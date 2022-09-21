all:

# This is disabled for now, while we finish porting from stm32f7xx to stm32f4xx used on stm32-repeater
#
#all: world

CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld

CFLAGS += -I. -I./FATFS/Target

LDSCRIPT_FLASH = STM32F767ZITX_FLASH.ld
LDSCRIPT_RAM = STM32F767ZITX_RAM.ld
bins += build/bootloader.elf

include ./chk_headers.mk

src += ./Middlewares/Third_Party/FatFs/src/ff_gen_drv.c
src += ./Middlewares/Third_Party/FatFs/src/ff.c
src += ./Middlewares/Third_Party/FatFs/src/diskio.c
src += ./Middlewares/Third_Party/FatFs/src/option/ccsbcs.c
src += ./Middlewares/Third_Party/FatFs/src/option/syscall.c
src += ./FATFS/App/fatfs.c
src += ./FATFS/Target/user_diskio_spi.c
src += ./FATFS/Target/user_diskio.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
src += ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
src += ./Core/Src/syscalls.c
src += ./Core/Src/stm32f7xx_it.c
src += ./Core/Src/main.c
src += ./Core/Src/system_stm32f7xx.c
src += ./Core/Src/sysmem.c
src += ./Core/Src/stm32f7xx_hal_msp.c
src += ./Core/Src/etx_ota_update.c

objs := $(patsubst %.c, %.o, ${src})

world: ${bins}

clean:
	${RM} -f build/*

install:

build/bootloader.elf: ${objs} ${incs}
	${CC} ${LDFLAGS} -o $@

%.o:%.c ${incs}
	${CC} ${CFLAGS} -o $@ -c $<
