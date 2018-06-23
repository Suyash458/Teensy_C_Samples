#include  "common.h"

void gpio_init() {
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; //Set clock gating for GPIO
	PORTB_PCR17 = (3 << 8) | (1 << 6); //Drive Strength enable and DMA interrupt on either edge
	GPIOC_PDDR |= (1 << 5); //configure pin 5 as output
	PORTC_PCR5 = (1 << 8); //select function for pin 5 as GPIO
}

void uart_init(uint32_t baud_rate) {
	/*
	Calculate the uart clock divider in 32nds
	last 5 bits = fine adjustment
	next 8 bits = BDL
	next 5 bits = BDH
	*/

	SIM_SCGC4 |=  SIM_SCGC4_UART0_MASK; //Set clock gating for UART0
	uint32_t baud_rate_divider = (uint32_t)((mcg_clk_hz * 2)/(baud_rate));

	UART0_BDH = (baud_rate_divider >> 13) & 0x1F;
	UART0_BDL = (baud_rate_divider >> 5) & 0xFF;
	UART0_C4 = (baud_rate_divider) & 0x1F; //Fine adjustment for remainder
	UART0_C2 = UART_C2_TE_MASK; //transmitter enable
}

void uart_send_byte(uint8_t data) {
	while(!(UART0_S1 & UART_S1_TC_MASK)); //wait till transmission complete bit is set
	UART0_D = data;
}

int main(void) {
	gpio_init();
	uart_init(115200);

	while(1) {
		uart_send_byte(0x4B); //ASCII for 'K';
		GPIOC_PTOR  = (1 << 5); //Toggle LED
		for(int n=0; n<1000000; n++); //dumb delay
	}
}