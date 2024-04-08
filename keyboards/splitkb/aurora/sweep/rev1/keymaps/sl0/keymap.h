#ifndef KEYMAP_H
#define KEYMAP_H

#define SPC KC_SPC

// custom keys for mod toggle
#define LA(kc) LALT_T(kc)
#define LS(kc) LSFT_T(kc)
#define LG(kc) LGUI_T(kc)
#define LC(kc) LCTL_T(kc)
#define RA(kc) RALT_T(kc)
#define RS(kc) RSFT_T(kc)
#define RG(kc) RGUI_T(kc)
#define RC(kc) RCTL_T(kc)
#define OM(kc) OSM(MOD_ ## kc)

// custom keys for layer toggle
#define NAV_TAB LT(_NAV, KC_TAB)
#define HYP_BSPC LT(_HYP, KC_BSPC)
#define SYM_ENT LT(_SYM, KC_ENT)

// tmux and general shortcuts
#define TMUXLEAD LCTL(KC_A)
#define UNDO LCTL(KC_Z)
#define SAVE LCTL(KC_S)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define TERMLOUT LCTL(KC_D)
#define TERMCLR LCTL(KC_L)
#define TERMDLN LCTL(KC_K)
#define NEXTELEM LCTL(KC_N)
#define PREVELEM LCTL(KC_P)

// hyprland shortcuts
#define CLOSE LALT(LSFT(KC_Q))
#define OPENTERM LALT(KC_ENT)
#define MASTSWP LALT(LSFT(KC_ENT))
#define LOCK LALT(LSFT(KC_X))
#define FULLSCR LALT(KC_M)
#define FOCLEFT LALT(KC_H)
#define FOCDOWN LALT(KC_J)
#define FOCUP LALT(KC_K)
#define FOCRIGHT LALT(KC_L)
#define MOVLEFT LALT(LSFT(KC_H))
#define MOVDOWN LALT(LSFT(KC_J))
#define MOVUP LALT(LSFT(KC_K))
#define MOVRIGHT LALT(LSFT(KC_L))
#define FOCWSP1 LALT(KC_1)
#define FOCWSP2 LALT(KC_2)
#define FOCWSP3 LALT(KC_3)
#define FOCWSP4 LALT(KC_4)
#define FOCWSP5 LALT(KC_5)
#define FOCWSP6 LALT(KC_6)
#define MOVWSP1 LALT(LSFT(KC_1))
#define MOVWSP2 LALT(LSFT(KC_2))
#define MOVWSP3 LALT(LSFT(KC_3))
#define MOVWSP4 LALT(LSFT(KC_4))
#define MOVWSP5 LALT(LSFT(KC_5))
#define MOVWSP6 LALT(LSFT(KC_6))


// LAYERS
enum layers {
  _COL,
  _QWE,
  _NAV,
  _SYM,
  _NUM,
  _HYP,
};

// key override settings
const key_override_t sbpc_delete = ko_make_basic(MOD_MASK_SHIFT, HYP_BSPC, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]) {
  &sbpc_delete,
  NULL,
};

// sioel0 logo
static const char sioel0_logo[] = { // 32x64
  0x00, 0x00, 0xc0, 0xa0, 0xa0, 0x20, 0x00, 0x20, 0xe8, 0x00, 0xc0, 0x20, 0x20, 0x20, 0xc0, 0x00, 
  0xc0, 0xa0, 0xa0, 0xa0, 0xc0, 0x00, 0xf8, 0x00, 0x00, 0xf0, 0x08, 0x88, 0x48, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00, 0x07, 0x00, 0x03, 0x04, 0x04, 0x04, 0x03, 0x00, 
  0x03, 0x04, 0x04, 0x04, 0x02, 0x00, 0x07, 0x04, 0x00, 0x03, 0x05, 0x04, 0x04, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0xe0, 0x08, 0x40, 0x08, 0x00, 0xa0, 0x00, 0x00, 0x1c, 0x20, 0xc8, 0x08, 0xe8, 0x08, 
  0xf8, 0x00, 0xe8, 0x00, 0xe8, 0x20, 0x20, 0x20, 0x20, 0xa0, 0x20, 0xe0, 0x00, 0x00, 0x00, 0x00, 
  0x10, 0x10, 0x7f, 0x50, 0x50, 0x52, 0x50, 0x00, 0x50, 0xf8, 0x0d, 0x08, 0x0d, 0x08, 0x0d, 0x08, 
  0x0d, 0x08, 0x0d, 0x08, 0x0d, 0xf8, 0x50, 0x00, 0x50, 0x50, 0x50, 0x5f, 0x40, 0x40, 0xf8, 0x48, 
  0x00, 0xc5, 0x50, 0x44, 0x51, 0x41, 0x55, 0x00, 0x55, 0xff, 0x80, 0x87, 0x85, 0x87, 0x82, 0x82, 
  0x82, 0x86, 0x82, 0x86, 0x80, 0xff, 0x55, 0x00, 0x55, 0x14, 0x15, 0x94, 0x25, 0x44, 0x47, 0x40, 
  0x00, 0x7f, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x2a, 0x00, 0x00, 0x05, 0x00, 0x15, 0x00, 0xfd, 0x00, 
  0x1d, 0x10, 0xfd, 0x10, 0x55, 0x50, 0x50, 0x57, 0xd5, 0x07, 0x00, 0xa8, 0x02, 0xa8, 0x02, 0xa8, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x60, 0x60, 0x80, 0x81, 0x00, 
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x06, 0x06, 0x01, 0x01, 0x00, 
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char github_qr[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xfe, 0x82, 0xba, 0xba, 0xba, 0x82, 0xfe, 0x00, 0xe6, 0x24, 0xbc, 0x6a, 0x8e, 0x72, 0xd6, 
  0x22, 0x96, 0x76, 0xdc, 0x06, 0xf2, 0x00, 0xfe, 0x82, 0xba, 0xba, 0xba, 0x82, 0xfe, 0x00, 0x00, 
  0x00, 0x42, 0x72, 0x7a, 0xe8, 0x88, 0x72, 0xaa, 0xd4, 0x5b, 0xb6, 0x07, 0x29, 0xe1, 0x23, 0x60, 
  0xfb, 0x5d, 0x32, 0x84, 0x37, 0xcd, 0x22, 0x9a, 0x96, 0x62, 0x74, 0x20, 0x92, 0x3a, 0x00, 0x00, 
  0x00, 0xa8, 0xad, 0x8d, 0x92, 0x80, 0x9b, 0xaa, 0x3a, 0x6c, 0x31, 0x3a, 0x29, 0xe1, 0x13, 0x47, 
  0x7f, 0x51, 0x12, 0x4b, 0x77, 0xfd, 0x25, 0xbb, 0x3d, 0xe0, 0x06, 0x02, 0x28, 0xb7, 0x00, 0x00, 
  0x00, 0x3f, 0x20, 0x2e, 0x2e, 0x2e, 0x20, 0x3f, 0x00, 0x39, 0x22, 0x2e, 0x29, 0x2b, 0x22, 0x15, 
  0x3a, 0x23, 0x30, 0x07, 0x02, 0x1f, 0x2a, 0x02, 0x26, 0x37, 0x1a, 0x11, 0x1e, 0x39, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void render_sioel0_logo(void);
void render_github_qr(void);

#endif