// ===========================================================
// tts_audio.cpp — PIAM Pro
// WiFi + ElevenLabs + cache (SPIFFS) + reproduccion por el codec
// que ya inicializa esp_es8311_port_init() (ver ese archivo).
//
// Adaptado de la logica de PIAM Lite (Arduino) a ESP-IDF puro:
//  - WiFi.h / HTTPClient.h        -> esp_wifi.h / esp_http_client.h
//  - FFat (Arduino)               -> SPIFFS nativo de ESP-IDF
//  - i2s.write() + duplicar mono a stereo -> esp_codec_dev_write()
//    directo (el codec de Pro ya esta configurado en MONO, asi que
//    no hace falta el truco de duplicar canales que usa Lite)
// ===========================================================

#include "tts_audio.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_log.h"
#include "esp_http_client.h"
#include "esp_crt_bundle.h"
#include "esp_spiffs.h"
#include "esp_codec_dev.h"
#include "cJSON.h"
#include "nvs_flash.h"
#include "nvs.h"

static const char *TAG = "tts_audio";

// ---------- Config ----------
// TEMPORAL: hardcodeado hasta que la pantalla de Ajustes (WiFi)
// este lista. Cuando exista, reemplazar por lectura desde NVS.
#define WIFI_SSID       "Flia Odesser-Samaniego"
#define WIFI_PASS       "31161207"
#define WIFI_CONNECT_TIMEOUT_MS 10000

#define ELEVENLABS_API_KEY   "sk_35abc7fc9fb4352b146245d1f79540668485edbc5354553b"
#define ELEVENLABS_VOICE_ID  "X5HUVd7s8mDPR5uItKes"
#define ELEVENLABS_MODEL_ID  "eleven_turbo_v2_5"

// El codec ya lo crea/abre esp_es8311_port_init() (ver
// esp_es8311_port.cpp) -- esas variables son globales (no static)
// ahi, asi que las reusamos directo aca en vez de reinicializar
// el I2S/codec por segunda vez (lo cual crashearia).
extern esp_codec_dev_handle_t output_dev;
extern esp_codec_dev_handle_t input_dev;

// ---------- WiFi ----------
static EventGroupHandle_t s_wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0

// PIAM Pro: mientras esto es true, un intento de conexion MANUAL
// (desde wifi_connect_and_save) esta en curso -- el reconectado
// automatico de abajo se queda quieto para no pelear por el control
// de la radio WiFi al mismo tiempo (eso causaba "sta is connecting,
// cannot set config" y un loop de desconexion/reconexion sin fin).
static volatile bool s_manual_connect_in_progress = false;

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                                int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (!s_manual_connect_in_progress) {
            ESP_LOGW(TAG, "WiFi desconectado, reintentando...");
            esp_wifi_connect();
        }
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
        ESP_LOGI(TAG, "WiFi conectado, IP: " IPSTR, IP2STR(&event->ip_info.ip));
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

static void wifi_init(void)
{
    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID,
                                                          &wifi_event_handler, NULL, &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP,
                                                          &wifi_event_handler, NULL, &instance_got_ip));

    // PIAM Pro: si el usuario ya configuro una red desde Ajustes, usamos
    // esa (guardada en NVS). Si no hay nada guardado, usamos la de
    // fabrica/desarrollo como default.
    char saved_ssid[33] = {0};
    char saved_pass[65] = {0};
    bool has_saved = false;

    nvs_handle_t nvs;
    if (nvs_open("piam_wifi", NVS_READONLY, &nvs) == ESP_OK) {
        size_t ssid_len = sizeof(saved_ssid);
        size_t pass_len = sizeof(saved_pass);
        if (nvs_get_str(nvs, "ssid", saved_ssid, &ssid_len) == ESP_OK &&
            nvs_get_str(nvs, "pass", saved_pass, &pass_len) == ESP_OK &&
            saved_ssid[0] != '\0') {
            has_saved = true;
        }
        nvs_close(nvs);
    }

    wifi_config_t wifi_config = {};
    if (has_saved) {
        ESP_LOGI(TAG, "Usando WiFi guardada en Ajustes: '%s'", saved_ssid);
        strncpy((char *)wifi_config.sta.ssid, saved_ssid, sizeof(wifi_config.sta.ssid));
        strncpy((char *)wifi_config.sta.password, saved_pass, sizeof(wifi_config.sta.password));
    } else {
        strncpy((char *)wifi_config.sta.ssid, WIFI_SSID, sizeof(wifi_config.sta.ssid));
        strncpy((char *)wifi_config.sta.password, WIFI_PASS, sizeof(wifi_config.sta.password));
    }
    wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "Conectando a WiFi '%s'...", (const char *)wifi_config.sta.ssid);
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group, WIFI_CONNECTED_BIT,
                                            pdFALSE, pdFALSE, pdMS_TO_TICKS(WIFI_CONNECT_TIMEOUT_MS));

    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "WiFi conectado.");
    } else {
        ESP_LOGW(TAG, "WiFi no disponible todavia -- solo funcionara el cache por ahora.");
    }
}

