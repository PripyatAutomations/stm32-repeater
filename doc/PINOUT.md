CPU
---
	STM32F401CCU6 @ 84mhz
	256kbyte flash
	64kbyte ram


Header Pins
-----------
1	PTT OUT			TX Radio
2	COS IN			RX Radio
3	GND			Shared GND
4	AUDIO IN		Squelched audio from RX radio
5	AUDIO OUT		Audio out to TX radio (mixed)
6
7
8
9	* SIO_RX		Serial RX from esp8266
10	* SIO_TX		Serial TX to esp8266
11	RST			Ground to reset stm32
12	
13	+5V			+5V to power esp8266


STM32 PINS
----------
B8	I2C1 SCL		-> PCM5102A SCL
B9	I2C1 SDA		-> PCM5102A SDA
A0
A1
A2	COR/TOR Input		-> Optocoupler to pin 2 (COR/TOR in)
A3	PTT Output		-> PTT buffer circuit
A4
A5	SIO_RX			Serial RX from esp8266
A6	SIO_TX			Serial TX to esp8266
A7	Mix audio in
A8	(USB FS_SOF)
A9	(USB/OTG FS_VBUS)
A10	(USB FS_ID)
A11	* (USB FS DM-)
A12	* (USB FS DM+)
A13	* (SWDIO)
A14	* (SWCLK)
A15	(JTDI)
B0
B1
B2	BOOT1 dipswitch
B3	(JTDO-SWO)
B4	(JTRST)
B5
B6
B7
B8	* RX_LED
B9	* TX_LED
B10	* CONFLICT_LED
B11
B12
B13
B14
B15	(RTC_REFIN)
C13	* BLUE LED
C14	(RSVD OSC32 OUT
C15	(RSVD OSC32 IN)
H0	(RSVD)
H1	(RSVD)


Display Board
-------------
	74HC595
		1-7 	output bits 1-7
		8 	GND
		10	MR (master reset) - to VCC
		11	SH_CP - to STM32 GPIO#1
		12	ST_CP - to STM32 GPIO#2
		13	OE (output enable) - to GND
		14	Serial Input - to STM32 GPIO#3
		15	output bit 8
		16	VCC

TODO
----
