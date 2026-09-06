/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font C:/Users/Giode/Downloads/assets/BebasNeue-Regular.ttf -o C:/Users/Giode/Downloads/assets\ui_font_Font20.c --format lvgl -r 0x20-0x7f --symbols áéíóúñ --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT20
#define UI_FONT_FONT20 1
#endif

#if UI_FONT_FONT20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf0, 0xf0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x36, 0x36, 0x36, 0x7f, 0x7f, 0x36, 0x26, 0x24,
    0xfe, 0xfe, 0x6c, 0x6c, 0x6c, 0x6c,

    /* U+0024 "$" */
    0x31, 0xef, 0xf3, 0xcf, 0xe, 0x1c, 0x38, 0x70,
    0xf3, 0xcf, 0xf7, 0x8c,

    /* U+0025 "%" */
    0x71, 0x9b, 0x23, 0x64, 0x6d, 0xd, 0xa1, 0xbc,
    0x37, 0x73, 0xbb, 0xf, 0x61, 0x6c, 0x2d, 0x89,
    0xb1, 0x36, 0x63, 0x80,

    /* U+0026 "&" */
    0x7c, 0xfc, 0xc0, 0xc0, 0xc6, 0xc6, 0x7f, 0x7f,
    0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0x76,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x7f, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xf7,

    /* U+0029 ")" */
    0xef, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xfe,

    /* U+002A "*" */
    0x18, 0x8, 0x4b, 0xff, 0x18, 0x34, 0x66,

    /* U+002B "+" */
    0x30, 0x60, 0xc7, 0xff, 0xe6, 0xc, 0x0,

    /* U+002C "," */
    0xf6, 0x80,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x6, 0x6, 0x6, 0xc, 0xc, 0x8, 0x18, 0x18,
    0x30, 0x30, 0x20, 0x60, 0x60, 0xc0,

    /* U+0030 "0" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0031 "1" */
    0x18, 0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c,

    /* U+0032 "2" */
    0x7b, 0xfc, 0xf3, 0xcc, 0x31, 0x8c, 0x71, 0x8c,
    0x30, 0xff, 0xf0,

    /* U+0033 "3" */
    0x7b, 0xfc, 0xf3, 0xc, 0x33, 0x8e, 0xc, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0034 "4" */
    0xc, 0x38, 0x71, 0xe3, 0xc7, 0x9b, 0x36, 0x4d,
    0x9b, 0xff, 0xf0, 0xc1, 0x80,

    /* U+0035 "5" */
    0xff, 0xfc, 0x30, 0xfb, 0xfc, 0xc3, 0xf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0036 "6" */
    0x7d, 0xff, 0x1e, 0x3c, 0x1b, 0xbf, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0037 "7" */
    0xff, 0xfc, 0x18, 0x70, 0xc1, 0x87, 0xc, 0x18,
    0x70, 0xc1, 0x87, 0xe, 0x0,

    /* U+0038 "8" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xdf, 0x3e, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0039 "9" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x76,
    0xf, 0x1e, 0x3f, 0xef, 0x80,

    /* U+003A ":" */
    0xf0, 0x0, 0xf0,

    /* U+003B ";" */
    0xf0, 0x0, 0xf6, 0x80,

    /* U+003C "<" */
    0xc, 0xfe, 0x38, 0x38, 0x30,

    /* U+003D "=" */
    0xff, 0xfc, 0x7, 0xff, 0xe0,

    /* U+003E ">" */
    0xc3, 0xc1, 0xc7, 0x73, 0x0,

    /* U+003F "?" */
    0x7b, 0xfc, 0xf3, 0xcc, 0x31, 0x8e, 0x30, 0xc0,
    0x0, 0x30, 0xc0,

    /* U+0040 "@" */
    0x7, 0xc0, 0xff, 0x8e, 0x1c, 0xe0, 0x76, 0xed,
    0xe7, 0xcf, 0x66, 0x7b, 0x33, 0xd9, 0x9e, 0xcd,
    0xb7, 0xfd, 0x9b, 0xc6, 0x0, 0x38, 0x20, 0xff,
    0x3, 0xf0,

    /* U+0041 "A" */
    0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x2c, 0x66, 0x66,
    0x66, 0x7e, 0x7e, 0x66, 0xe7, 0xc3,

    /* U+0042 "B" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xbe, 0xcf, 0x3c,
    0xf3, 0xff, 0xe0,

    /* U+0043 "C" */
    0x7b, 0xfc, 0xf3, 0xcf, 0xc, 0x30, 0xc3, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0044 "D" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xff, 0x80,

    /* U+0045 "E" */
    0xff, 0xfc, 0x30, 0xc3, 0xf, 0xbe, 0xc3, 0xc,
    0x30, 0xff, 0xf0,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xc3, 0xf, 0xbe, 0xc3, 0xc,
    0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0x33, 0xe7, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xff, 0xff, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xc0,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xfe,

    /* U+004B "K" */
    0xc7, 0x9b, 0x36, 0xcd, 0x9f, 0x3e, 0x7c, 0xf9,
    0xbb, 0x36, 0x6c, 0xf8, 0xc0,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xff, 0xf0,

    /* U+004D "M" */
    0xe3, 0xf1, 0xfc, 0xfe, 0xff, 0x7f, 0xbf, 0xdf,
    0xab, 0xd5, 0xea, 0xf7, 0x7b, 0xbd, 0xde, 0x4c,

    /* U+004E "N" */
    0xe7, 0xcf, 0x9f, 0xbf, 0x7e, 0xf7, 0xef, 0xdf,
    0x9f, 0x3e, 0x7c, 0xf8, 0xc0,

    /* U+004F "O" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0050 "P" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xfe, 0xc3, 0xc,
    0x30, 0xc3, 0x0,

    /* U+0051 "Q" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0xc0, 0x80,

    /* U+0052 "R" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xbf, 0xcf, 0x3c,
    0xf3, 0xcf, 0x30,

    /* U+0053 "S" */
    0x7b, 0xfc, 0xf3, 0xc3, 0x87, 0xe, 0x1c, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0054 "T" */
    0xff, 0xfc, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x60, 0xc1, 0x83, 0x6, 0x0,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0056 "V" */
    0xe7, 0xcd, 0x9b, 0x36, 0x6c, 0xdb, 0x36, 0x3c,
    0x78, 0xf1, 0xe3, 0xc7, 0x0,

    /* U+0057 "W" */
    0xce, 0x7d, 0xcd, 0xb9, 0xb7, 0x36, 0xe4, 0xdd,
    0x9a, 0xf3, 0x5e, 0x6b, 0xcd, 0x79, 0xef, 0x3d,
    0xe3, 0x9c, 0x73, 0x0,

    /* U+0058 "X" */
    0x63, 0x66, 0x66, 0x36, 0x3c, 0x3c, 0x1c, 0x1c,
    0x3c, 0x3c, 0x6e, 0x66, 0x66, 0xc7,

    /* U+0059 "Y" */
    0x66, 0x66, 0x66, 0x76, 0x3c, 0x3c, 0x3c, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0xf0, 0xc6, 0x18, 0xe3, 0xc, 0x61, 0x86,
    0x30, 0xff, 0xf0,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0xc0, 0x60, 0x60, 0x20, 0x30, 0x30, 0x18, 0x18,
    0x8, 0xc, 0xc, 0x6, 0x6, 0x6,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xff,

    /* U+005E "^" */
    0x18, 0x18, 0x3c, 0x2c, 0x66, 0x42,

    /* U+005F "_" */
    0xff, 0xf0,

    /* U+0060 "`" */
    0x63,

    /* U+0061 "a" */
    0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x2c, 0x66, 0x66,
    0x66, 0x7e, 0x7e, 0x66, 0xe7, 0xc3,

    /* U+0062 "b" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xbe, 0xcf, 0x3c,
    0xf3, 0xff, 0xe0,

    /* U+0063 "c" */
    0x7b, 0xfc, 0xf3, 0xcf, 0xc, 0x30, 0xc3, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0064 "d" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xff, 0x80,

    /* U+0065 "e" */
    0xff, 0xfc, 0x30, 0xc3, 0xf, 0xbe, 0xc3, 0xc,
    0x30, 0xff, 0xf0,

    /* U+0066 "f" */
    0xff, 0xfc, 0x30, 0xc3, 0xf, 0xbe, 0xc3, 0xc,
    0x30, 0xc3, 0x0,

    /* U+0067 "g" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0x33, 0xe7, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0068 "h" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xff, 0xff, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xc0,

    /* U+0069 "i" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xfe,

    /* U+006B "k" */
    0xc7, 0x9b, 0x36, 0xcd, 0x9f, 0x3e, 0x7c, 0xf9,
    0xbb, 0x36, 0x6c, 0xf8, 0xc0,

    /* U+006C "l" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xff, 0xf0,

    /* U+006D "m" */
    0xe3, 0xf1, 0xfc, 0xfe, 0xff, 0x7f, 0xbf, 0xdf,
    0xab, 0xd5, 0xea, 0xf7, 0x7b, 0xbd, 0xde, 0x4c,

    /* U+006E "n" */
    0xe7, 0xcf, 0x9f, 0xbf, 0x7e, 0xf7, 0xef, 0xdf,
    0x9f, 0x3e, 0x7c, 0xf8, 0xc0,

    /* U+006F "o" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0070 "p" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xfe, 0xc3, 0xc,
    0x30, 0xc3, 0x0,

    /* U+0071 "q" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0xc0, 0x80,

    /* U+0072 "r" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xbf, 0xcf, 0x3c,
    0xf3, 0xcf, 0x30,

    /* U+0073 "s" */
    0x7b, 0xfc, 0xf3, 0xc3, 0x87, 0xe, 0x1c, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+0074 "t" */
    0xff, 0xfc, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x60, 0xc1, 0x83, 0x6, 0x0,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3f, 0xef, 0x80,

    /* U+0076 "v" */
    0xe7, 0xcd, 0x9b, 0x36, 0x6c, 0xdb, 0x36, 0x3c,
    0x78, 0xf1, 0xe3, 0xc7, 0x0,

    /* U+0077 "w" */
    0xce, 0x7d, 0xcd, 0xb9, 0xb7, 0x36, 0xe4, 0xdd,
    0x9a, 0xf3, 0x5e, 0x6b, 0xcd, 0x79, 0xef, 0x3d,
    0xe3, 0x9c, 0x73, 0x0,

    /* U+0078 "x" */
    0x63, 0x66, 0x66, 0x36, 0x3c, 0x3c, 0x1c, 0x1c,
    0x3c, 0x3c, 0x6e, 0x66, 0x66, 0xc7,

    /* U+0079 "y" */
    0x66, 0x66, 0x66, 0x76, 0x3c, 0x3c, 0x3c, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+007A "z" */
    0xff, 0xf0, 0xc6, 0x18, 0xe3, 0xc, 0x61, 0x86,
    0x30, 0xff, 0xf0,

    /* U+007B "{" */
    0x1c, 0xf3, 0xc, 0x30, 0xc3, 0x3c, 0xf0, 0xc3,
    0xc, 0x30, 0xc3, 0xc7,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xe7, 0x8c, 0x63, 0x18, 0xc7, 0x39, 0x8c, 0x63,
    0x1b, 0xdc,

    /* U+007E "~" */
    0x72, 0x7e, 0x4e,

    /* U+00E1 "á" */
    0xc, 0x18, 0x0, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
    0x2c, 0x66, 0x66, 0x66, 0x7e, 0x7e, 0x66, 0xe7,
    0xc3,

    /* U+00E9 "é" */
    0x18, 0xc0, 0x3f, 0xff, 0xc, 0x30, 0xc3, 0xef,
    0xb0, 0xc3, 0xc, 0x3f, 0xfc,

    /* U+00ED "í" */
    0x6c, 0xc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0xc0,

    /* U+00F1 "ñ" */
    0x7c, 0xf8, 0x7, 0x3e, 0x7c, 0xfd, 0xfb, 0xf7,
    0xbf, 0x7e, 0xfc, 0xf9, 0xf3, 0xe7, 0xc6,

    /* U+00F3 "ó" */
    0x1c, 0x70, 0x3, 0xef, 0xf8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7c,

    /* U+00FA "ú" */
    0x1c, 0x70, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7c
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 51, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 67, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 108, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 8, .adv_w = 132, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 34, .adv_w = 188, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 133, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 60, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 69, .adv_w = 88, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 77, .adv_w = 88, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 85, .adv_w = 135, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 92, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 99, .adv_w = 60, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 101, .adv_w = 86, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 102, .adv_w = 60, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 124, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 60, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 60, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 244, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 249, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 254, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 259, .adv_w = 116, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 223, .box_w = 13, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 296, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 129, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 123, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 130, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 116, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 110, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 125, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 61, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 85, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 132, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 110, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 172, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 137, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 124, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 128, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 495, .adv_w = 129, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 119, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 116, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 129, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 122, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 178, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 130, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 126, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 116, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 88, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 623, .adv_w = 124, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 637, .adv_w = 88, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 645, .adv_w = 128, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 651, .adv_w = 96, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 653, .adv_w = 160, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 15},
    {.bitmap_index = 654, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 129, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 123, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 690, .adv_w = 130, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 116, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 110, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 125, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 61, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 755, .adv_w = 85, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 132, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 110, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 172, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 137, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 828, .adv_w = 124, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 839, .adv_w = 128, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 853, .adv_w = 129, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 119, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 875, .adv_w = 116, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 129, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 901, .adv_w = 122, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 914, .adv_w = 178, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 130, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 948, .adv_w = 126, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 962, .adv_w = 116, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 973, .adv_w = 88, .box_w = 6, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 985, .adv_w = 160, .box_w = 2, .box_h = 19, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 990, .adv_w = 88, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1000, .adv_w = 128, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 1003, .adv_w = 128, .box_w = 8, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1020, .adv_w = 116, .box_w = 6, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1033, .adv_w = 61, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1042, .adv_w = 137, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1057, .adv_w = 128, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1072, .adv_w = 129, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x8, 0xc, 0x10, 0x12, 0x19
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 225, .range_length = 26, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 6, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 2, 0, 0, 0, 0, 3, 0,
    4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 5, 6, 7, 8, 9, 10, 11,
    12, 0, 0, 13, 14, 15, 0, 0,
    9, 16, 9, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 2, 0, 0, 0,
    0, 0, 6, 7, 8, 9, 10, 11,
    12, 0, 0, 0, 14, 15, 0, 0,
    9, 16, 9, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 2, 0, 0, 0,
    6, 10, 0, 0, 9, 20
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 2,
    1, 0, 3, 4, 0, 5, 6, 5,
    7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 8, 8, 0, 0, 0,
    9, 10, 11, 0, 12, 0, 0, 0,
    12, 0, 0, 13, 0, 0, 0, 0,
    12, 0, 12, 0, 14, 15, 16, 17,
    18, 19, 20, 21, 0, 0, 3, 0,
    0, 0, 11, 0, 12, 0, 0, 0,
    12, 0, 0, 0, 0, 0, 0, 0,
    12, 0, 12, 0, 14, 15, 16, 17,
    18, 19, 20, 21, 0, 0, 3, 0,
    11, 0, 0, 0, 12, 16
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    0, 3, 0, 5, 0, 3, 3, 2,
    3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, 0, -20, 0,
    -23, 0, -6, -3, -11, -16, -5, 0,
    0, 0, 0, 0, 0, -45, 0, 0,
    0, -8, 0, -14, 0, 3, 0, 3,
    3, 0, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    -3, 0, 0, 0, 0, 0, -6, -5,
    0, -17, 0, 3, -14, 3, -6, 3,
    3, -10, -2, 2, -1, 0, -1, -15,
    -1, -9, -4, 1, -15, 1, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -2, -5, 0, 0, 0, 0, 2, 0,
    0, 0, 0, 2, 2, 0, 1, 0,
    1, 0, 0, 0, 0, -2, -3, 0,
    -2, 0, 0, 0, -2, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0,
    -1, 0, -5, -6, 0, 0, 0, 3,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 1,
    0, 1, 3, 0, 5, 3, -23, -2,
    -10, 0, 2, -2, -10, 0, -16, 0,
    3, 0, 2, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, -5, 0, 0, 0, 0, 0,
    -1, 0, -3, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 2, -6, 2, -11, 0,
    2, -3, -3, 0, -5, 0, -2, 0,
    0, 0, 0, 0, 0, 0, -23, 3,
    5, -32, 3, -23, 3, 3, -14, 0,
    1, -1, 3, 0, -25, 0, -15, -5,
    0, -28, 0, 0, 0, 0, 3, -30,
    0, -21, 0, 3, 0, -11, 0, -18,
    1, 1, 0, 0, 0, -4, -2, -1,
    -2, 0, 0, 0, 2, 0, 3, 2,
    0, 0, 0, 0, 0, 0, -1, 0,
    -1, -1, 0, -5, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, -2,
    -2, 0, 3, 0, 5, 3, -23, -23,
    -14, -11, 2, -8, -15, -1, -16, 0,
    3, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 0, -1, 0, -3, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, -2, 3, 0,
    -17, -6, -8, -5, 0, -3, -9, -1,
    -15, 0, 1, 0, 2, 2, 0, 0,
    0, 3, 0, 3, 0, -8, -3, 0,
    -2, 0, -2, -4, 0, -7, 0, 1,
    0, 2, 2, 0, 0, 0, 0, -2,
    2, -6, 2, -11, 3, 2, -3, -3,
    1, -5, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 3, -6, 3, -3, -30,
    -16, -18, -13, -3, -13, -15, -6, -19,
    -5, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, -5, 0, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 25,
    .right_class_cnt     = 21,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font20 = {
#else
lv_font_t ui_font_Font20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT20*/

