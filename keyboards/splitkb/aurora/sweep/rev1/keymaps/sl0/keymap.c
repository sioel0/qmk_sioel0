#include QMK_KEYBOARD_H
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COL] = LAYOUT(
      KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_B  ,  KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  , KC_SCLN,
	    KC_A  ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_G  ,  KC_M  ,  KC_N  ,  KC_E  ,  KC_I  ,  KC_O  ,
	  	KC_Z  ,  KC_X  ,  KC_C  ,  KC_D  ,  KC_V  ,  KC_K  ,  KC_H  , KC_COMM, KC_DOT , KC_SLSH,
	                             NAV_TAB , RA(SPC),HYP_BSPC, SYM_ENT
  ),
	[_QWE] = LAYOUT(
      KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,  KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,
	    KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN,
	    KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH,
	                             NAV_TAB , RA(SPC),HYP_BSPC, SYM_ENT
  ),
	[_NAV] = LAYOUT(
     KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERMCLR, XXXXXXX, XXXXXXX, XXXXXXX,
	  TMUXLEAD, XXXXXXX,  SAVE  ,OM(LSFT), XXXXXXX, KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, XXXXXXX,
	    UNDO  , XXXXXXX,  COPY  ,TERMLOUT,  PASTE , TERMDLN,NEXTELEM,PREVELEM, XXXXXXX, XXXXXXX,
	                             _______ , _______, _______, _______
  ),
	[_SYM] = LAYOUT(
     KC_GRV , KC_BSLS, KC_LPRN, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_RPRN, KC_MINS, KC_PLUS,
	   KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL ,
	   KC_TILD, KC_PIPE, XXXXXXX, KC_QUOT, XXXXXXX, XXXXXXX, KC_DQUO,  KC_LT ,  KC_GT , XXXXXXX,
	                              _______, _______, _______, _______
  ),
	[_NUM] = LAYOUT(
    DF(_COL),DF(_QWE), XXXXXXX, KC_MUTE, KC_BRID, KC_BRIU,  KC_7  ,  KC_8  ,  KC_9  , XXXXXXX,
	  OM(LGUI),OM(LALT),OM(LCTL),OM(LSFT), KC_VOLD, KC_VOLU,  KC_4  ,  KC_5  ,  KC_6  , XXXXXXX,
	   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  KC_0  ,  KC_1  ,  KC_2  ,  KC_3  , XXXXXXX,
	                              _______, _______, _______, _______
  ),
	[_HYP] = LAYOUT(
      CLOSE , MOVLEFT, MOVDOWN,  MOVUP ,MOVRIGHT, FOCLEFT, FOCDOWN,  FOCUP ,FOCRIGHT, XXXXXXX,
	   FOCWSP1, FOCWSP2, FOCWSP3, FOCWSP4, FOCWSP5, FOCWSP6,OPENTERM, MASTSWP, DMENU, XXXXXXX,
	   MOVWSP1, MOVWSP2, MOVWSP3, MOVWSP4, MOVWSP5, MOVWSP6,  LOCK  , FULLSCR, XXXXXXX, XXXXXXX,
	                              _______, _______, _______, _______
  ),
};

// enable on board led
void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(HSV_BLACK);
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

// setup trilayer
layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}

// change caps word standard behavior
bool caps_word_press_user(uint16_t keycode) {
	switch(keycode) {
		// send keycode with shift applied
		case KC_A ... KC_Z:
		  add_weak_mods(MOD_BIT(KC_LSFT));
		  return true;

    // continue caps word without shifting		
		case KC_1 ... KC_0: 
		case KC_BSPC:
		case KC_DEL:
		case KC_UNDS:
		  return true;
    
		// disable caps word
		default:
		  return false;
	}
}

// do stuff based on layer
void housekeeping_task_user(void) {
	if(is_caps_word_on()) {
	  rgblight_setrgb_at(RGB_PURPLE, 0);
	  rgblight_setrgb_at(RGB_PURPLE, 1);
	}
	if(get_oneshot_mods() & MOD_MASK_SHIFT) {
	  rgblight_setrgb_at(RGB_ORANGE, 0);
	  rgblight_setrgb_at(RGB_ORANGE, 1);
	}
}

// tapping term per key settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case NAV_TAB:
		case RA(SPC):
		case HYP_BSPC:
		case SYM_ENT:
		  return 150;
		default:
		  return TAPPING_TERM; 
	}
}

// hold on other key press settings
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case NAV_TAB:
		case SYM_ENT:
		  return true;
		default:
		  return false;
	}
}

void render_sioel0_logo(void) {
	oled_write_raw_P(sioel0_logo, sizeof(sioel0_logo));
	oled_set_cursor(0, 8);
}

void render_github_qr(void) {
	oled_write_raw_P(github_qr, sizeof(github_qr));
}

bool oled_task_user(void) {
	uint8_t current_layer = get_highest_layer(layer_state);
	uint8_t oneshot_mods = get_oneshot_mods();
	uint8_t mods = get_mods();
	if(is_keyboard_master()) {
	  // sioel0 logo height 64 bit
		render_sioel0_logo();
		
		// activate line based on layer height 40
		if(default_layer_state == _COL) {
			oled_write_P(PSTR(" COL "), current_layer == _COL);
		} else if(default_layer_state == _QWE) {
			oled_write_P(PSTR(" QWE "), current_layer == _QWE);
		}
		oled_write_P(PSTR(" NAV "), current_layer == _NAV);
		oled_write_P(PSTR(" SYM "), current_layer == _SYM);
		oled_write_P(PSTR(" NUM "), current_layer == _NUM);
		oled_write_P(PSTR(" HYP "), current_layer == _HYP);

		// mod keys status height 8 bit
		if(oneshot_mods & MOD_MASK_GUI || mods & MOD_MASK_GUI) {
			oled_write_P(PSTR("G"), true);
		} else {
			oled_write_P(PSTR("G"), false);
		}
		if(oneshot_mods & MOD_BIT(KC_LALT) || mods & MOD_BIT(KC_LALT)) {
			oled_write_P(PSTR("A"), true);
		} else {
			oled_write_P(PSTR("A"), false);
		}
		if(oneshot_mods & MOD_MASK_CTRL || mods & MOD_MASK_CTRL) {
			oled_write_P(PSTR("C"), true);
		} else {
			oled_write_P(PSTR("C"), false);
		}
		if(oneshot_mods & MOD_MASK_SHIFT || mods & MOD_MASK_SHIFT) {
			oled_write_P(PSTR("S"), true);
		} else {
			oled_write_P(PSTR("S"), false);
		}
		if(oneshot_mods & MOD_BIT(KC_RALT) || mods & MOD_BIT(KC_RALT)) {
			oled_write_P(PSTR("R"), true);
		} else {
			oled_write_P(PSTR("R"), false);
		}
		
		// padding height 8 bit
		oled_write_P(PSTR("      "), false);
		
		// check caps woc rd state height 8 bit
		oled_write_P(is_caps_word_on() ? PSTR("CAPS") : PSTR("    "), false);
	} else {
		// render sioel0 logo height 64 bit
		render_sioel0_logo();
		render_github_qr();
	}
	return false;
}

