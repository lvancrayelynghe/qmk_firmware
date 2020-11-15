### PCB Specs by standard lily58 base PCB
- UNUSED_PINS { F4 }
- ENCODERS_PAD_A { D4 }
- ENCODERS_PAD_B { F5 }
- ENCODERS_PAD_A_RIGHT { F5 }
- ENCODERS_PAD_B_RIGHT { D4 }

### Fractory Spec 
- from `OLED_FONT_H "lib/glcdfont_lily.c"`
- to `OLED_FONT_H "glcdfont.c"` (reset to base oled config)

### Utils / Notes

- Flash both sides
`qmk flash -kb lily58 -km fractory`

- Flash each side with EEPROM
`qmk flash -kb lily58 -km fractory -bl avrdude-split-left`
`qmk flash -kb lily58 -km fractory -bl avrdude-split-right`

- Update build dependancies
`make git-submodule`

## Ideas
- Raise + OS + Enc -> alt+tab
- Page Up & Down -> navigate up down in text (mod tap ??)
- End -> text nav end

### ROADMAP 
- keymap (fr + osx) (quantum/keymap_extras/keymap_french_osx.h)
- eeprom rgb config
- Velocikey

RGB Base State          -> OK
Fractory Logo           -> OK
Oled Font               -> OK
config.h                -> OK
is_keyboard_left()      -> OK
Encoder resolution      -> OK
update_tri_layer_RGB    -> OK
Layer RGB               -> OK

### Roadmap guides 
- https://docs.qmk.fm/#/feature_velocikey
- https://www.reddit.com/r/olkb/comments/94zmyf/custom_keycode_when_key_is_hit_while_holding_shift/
- https://javl.github.io/image2cpp/
- https://joric.github.io/qle/
- https://cpp.hotexamples.com/fr/examples/-/-/update_tri_layer_RGB/cpp-update_tri_layer_rgb-function-examples.html
- https://www.reddit.com/r/olkb/comments/ea1rly/how_do_i_change_the_default_colors_of_rgb/
- keyboards/crkbd/keymaps/gotham