static bool wifi_is_connected(void)
{
    return (xEventGroupGetBits(s_wifi_event_group) & WIFI_CONNECTED_BIT) != 0;
}

// ---------- SPIFFS (cache de audio) ----------
static bool cache_ready = false;

static void cache_init(void)
{
    esp_vfs_spiffs_conf_t conf = {};
    conf.base_path = "/tts";
    conf.partition_label = "tts";
    conf.max_files = 20;
    conf.format_if_mount_failed = true;

    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "No se pudo montar el cache TTS (0x%x). Revisar partitions.csv (particion 'tts').", ret);
        return;
    }

    size_t total = 0, used = 0;
    esp_spiffs_info("tts", &total, &used);
    ESP_LOGI(TAG, "Cache TTS listo -- %d/%d bytes usados", (int)used, (int)total);

    cache_ready = true;
}

// FNV-1a, igual que en PIAM Lite -- nombre de archivo corto y valido
static void cache_path_for(const char *text, char *out, size_t out_size)
{
    uint32_t hash = 2166136261u;
    for (const char *p = text; *p; p++) {
        hash ^= (uint8_t)(*p);
        hash *= 16777619u;
    }
    snprintf(out, out_size, "/tts/%08lx.pcm", (unsigned long)hash);
}

static bool play_from_cache_if_exists(const char *text)
{
    if (!cache_ready) return false;

    char path[40];
    cache_path_for(text, path, sizeof(path));

    FILE *f = fopen(path, "rb");
    if (!f) return false;

    ESP_LOGI(TAG, "Reproduciendo desde cache: %s", path);

    const size_t CHUNK = 1024;
    uint8_t chunk[CHUNK];
    size_t n;
    while ((n = fread(chunk, 1, CHUNK, f)) > 0) {
        esp_codec_dev_write(output_dev, chunk, n);
    }

    fclose(f);
    return true;
}

// ---------- ElevenLabs ----------
static char s_json_escape_buf[512];

static const char *json_escape(const char *text)
{
    size_t j = 0;
    for (const char *p = text; *p && j < sizeof(s_json_escape_buf) - 2; p++) {
        if (*p == '"' || *p == '\\') {
            s_json_escape_buf[j++] = '\\';
        }
        s_json_escape_buf[j++] = *p;
    }
    s_json_escape_buf[j] = '\0';
    return s_json_escape_buf;
}

// Cada bloque de datos que llega por HTTP se escribe directo al
// archivo de cache (no se guarda todo en RAM antes de reproducir --
// primero se descarga completo, y RECIEN DESPUES se reproduce desde
// la flash, igual que hace Lite, para evitar cortes por WiFi lento).
static FILE *s_download_file = NULL;
static size_t s_download_bytes = 0;

static esp_err_t http_event_handler(esp_http_client_event_t *evt)
{
    if (evt->event_id == HTTP_EVENT_ON_DATA) {
        if (s_download_file && evt->data_len > 0) {
            fwrite(evt->data, 1, evt->data_len, s_download_file);
            s_download_bytes += evt->data_len;
        }
    }
    return ESP_OK;
}

