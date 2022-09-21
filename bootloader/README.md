This folder contains our modified version of stm32 bootloader adding
OTA (Over The Air) updating via serial port.

Eventually this will allow updating the stm32 over the serial port.

You either need to hook a gpio on siobridge to the stm32's RST pin to
allow resetting it, or implement BOOTWAIT.

If BOOTWAIT is used, the stm32 will wait for BOOTWAIT seconds for a
command before starting the application.

The prompt during bootloader BOOTWAIT is "LOADER:"

The following commands are planned:
	OTA		Over The Air flashing
	ZAP		Sets EEPROM flag causing config.txt to be erased at boot


This *IS NOT* yet ready, but hopefully will be soon!
