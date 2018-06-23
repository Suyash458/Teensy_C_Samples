### C code examples for the Teensy 3.x boards

Some bare metal projects inspired from [dhwlch67's project](https://github.com/dwelch67/teensy_samples) and [Karl Lunt's blog](https://www.seanet.com/~karllunt/bareteensy31.html)

Right now there are two examples

1) Blinky
	- The on board LED blinks at a roughly 0.5 second interval

2) UART
	- The board prints "Hello, world!" over UART1 (pins 0 and 1 for Teensy 3.2) from the schematic [here](https://www.pjrc.com/teensy/pinout.html)
	- Serial doesn't work over the USB port so get one of [these](https://www.sparkfun.com/products/12977) cables, they're useful for other projects involving UART as well.