bool tts_speak(const char *text_utf8)
{
    if (text_utf8 == NULL || text_utf8[0] == '\0') return false;

    // 1) Ya la tenemos en cache? Ni siquiera hace falta WiFi.
    if (play_from_cache_if_exists(text_utf8)) {
        return true;
    }

    // 2) No esta en cache -- hace falta WiFi
    if (!wifi_is_connected()) {
        ESP_LOGW(TAG, "Sin WiFi y la frase no esta en cache: %s", text_utf8);
        return false;
    }

    if (!cache_ready) {
        ESP_LOGE(TAG, "Cache no disponible, no se puede descargar la frase");
        return false;
    }

    ESP_LOGI(TAG, "Sintetizando (nueva): %s", text_utf8);

    char path[40];
    cache_path_for(text_utf8, path, sizeof(path));

    s_download_file = fopen(path, "wb");
    if (!s_download_file) {
        ESP_LOGE(TAG, "No se pudo crear el archivo de cache");
        return false;
    }
    s_download_bytes = 0;

    char url[160];
    snprintf(url, sizeof(url),
             "https://api.elevenlabs.io/v1/text-to-speech/%s?output_format=pcm_16000",
             ELEVENLABS_VOICE_ID);

    esp_http_client_config_t config = {};
    config.url = url;
    config.event_handler = http_event_handler;
    config.timeout_ms = 15000;
    config.crt_bundle_attach = esp_crt_bundle_attach; // certificados TLS del sistema

    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_header(client, "xi-api-key", ELEVENLABS_API_KEY);
    esp_http_client_set_header(client, "Accept", "audio/pcm");

    char body[600];
    snprintf(body, sizeof(body),
             "{\"text\":\"%s\",\"model_id\":\"%s\",\"language_code\":\"es\"}",
             json_escape(text_utf8), ELEVENLABS_MODEL_ID);

    esp_http_client_set_post_field(client, body, strlen(body));

    esp_err_t err = esp_http_client_perform(client);

    fclose(s_download_file);
    s_download_file = NULL;

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error HTTP: %s", esp_err_to_name(err));
        esp_http_client_cleanup(client);
        remove(path);
        return false;
    }

    int status = esp_http_client_get_status_code(client);
    esp_http_client_cleanup(client);

    if (status != 200 || s_download_bytes == 0) {
        ESP_LOGE(TAG, "ElevenLabs devolvio status %d (%d bytes)", status, (int)s_download_bytes);
        remove(path);
        return false;
    }

    ESP_LOGI(TAG, "Descarga completa (%d bytes) -- reproduciendo desde cache...", (int)s_download_bytes);

    return play_from_cache_if_exists(text_utf8);
}

// =====================================================================
// STT (Speech to Text) -- ElevenLabs Scribe
// =====================================================================

// Duracion maxima de grabacion: 15 segundos a 16kHz mono 16-bit.
#define STT_MAX_SECONDS   15
#define STT_SAMPLE_RATE   16000
#define STT_MAX_SAMPLES   (STT_SAMPLE_RATE * STT_MAX_SECONDS)
#define STT_MAX_BYTES     (STT_MAX_SAMPLES * 2)  // 16-bit = 2 bytes/muestra
#define STT_CHUNK_SAMPLES 320                     // 20ms por lectura

static uint8_t *s_stt_buffer = NULL;      // buffer en PSRAM con el audio grabado
static size_t s_stt_recorded_bytes = 0;
static volatile bool s_stt_recording = false;
static TaskHandle_t s_stt_task_handle = NULL;
static char s_stt_transcript[512] = {0};

// Tarea en background que lee del microfono en chunks chicos mientras
// s_stt_recording sea true (o hasta llenar el buffer maximo).
static void stt_record_task(void *arg)
{
    const size_t chunk_bytes = STT_CHUNK_SAMPLES * 2;
    s_stt_recorded_bytes = 0;

    while (s_stt_recording && (s_stt_recorded_bytes + chunk_bytes) < STT_MAX_BYTES) {
        int err = esp_codec_dev_read(input_dev, s_stt_buffer + s_stt_recorded_bytes, chunk_bytes);
        if (err == ESP_CODEC_DEV_OK) {
            s_stt_recorded_bytes += chunk_bytes;
        } else {
            ESP_LOGW(TAG, "stt: error leyendo microfono (%d)", err);
            break;
        }
    }

    s_stt_task_handle = NULL;
    vTaskDelete(NULL);
}

