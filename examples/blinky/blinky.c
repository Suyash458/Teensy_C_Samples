/*
 *  blinky.c for the Teensy 3.1 board (K20 MCU, 16 MHz crystal)
 *
 *  This code will blink the Teensy's LED.  Each "blink" is
 *  really a set of eight pulses.  These pulses give the actual
 *  system clock in Mhz, starting with the MSB.  A pulse is
 *  narrow for a 0-bit and wide for a 1-bit.
 *
 *  For a system clock of 72 MHz, blinks will read 0x48.
 *  For a system clock of 48 MHz, blinks will read 0x30.
 */

#include  "common.h"

void gpio_init() {
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; //Set clock gating for GPIO
	PORTB_PCR17 = (3 << 8) | (1 << 6); //Drive Strength enable and DMA interrupt on either edge
	GPIOC_PDDR |= (1 << 5); //configure pin 5 as output
	PORTC_PCR5 = (1 << 8); //select function for pin 5 as GPIO
}

void blink() {
	GPIOC_PTOR  = (1 << 5); //Toggle LED
	for(int n=0; n<1000000; n++); //dumb delay	
}

int  main(void) {
	gpio_init();
	while(1) {
		blink();
	}
}
