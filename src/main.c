/**
 * main.c
 *
 */
#define F_CPU   16000000UL // 16 MHz external OSC

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>
#include <colorFade.h>

/*
 * Prototypes
 */
void configure(void);
void setPWM(const colorval_t* color);

/*
 * main()
 *  
 *  Process fade table, wash rinse, repeat
 *
 */
int main(void) {
	colorval_t  curval = CV_HSV_BLACK ; // reset to black
  uint8_t     findex = 0 ;            // init fade index to beginning of fade table
  
  /* One-time configuration */
  configure();  // set up I/O and periph

  /* main loop: process fade table */
  while(1) { 
    colorval_t  nextval ;
    colordel_t  deltaval ;
        
    readFade(findex,&nextval); // read next color from fade table and copy into nextval
    initFade(&curval,&nextval,&deltaval); // initialize deltas (simple linear 3D interpolation)
    while(curval.step > 0) { // count down steps
		  stepFade(&curval,&nextval,&deltaval); // Compute new color at each tick
      setPWM(&curval); // Drive current color's PWM duty cycle
      _delay_ms(20); // Wait for next step      
    }
    findex = ++findex < NUM_FADES ? findex : 0 ; // increment fade index (wrap on overflow)
	}
  return 0;
}

/*
 * setPWM(color)
 *  
 *  Set PWM duty cycles for current (HSV) color
 *
 */
void setPWM(const colorval_t* color) {
  colorval_t rgb ;
  hsv2rgb(color,&rgb); // Convert HSV to RGB (PWM is driving R G and B LEDs!)
  OCR1A = readCal(round16to8(rgb.xyz[0]),rcal); // set new calibrated 8-bit PWM for R
  OCR0A = readCal(round16to8(rgb.xyz[1]),gcal); // set new calibrated 8-bit PWM for G
  OCR1B = readCal(round16to8(rgb.xyz[2]),bcal); // set new calibrated 8-bit PWM for B
}

/*
 * configure()
 *  
 *  Initialize output pins and setup timers for PWM
 *
 */
void configure(void) {
  DDRB  = 0x1C; // PB2 is OC0A, PB3 is OC1A, PB4 is OC1B
  PORTB = 0x1C; // start with all LEDs off while we configure the timer PWM
  OCR1A = 0; // Initialize R duty cycle to 0
  OCR0A = 0; // Initialize G duty cycle to 0
  OCR1B = 0; // Initialize B duty cycle to 0
  
  // Set up 1 PWM channel on PB2 using Timer0
  // 8-bit, phase correct, no pre-scaling
  // WGM0[2:0]  = 0b001
  // COM0A[1:0] = 0b10
  // CS0[2:0]   = 0b001
  // (F_CPU/( N * 510 ) = 31.4 kHz PWM period @ F_CPU=16MHz,N=1
  TCCR0A    = (1<<COM0A1)|(0<<COM0A0)|(0<<COM0B1)|(0<<COM0B0)|
              (0<<WGM01) |(1<<WGM00) ;
  TCCR0B    = (0<<WGM02) |(0<<CS02)  |(0<<CS01)  |(1<<CS00) ;              

  // Set up 2 PWM channels on PB3&PB4 using Timer1
  // 8-bit, phase correct, no pre-scaling
  // WGM1[3:0]  = 0b0001
  // COM1A[1:0] = 0b10
  // COM1B[1:0] = 0b10
  // CS1[2:0]   = 0b001
  // (F_CPU/( N * 510) = 31.4 kHz PWM period @ F_CPU=16MHz,N=1
  TCCR1A  = (1<<COM1A1)|(0<<COM1A0)|(1<<COM1B1)|(0<<COM1B0)|
            (0<<FOC1A) |(0<<FOC1B) |(0<<WGM11) |(1<<WGM10) ;
  TCCR1B  = (0<<ICNC1) |(0<<ICES1) |(0<<5)     |(0<<WGM13) |
            (0<<WGM12) |(0<<CS12)  |(0<<CS11)  |(1<<CS10)  ; 
}