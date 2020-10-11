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

### ROADMAP 
- Fractory logo
- keymap (fr + osx) (quantum/keymap_extras/keymap_french_osx.h)

- logo -> ???
- layer rgb 
- rgb base sate
- update_tri_layer_RGB -> ???
- encoder resolution -> ???
- oled font -> ???
- is_keyboard_left() -> ???

config.h -> OK

### Roadmap guides 
- https://javl.github.io/image2cpp/
- https://joric.github.io/qle/
- https://cpp.hotexamples.com/fr/examples/-/-/update_tri_layer_RGB/cpp-update_tri_layer_rgb-function-examples.html
- https://www.reddit.com/r/olkb/comments/ea1rly/how_do_i_change_the_default_colors_of_rgb/
