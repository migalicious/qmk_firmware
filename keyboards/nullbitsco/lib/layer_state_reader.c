
// #include QMK_KEYBOARD_H
#include <stdio.h>
#include "tidbit.h"

#define L_BASE 0
#define L_VIA1 (1 << 1)
#define L_VIA2 (1 << 2)
#define L_VIA3 (1 << 3)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_VIA1:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: VIA1");
    break;
  case L_VIA2:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: VIA2");
    break;
  case L_VIA3:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: VIA3");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%d", layer_state);
  }

  return layer_state_str;
}
