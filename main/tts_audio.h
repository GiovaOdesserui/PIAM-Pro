#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Conecta WiFi y monta el cache de audio (SPIFFS). Llamar una sola
// vez desde app_main(), DESPUES de esp_es8311_port_init() (necesita
// que el codec ya este creado).
void tts_audio_init(void);

// Reproduce una frase. Si ya esta en cache, la reproduce directo sin
// necesitar WiFi. Si no esta, la pide a ElevenLabs, la guarda en
// cache, y recien ahi la reproduce. Devuelve false si fallo (por
// ejemplo, sin WiFi y sin cache).
bool tts_speak(const char *text_utf8);

// --------------------------------------------------------------
// STT (Speech to Text) -- para que la persona con discapacidad
// auditiva pueda LEER lo que le dicen. Usa ElevenLabs Scribe.
// --------------------------------------------------------------

// Empieza a grabar del microfono (bloquea en un thread interno, no
// en el que llama). Llamar cuando el usuario activa RecordButton
// (checked). No hace falta WiFi para esto -- solo para transcribir
// despues.
void stt_start_recording(void);

// Corta la grabacion y la manda a transcribir (esto SI bloquea,
// tarda lo que tarda la subida + respuesta de ElevenLabs). Llamar
// cuando el usuario desactiva RecordButton (unchecked).
// Devuelve true si se pudo transcribir bien.
bool stt_stop_and_transcribe(void);

// Devuelve el ultimo texto transcripto (valido despues de un
// stt_stop_and_transcribe() exitoso). NO liberar el puntero.
const char *stt_get_last_transcript(void);

// --------------------------------------------------------------
// WiFi: escaneo, conexion y guardado persistente (NVS)
// --------------------------------------------------------------

#define WIFI_SCAN_MAX_NETWORKS 12

typedef struct {
    char ssid[33];
    int8_t rssi; // señal, mas alto (menos negativo) = mejor
} wifi_scan_result_t;

// Escanea redes cercanas (bloquea unos segundos). Llena 'out' con
// hasta WIFI_SCAN_MAX_NETWORKS resultados, ordenados de mejor a
// peor señal, sin duplicados. Devuelve la cantidad real encontrada.
int wifi_scan_networks(wifi_scan_result_t *out, int max_results);

// Se conecta a una red nueva (desconecta la actual si hay una), y si
// funciona, la guarda en NVS para que se use sola en el proximo
// arranque. Devuelve true si logro conectar dentro del timeout.
bool wifi_connect_and_save(const char *ssid, const char *password);

#ifdef __cplusplus
}
#endif