void stt_start_recording(void)
{
    if (s_stt_buffer == NULL) {
        s_stt_buffer = (uint8_t *)heap_caps_malloc(STT_MAX_BYTES, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
        if (s_stt_buffer == NULL) {
            ESP_LOGE(TAG, "stt: no se pudo reservar buffer de grabacion (%d bytes)", STT_MAX_BYTES);
            return;
        }
    }

    if (s_stt_recording) return; // ya estaba grabando

    ESP_LOGI(TAG, "stt: empezando a grabar...");
    s_stt_recording = true;
    xTaskCreate(stt_record_task, "stt_record", 4096, NULL, 5, &s_stt_task_handle);
}

// Arma un header WAV de 44 bytes para el audio PCM crudo que grabamos
// (mono, 16-bit, 16kHz) -- ElevenLabs necesita un archivo de audio
// real, no PCM sin envoltorio.
static void write_wav_header(FILE *f, uint32_t data_bytes)
{
    uint32_t sample_rate = STT_SAMPLE_RATE;
    uint16_t channels = 1;
    uint16_t bits_per_sample = 16;
    uint32_t byte_rate = sample_rate * channels * bits_per_sample / 8;
    uint16_t block_align = channels * bits_per_sample / 8;
    uint32_t riff_size = 36 + data_bytes;

    fwrite("RIFF", 1, 4, f);
    fwrite(&riff_size, 4, 1, f);
    fwrite("WAVE", 1, 4, f);
    fwrite("fmt ", 1, 4, f);
    uint32_t fmt_size = 16;
    fwrite(&fmt_size, 4, 1, f);
    uint16_t audio_format = 1; // PCM
    fwrite(&audio_format, 2, 1, f);
    fwrite(&channels, 2, 1, f);
    fwrite(&sample_rate, 4, 1, f);
    fwrite(&byte_rate, 4, 1, f);
    fwrite(&block_align, 2, 1, f);
    fwrite(&bits_per_sample, 2, 1, f);
    fwrite("data", 1, 4, f);
    fwrite(&data_bytes, 4, 1, f);
}

// Callback de HTTP para leer la RESPUESTA de ElevenLabs (el JSON con
// el texto transcripto), acumulandola en un buffer chico en RAM
// (la respuesta es solo texto, no audio, asi que es liviana).
static char s_stt_response_buf[8192];
static size_t s_stt_response_len = 0;

static esp_err_t stt_http_event_handler(esp_http_client_event_t *evt)
{
    if (evt->event_id == HTTP_EVENT_ON_DATA) {
        size_t remaining = sizeof(s_stt_response_buf) - s_stt_response_len - 1;
        size_t to_copy = (size_t)evt->data_len < remaining ? (size_t)evt->data_len : remaining;
        if (to_copy > 0) {
            memcpy(s_stt_response_buf + s_stt_response_len, evt->data, to_copy);
            s_stt_response_len += to_copy;
            s_stt_response_buf[s_stt_response_len] = '\0';
        }
    }
    return ESP_OK;
}

bool stt_stop_and_transcribe(void)
{
    if (!s_stt_recording) {
        ESP_LOGW(TAG, "stt: no se estaba grabando");
        return false;
    }

    ESP_LOGI(TAG, "stt: deteniendo grabacion...");
    s_stt_recording = false;

    // Esperar a que la tarea de grabacion termine de verdad
    while (s_stt_task_handle != NULL) {
        vTaskDelay(pdMS_TO_TICKS(10));
    }

    ESP_LOGI(TAG, "stt: grabados %d bytes (~%.1f seg)", (int)s_stt_recorded_bytes,
             s_stt_recorded_bytes / (float)(STT_SAMPLE_RATE * 2));

    if (s_stt_recorded_bytes == 0) {
        ESP_LOGW(TAG, "stt: no se grabo nada");
        return false;
    }

    if (!wifi_is_connected()) {
        ESP_LOGW(TAG, "stt: sin WiFi, no se puede transcribir");
        return false;
    }

    // 1) Armar el cuerpo multipart COMPLETO en un solo bloque de PSRAM.
    // Mas simple y confiable que mandarlo en streaming con lectura
    // manual de la respuesta (eso fallaba, se cortaba a mitad de
    // camino). El audio ya esta en PSRAM de por si, asi que esto no
    // gasta mucha memoria extra.
    const char *boundary = "----PIAMProSTTBoundary";
    char part1[384];
    int part1_len = snprintf(part1, sizeof(part1),
             "--%s\r\n"
             "Content-Disposition: form-data; name=\"model_id\"\r\n\r\n"
             "scribe_v2\r\n"
             "--%s\r\n"
             "Content-Disposition: form-data; name=\"language_code\"\r\n\r\n"
             "spa\r\n"
             "--%s\r\n"
             "Content-Disposition: form-data; name=\"file\"; filename=\"rec.wav\"\r\n"
             "Content-Type: audio/wav\r\n\r\n",
             boundary, boundary, boundary);

    char part2[64];
    int part2_len = snprintf(part2, sizeof(part2), "\r\n--%s--\r\n", boundary);

    size_t wav_size = 44 + s_stt_recorded_bytes;
    size_t body_len = (size_t)part1_len + wav_size + (size_t)part2_len;

    uint8_t *body = (uint8_t *)heap_caps_malloc(body_len, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (!body) {
        ESP_LOGE(TAG, "stt: no se pudo reservar memoria para el pedido (%d bytes)", (int)body_len);
        return false;
    }

    size_t offset = 0;
    memcpy(body + offset, part1, part1_len);
    offset += part1_len;

    // Header WAV armado directo en el buffer (sin pasar por archivo)
    {
        uint32_t sr = STT_SAMPLE_RATE;
        uint16_t channels = 1;
        uint16_t bits_per_sample = 16;
        uint32_t byte_rate = sr * channels * bits_per_sample / 8;
        uint16_t block_align = channels * bits_per_sample / 8;
        uint32_t data_bytes = (uint32_t)s_stt_recorded_bytes;
        uint32_t riff_size = 36 + data_bytes;
        uint32_t fmt_size = 16;
        uint16_t audio_format = 1;

        memcpy(body + offset, "RIFF", 4); offset += 4;
        memcpy(body + offset, &riff_size, 4); offset += 4;
        memcpy(body + offset, "WAVE", 4); offset += 4;
        memcpy(body + offset, "fmt ", 4); offset += 4;
        memcpy(body + offset, &fmt_size, 4); offset += 4;
        memcpy(body + offset, &audio_format, 2); offset += 2;
        memcpy(body + offset, &channels, 2); offset += 2;
        memcpy(body + offset, &sr, 4); offset += 4;
        memcpy(body + offset, &byte_rate, 4); offset += 4;
        memcpy(body + offset, &block_align, 2); offset += 2;
        memcpy(body + offset, &bits_per_sample, 2); offset += 2;
        memcpy(body + offset, "data", 4); offset += 4;
        memcpy(body + offset, &data_bytes, 4); offset += 4;
    }

    memcpy(body + offset, s_stt_buffer, s_stt_recorded_bytes);
    offset += s_stt_recorded_bytes;

    memcpy(body + offset, part2, part2_len);
    offset += part2_len;

    // 2) Mandar todo de una con esp_http_client_perform() -- mismo
    // patron simple y probado que ya usamos para el TTS.
    s_stt_response_len = 0;
    s_stt_response_buf[0] = '\0';

    esp_http_client_config_t config = {};
    config.url = "https://api.elevenlabs.io/v1/speech-to-text";
    config.event_handler = stt_http_event_handler;
    config.timeout_ms = 45000;
    config.crt_bundle_attach = esp_crt_bundle_attach;

    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_header(client, "xi-api-key", ELEVENLABS_API_KEY);

    char content_type[80];
    snprintf(content_type, sizeof(content_type), "multipart/form-data; boundary=%s", boundary);
    esp_http_client_set_header(client, "Content-Type", content_type);

    esp_http_client_set_post_field(client, (const char *)body, (int)offset);

    esp_err_t err = esp_http_client_perform(client);

    heap_caps_free(body);

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "stt: error HTTP: %s", esp_err_to_name(err));
        esp_http_client_cleanup(client);
        return false;
    }

    int status = esp_http_client_get_status_code(client);
    esp_http_client_cleanup(client);

    ESP_LOGI(TAG, "stt: status HTTP: %d", status);
    ESP_LOGI(TAG, "stt: respuesta cruda: %s", s_stt_response_buf);

    if (status != 200) {
        ESP_LOGE(TAG, "stt: ElevenLabs devolvio status %d: %s", status, s_stt_response_buf);
        return false;
    }

    // 3) Parsear el JSON de respuesta y sacar el campo "text"
    cJSON *root = cJSON_Parse(s_stt_response_buf);
    if (!root) {
        ESP_LOGE(TAG, "stt: no se pudo parsear la respuesta JSON. Cruda: %s", s_stt_response_buf);
        return false;
    }

    cJSON *text_item = cJSON_GetObjectItem(root, "text");
    if (!cJSON_IsString(text_item)) {
        ESP_LOGE(TAG, "stt: la respuesta no tiene campo 'text'");
        cJSON_Delete(root);
        return false;
    }

    strncpy(s_stt_transcript, text_item->valuestring, sizeof(s_stt_transcript) - 1);
    s_stt_transcript[sizeof(s_stt_transcript) - 1] = '\0';
    cJSON_Delete(root);

    ESP_LOGI(TAG, "stt: transcripcion: \"%s\"", s_stt_transcript);
    return true;
}

