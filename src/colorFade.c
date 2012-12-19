/*
 * colorFade.c
 *
 */
#include <colorFade.h>
#include <calibrationGlobal.h>
#include <fadeGlobal.h>

/*
 * hsv2rgb(const colorval_t*  hsv, colorval_t* rgb)
 * 
 *   Converts HSV data to RGB data
 */
void hsv2rgb(const colorval_t*  hsv, colorval_t* rgb) {
  uint8_t r, g, b, lo;
  uint16_t s1,v1;
  int16_t h;

  // Hue
  h = hsv->xyz[0];
  h %= 1536;             // -1535 to +1535
  if(h < 0) h += 1536;   //     0 to +1535
    lo = h & UINT8_MAX;  // Low byte  = primary/secondary color mix
  switch(h >> 8) {       // High byte = sextant of colorwheel
    case 0 : r = UINT8_MAX     ; g =  lo           ; b =   0           ; break; // R to Y
    case 1 : r = UINT8_MAX - lo; g = UINT8_MAX     ; b =   0           ; break; // Y to G
    case 2 : r =   0           ; g = UINT8_MAX     ; b =  lo           ; break; // G to C
    case 3 : r =   0           ; g = UINT8_MAX - lo; b = UINT8_MAX     ; break; // C to B
    case 4 : r =  lo           ; g =   0           ; b = UINT8_MAX     ; break; // B to M
    default: r = UINT8_MAX     ; g =   0           ; b = UINT8_MAX - lo; break; // M to R
  }

  // Saturation:
  s1 = hsv->xyz[1] + 1;
  r = UINT8_MAX - (((UINT8_MAX - r) * s1) >> 8);
  g = UINT8_MAX - (((UINT8_MAX - g) * s1) >> 8);
  b = UINT8_MAX - (((UINT8_MAX - b) * s1) >> 8);

  // Value (brightness) 
  v1 = hsv->xyz[2] + 1;
  rgb->xyz[0] = (uint16_t)(r * v1) ;
  rgb->xyz[1] = (uint16_t)(g * v1) ;
  rgb->xyz[2] = (uint16_t)(b * v1) ;
}

/*---------------------------------------------------*/
uint8_t round16to8(const uint16_t val) {
  return (uint8_t)((val+0x8)>>8);
}

/*---------------------------------------------------*/
uint8_t readCal(const uint8_t val, const uint8_t* table) {
  return pgm_read_byte(&(table[(uint8_t)val]));
}

/*---------------------------------------------------*/
void readFade(const uint8_t fadenum, colorval_t* fadeval) {
  for(int i=0;i<NUM_COLORS;i++){
    fadeval->xyz[i] = pgm_read_word(&(fade[fadenum].xyz[i]));
  }
  fadeval->step = pgm_read_byte(&(fade[fadenum].step));
}

/*---------------------------------------------------*/
void initFade(colorval_t* start, colorval_t* end, colordel_t* delta) {
  for(uint8_t i=0;i<NUM_COLORS;i++) {
    int32_t temp = ((int32_t)end->xyz[i] - start->xyz[i]) / end->step ;
    delta->xyz[i] = (int16_t)( temp > INT16_MAX ? INT16_MAX : ( temp < INT16_MIN ? INT16_MIN : temp ));
  }
  start->step = end->step;
}

/*---------------------------------------------------*/
uint8_t stepFade(colorval_t* cur, colorval_t* end, colordel_t* delta) {
  uint32_t absdiff ;
  uint32_t absdelta;  
  if ( cur->step > 0 ) {
    for(uint8_t i=0;i<NUM_COLORS;i++) {
      absdiff  = (uint32_t)labs((uint32_t)end->xyz[i] - cur->xyz[i]) ; 
      absdelta = (uint32_t)labs((uint32_t)delta->xyz[i]) ;
      if ( absdiff > absdelta ) {
        // do step
        cur->xyz[i] += delta->xyz[i] ;
      } else { // stop stepping
        cur->xyz[i] = end->xyz[i] ;
      }
    } 
    return cur->step-- ;
  }
  return 0 ;
}


