What is this?
-------------

This is a (mostly) simple repeater controller implemented on stm32

It's NOT ready for use yet but may be soon...


Building
--------
	Edit config.h

	make world

	make install


Hardware
--------
* Enable DEBUG in config.h so that extra logging occurs
* Build your board to pin things out as your config.h has
* make world && make install to flash to the device
* Test things out while connected to serial monitor
* Rebuild with DEBUG disabled
* Reflash
* Enjoy!

TODO
----
Implement protocol between stm32 and esp8266 for additional functions:
	GetNtpTime()
	Watchdog()
	FetchTextUrl()




ESP8266-siobridge
-----------------
This should build both from cli and in Arduino IDE.

Run esp8266-siobridge/install.sh to install Arduino IDE addon for flash upload

Build + upload.

Click Tools >> ESP8266 Sketch Data Upload and do the needful.

Open a serial console and press reset button.

esp8266-siobridge will wait 5 seconds from reset/power on before beginning
operation.

This is to give the user time to catch logging messages.