const char *stt_get_last_transcript(void)
{
    return s_stt_transcript;
}

// =====================================================================
// WiFi: escaneo, conexion y guardado persistente
// =====================================================================

int wifi_scan_networks(wifi_scan_result_t *out, int max_results)
{
    wifi_scan_config_t scan_config = {};
    scan_config.show_hidden = false;

    ESP_LOGI(TAG, "Escaneando redes WiFi cercanas...");
    esp_err_t err = esp_wifi_scan_start(&scan_config, true); // bloqueante
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error al escanear: %s", esp_err_to_name(err));
        return 0;
    }

    uint16_t ap_count = 0;
    esp_wifi_scan_get_ap_num(&ap_count);
    if (ap_count == 0) return 0;

    wifi_ap_record_t *ap_records = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t) * ap_count);
    if (!ap_records) return 0;

    esp_wifi_scan_get_ap_records(&ap_count, ap_records);

    // Copiamos a 'out', evitando duplicados (la misma red puede
    // aparecer varias veces si hay varios puntos de acceso), y
    // quedandonos con hasta max_results, ordenados por señal (mejor
    // primero, ya que esp_wifi ya los devuelve asi por default).
    int count = 0;
    for (int i = 0; i < ap_count && count < max_results; i++) {
        const char *ssid = (const char *)ap_records[i].ssid;
        if (ssid[0] == '\0') continue; // red oculta, la saltamos

        bool duplicate = false;
        for (int j = 0; j < count; j++) {
            if (strcmp(out[j].ssid, ssid) == 0) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) continue;

        strncpy(out[count].ssid, ssid, sizeof(out[count].ssid) - 1);
        out[count].ssid[sizeof(out[count].ssid) - 1] = '\0';
        out[count].rssi = ap_records[i].rssi;
        count++;
    }

    free(ap_records);
    ESP_LOGI(TAG, "Encontradas %d redes", count);
    return count;
}

