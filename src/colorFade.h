#ifndef COLORFADE_H
#define COLORFADE_H

#include <asf.h>
#include <asf/mega/utils/progmem.h>

#define NUM_COLORS    3 // Number of color channels
#define NUM_FADES     7 // Number of fades in the fade table (globalFade.h)

/*
 * color value struct
 */
typedef struct {
	uint16_t  xyz[NUM_COLORS] ;
	uint8_t   step ;
} colorval_t ;

// Some common colors, in colorval_t format...
#define CV_HSV_BLACK    {{   0,  0,  0},0}
#define CV_HSV_WHITE    {{   0,  0,255},0}
#define CV_HSV_RED      {{   0,255,255},0}
#define CV_HSV_YELLOW   {{ 256,255,255},0}
#define CV_HSV_GREEN    {{ 512,255,255},0}
#define CV_HSV_CYAN     {{ 768,255,255},0}
#define CV_HSV_BLUE     {{1024,255,255},0}
#define CV_HSV_MAGENTA  {{1280,255,255},0}

/*
 * color delta struct
 */
typedef struct {
  int16_t   xyz[NUM_COLORS] ;
} colordel_t ;

/*
 * function prototypes
 */
uint8_t round16to8(const uint16_t val);
void    hsv2rgb(const colorval_t*  hsv, colorval_t* rgb);
uint8_t readCal(const uint8_t val, const uint8_t* table);
void    readFade(const uint8_t fadenum, colorval_t* val);
void    initFade(colorval_t* start, colorval_t* end, colordel_t* delta);
uint8_t stepFade(colorval_t* cur,   colorval_t* end, colordel_t* delta);

extern PROGMEM_LOCATION(uint8_t, rcal[UINT8_MAX+1],".rcal_table");
extern PROGMEM_LOCATION(uint8_t, gcal[UINT8_MAX+1],".gcal_table");
extern PROGMEM_LOCATION(uint8_t, bcal[UINT8_MAX+1],".bcal_table");

#endif // COLORFADE_H
