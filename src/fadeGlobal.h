/*
 * fadeGlobal.h
 *
 */ 
#ifndef FADEGLOBAL_H_
#define FADEGLOBAL_H_

#include <colorFade.h>

// AVRGCC requires hand-holding to understand data storage in
// program memory beyond simply using 'const'. The macros below
// handle this.

// List of fade setpoints
//   {{H,S,V},duration}
PROGMEM_LOCATION(colorval_t, fade[NUM_FADES],".fade_table") = {
  {{   0, 255, 255},255},
  {{1536, 255, 255},255},
  {{ 511, 255, 255},255},
  {{ 767, 255, 255},255},
  {{1023, 255, 255},255},
  {{1279, 255, 255},255},
  {{1536, 255, 255},255},
};

#endif 