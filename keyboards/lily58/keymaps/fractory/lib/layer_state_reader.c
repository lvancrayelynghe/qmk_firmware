#include QMK_KEYBOARD_H
#include <stdio.h>

#define L_BASE 0
#define L_SHIFTED (1 << 1)
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_SUPER (1 << 4)
#define L_ADJUST (1 << 5)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)
#define L_FUNC (1 << 6)

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state)
    {
    case L_BASE:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: BASE");
        break;
    case L_SHIFTED:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SHIFTED");
        break;
    case L_LOWER:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: LOWER");
        break;
    case L_RAISE:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RAISE");
        break;
    case L_SUPER:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SUPER");
        break;
    case L_ADJUST:
    case L_ADJUST_TRI:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST");
        break;
    case L_FUNC:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: FUNCTION");
        break;
    default:
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
    }

  return layer_state_str;
}
