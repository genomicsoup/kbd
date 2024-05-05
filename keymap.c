/*
 * file: keymap.c
 * desc: Defines the keymap and OLED code for my sofle choc.
 */

#include QMK_KEYBOARD_H

enum LAYERS {
    LAYER_QWERTY = 0,
    LAYER_DVORAK,
    LAYER_ALT,
    LAYER_SHIFT,
};

enum OLED_LAYERS { OLED_LAYER_EMPTY, OLED_LAYER_BOTTOM, OLED_LAYER_MIDDLE, OLED_LAYER_TOP };

// just some renaming so the identifiers fit into the keymap ascii below
// temporarily activates LAYER_SHIFT while keeping the LSHIFT key pressed
#define LAY_SHFT LM(LAYER_SHIFT, MOD_LSFT)
// temporarily activates LAYER_ALT
#define LAY_ALT MO(LAYER_ALT)
// switches the default layer to LAYER_DVORAK
#define DF_DVRK DF(LAYER_DVORAK)
// switches the default layer to LAYER_QWERTY
#define DF_QWRT DF(LAYER_QWERTY)

// clang-format off
// the keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_QWERTY] = LAYOUT(
//,-----------------------------------------------------.                     ,-----------------------------------------------------.
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,    KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_DOWN,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
                      KC_LCTL, KC_LWIN,LAY_SHFT,  KC_SPC, KC_LALT,    LAY_ALT,  KC_ENT, KC_LEFT,   KC_UP,KC_RIGHT
//                  \--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------/
),

[LAYER_DVORAK] = LAYOUT(
//,-----------------------------------------------------.                     ,-----------------------------------------------------.
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     KC_ESC,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,KC_MINUS,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X, KC_MPLY,    KC_MUTE,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_DOWN,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
                      KC_LCTL, KC_LWIN,LAY_SHFT,  KC_SPC, KC_LALT,    LAY_ALT,  KC_ENT, KC_LEFT,   KC_UP,KC_RIGHT
//                  \--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------/
),

[LAYER_ALT] = LAYOUT(
//,-----------------------------------------------------.                     ,-----------------------------------------------------.
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9, DF_DVRK, DF_QWRT,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                       _______, KC_LBRC, KC_RBRC, KC_SLSH,  KC_EQL, KC_BSLS,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
    KC_LSFT, _______, _______, _______, _______, _______, KC_MPLY,    KC_MUTE, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
                      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
//                  \--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------/
),

[LAYER_SHIFT] = LAYOUT(
//,-----------------------------------------------------.                     ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, DF_DVRK, DF_QWRT,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
    KC_LSFT, _______, _______, _______, _______, _______, KC_MPLY,    KC_MUTE, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------|========|  |========|--------+--------+--------+--------+--------+--------|
                      _______, _______, _______, _______, _______,    _______,  KC_SPC, _______, _______, _______
//                  \--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------/
),

};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    {ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
};
#endif

#ifdef OLED_ENABLE