bool wifi_connect_and_save(const char *ssid, const char *password)
{
    ESP_LOGI(TAG, "Conectando a '%s'...", ssid);

    s_manual_connect_in_progress = true; // el auto-reconectado se queda quieto

    xEventGroupClearBits(s_wifi_event_group, WIFI_CONNECTED_BIT);

    esp_wifi_disconnect();
    vTaskDelay(pdMS_TO_TICKS(200)); // le damos tiempo real a desconectar antes de reconfigurar

    wifi_config_t wifi_config = {};
    strncpy((char *)wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    strncpy((char *)wifi_config.sta.password, password, sizeof(wifi_config.sta.password));
    wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;

    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_connect();

    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group, WIFI_CONNECTED_BIT,
                                            pdFALSE, pdFALSE, pdMS_TO_TICKS(WIFI_CONNECT_TIMEOUT_MS));

    bool ok = (bits & WIFI_CONNECTED_BIT) != 0;

    s_manual_connect_in_progress = false; // listo, el auto-reconectado puede retomar

    if (ok) {
        ESP_LOGI(TAG, "Conectado. Guardando en NVS para el proximo arranque...");
        nvs_handle_t nvs;
        if (nvs_open("piam_wifi", NVS_READWRITE, &nvs) == ESP_OK) {
            nvs_set_str(nvs, "ssid", ssid);
            nvs_set_str(nvs, "pass", password);
            nvs_commit(nvs);
            nvs_close(nvs);
        }
    } else {
        ESP_LOGW(TAG, "No se pudo conectar a '%s' (contraseña incorrecta o fuera de rango)", ssid);
    }

    return ok;
}

// =====================================================================

void tts_audio_init(void)
{
    wifi_init();
    cache_init();
}