void render_space(void) { oled_write_P(PSTR("     "), false); }

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if (modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if (modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if (modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if (modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

// adapted from:
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/splitkb/aurora/sofle_v2/sofle_v2.c
void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {0x20, 0x94, 0x95, 0x96, 0x20, 0x20, 0xb4, 0xb5,
                                                 0xb6, 0x20, 0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {0x20, 0x97, 0x98, 0x99, 0x20, 0x20, 0xb7, 0xb8,
                                               0xb9, 0x20, 0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {0x20, 0x9a, 0x9b, 0x9c, 0x20, 0x20, 0xba, 0xbb,
                                               0xbc, 0x20, 0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {0x20, 0x9d, 0x9e, 0x9f, 0x20, 0x20, 0xbd, 0xbe,
                                                0xbf, 0x20, 0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case LAYER_QWERTY:
            oled_write_P(lower_layer, false);
            break;
        case LAYER_DVORAK:
            oled_write_P(default_layer, false);
            break;
        case LAYER_ALT:
            oled_write_P(adjust_layer, false);
            break;
        case LAYER_SHIFT:
            oled_write_P(adjust_layer, false);
            break;
        default:
            oled_write_P(raise_layer, false);
    }
}

// cute cat animation adapted from:
// https://github.com/FlorianBr/Keyboards.Sofle/
static uint32_t anim_timer = 0;   // animation timer
static uint8_t current_frame = 0; // current frame
static bool isawake = false;      // Awake anim?

#define MIN_WALK_SPEED 30   // WPM Threshold for walk anim
#define MIN_RUN_SPEED 60    // WPM Threshold for run anim
#define SPRITE_DURATION 500 // Length in ms for a sprite
#define SPRITE_SIZE 128     // Size of one sprite in byte

static void render_neko(int PosX, int PosY) {
    static const char PROGMEM awake[SPRITE_SIZE] = {
        0x01, 0x40, 0x40, 0x80, 0x80, 0x04, 0x08, 0x10, 0x20, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60,
        0x80, 0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x10, 0x08, 0x04, 0x80, 0x80, 0x40,
        0x40, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0x40, 0x40,
        0x5c, 0x00, 0x01, 0x41, 0x01, 0x00, 0x5c, 0x40, 0x40, 0x80, 0x7f, 0x00, 0x01, 0x01, 0x08,
        0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80,
        0xe1, 0x12, 0x0a, 0x06, 0x00, 0x80, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x90, 0x48, 0x64, 0x92,
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14,
        0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10,
        0x14, 0x14, 0x1f, 0x18, 0x00, 0x00, 0x00, 0x00};
    static const char PROGMEM kaki[][SPRITE_SIZE] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x20, 0x20,
            0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1a, 0x22, 0xc2, 0x04,
            0x04, 0x04, 0x07, 0x00, 0xc0, 0x20, 0x10, 0x80, 0x80, 0x01, 0x01, 0x02, 0xfc,
            0xfe, 0x02, 0x3c, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x09,
            0x08, 0x00, 0x80, 0x00, 0x06, 0x09, 0x1b, 0xee, 0x00, 0x00, 0x00, 0x00, 0x81,
            0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14,
            0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f,
            0x19, 0x18, 0x1c, 0x14, 0x16, 0x15, 0x14, 0x14, 0x14, 0x14, 0x08,
        },
        {0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x20,
         0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x03, 0x80,
         0x40, 0x40, 0x20, 0x00, 0x01, 0x02, 0x8c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94,
         0xf0, 0x10, 0x0a, 0x0e, 0x1d, 0x95, 0x24, 0x24, 0x27, 0x13, 0xe1, 0x01, 0x01, 0x01, 0x01,
         0x02, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14,
         0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18, 0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c,
         0x14, 0x14, 0x17, 0x14, 0x14, 0x14, 0x14, 0x08}};
    static const char PROGMEM run[][SPRITE_SIZE] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x10, 0x10, 0x08,
            0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x10, 0x88, 0x44, 0x22, 0x99,
            0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0xc0, 0x00, 0x00,
            0x00, 0x13, 0x0c, 0x08, 0x08, 0x04, 0x04, 0x82, 0x39, 0x47, 0x80, 0x00, 0x03,
            0x02, 0x01, 0x00, 0x00, 0x01, 0xc2, 0xfc, 0xf0, 0xc0, 0x00, 0x30, 0xd0, 0x50,
            0x58, 0x28, 0x16, 0x09, 0x80, 0x80, 0xc4, 0xc2, 0x62, 0x26, 0x44, 0x44, 0x40,
            0x43, 0x40, 0x20, 0x17, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x00, 0x00, 0x03, 0x06, 0x07, 0x01, 0x01, 0x01, 0x07, 0x07, 0x07, 0x03, 0x01,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
        {0x38, 0x48, 0x88, 0x30, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0xf8, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x0e, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0x04, 0x04,
         0x08, 0x08, 0x10, 0x20, 0x30, 0x0c, 0x06, 0x01, 0x01, 0x40, 0x40, 0x40, 0x40, 0x1d, 0x01,
         0x02, 0x1c, 0xe0, 0x00, 0xf8, 0x88, 0xc6, 0xe1, 0xe0, 0x60, 0x60, 0x70, 0x70, 0x30, 0x28,
         0x68, 0x44, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xe0, 0xe0, 0xc0, 0x80, 0x8c, 0x1c, 0x32,
         0x62, 0xc2, 0x82, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03,
         0x01, 0x01, 0x02, 0x02, 0x03, 0x01, 0x00, 0x00}};
    static const char PROGMEM sleep[][SPRITE_SIZE] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0xa8, 0x48, 0xa8, 0x18, 0x08, 0x00, 0x00,
         0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02,
         0x00, 0x00, 0x80, 0x44, 0x84, 0x06, 0x05, 0x04, 0x80, 0x40, 0x20, 0x10, 0xe0, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x18, 0x04, 0x04,
         0x02, 0x7a, 0x86, 0x01, 0x80, 0x80, 0x01, 0x03, 0x05, 0x07, 0x01, 0x00, 0x00, 0x80, 0x83,
         0x45, 0xfa, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10,
         0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x29, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39,
         0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00},
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x3a, 0x2a, 0x26,
         0x22, 0x80, 0xc0, 0x80, 0x00, 0x24, 0x34, 0x2c, 0xe4, 0x60, 0x10, 0x70, 0x80, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x02,
         0x01, 0x79, 0x87, 0x01, 0x80, 0x81, 0x83, 0x05, 0x05, 0x03, 0x01, 0x00, 0x00, 0x80, 0x43,
         0x05, 0xfa, 0x3c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10,
         0x10, 0x10, 0x10, 0x10, 0x33, 0x24, 0x28, 0x28, 0x28, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39,
         0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00},
    };


    // prints out the current wpm
    oled_set_cursor(1, 7);
    oled_write_P(PSTR("W"), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

    // Animation timer
    if (timer_elapsed32(anim_timer) > SPRITE_DURATION) {
        anim_timer = timer_read32();
        current_frame = (current_frame + 1) % 2; // toggle frame

        oled_set_cursor(PosX, PosY);

        if (get_current_wpm() <= MIN_WALK_SPEED) {
            // prints out the cat :3
            oled_write_raw_P(sleep[abs(1 - current_frame)], SPRITE_SIZE);

            isawake = false;

        } else if (get_current_wpm() <= MIN_RUN_SPEED) {
            if (!isawake) {
                oled_write_raw_P(awake, SPRITE_SIZE);
            } else {
                oled_write_raw_P(kaki[abs(1 - current_frame)], SPRITE_SIZE);
            }
            isawake = true;
        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], SPRITE_SIZE);
        }
    }
}

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        render_space();
        render_layer_state();
        render_space();
        render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
        render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());

    } else {
        render_neko(0, 3);
    }

    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

#endif
