#
#             LUFA Library
#     Copyright (C) Dean Camera, 2014.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

ASIS_MAIN = asis+_main
# Path to "programs" folder
ASIS_PROGRAM_PATH = ./programs
ASIS_PROGRAM_LIB_PATH =  		
ASIS+_PROGRAM_SRC =

# Include ASIS+ program makefiles
include $(ASIS_PROGRAM_PATH)/programs.mk


# Library Paths
LUFA_PATH = ./lufa/LUFA
ASIS_PATH = ./asis
U8X8_PATH = ./u8g2/csrc
U8X8_AVR_PATH = $(U8X8_PATH)/../sys/avr/avr-libc/lib

# MCU settings
MCU          = at90usb1286
ARCH         = AVR8
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = ./build/$(ASIS_MAIN)

# Sources
U8X8_SRC =  $(U8X8_AVR_PATH)/u8x8_avr.c \
			$(U8X8_PATH)/u8x8_8x8.c \
			$(U8X8_PATH)/u8x8_byte.c \
			$(U8X8_PATH)/u8x8_cad.c \
			$(U8X8_PATH)/u8x8_d_ssd1306_128x32.c \
			$(U8X8_PATH)/u8x8_setup.c \
			$(U8X8_PATH)/u8x8_display.c \
			$(U8X8_PATH)/u8x8_fonts.c \
			$(U8X8_PATH)/u8x8_gpio.c \
			
ASIS_SRC =  $(ASIS_PATH)/asis_display_adapter.c \
            $(ASIS_PATH)/asis+_hw_adapter.c \
			$(ASIS_PATH)/asis_joystick_adapter.c \
			$(ASIS_PATH)/asis_joystick_descriptors.c \
			$(ASIS_PATH)/asis+.c
			
ASIS_PROGRAM_LIB_SRC = $(ASIS_PROGRAM_PATH)/program_hook.c

SRC = 	$(ASIS_PATH)/$(ASIS_MAIN).c \
        $(ASIS+_PROGRAM_SRC) \
		$(ASIS_SRC) \
		$(U8X8_SRC) \
		$(LUFA_SRC_USB) \
		$(ASIS_PROGRAM_LIB_SRC)

CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/ \
							 -I$(U8X8_PATH) \
							 -I$(U8X8_AVR_PATH) \
							 -I$(ASIS_PATH) \
							 -I$(ASIS_PROGRAM_PATH) \
							 $(ASIS_PROGRAM_LIB_PATH) \
							 
LD_FLAGS     = 

# Default target
all: build

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk

build:
	mkdir build

clean:
	rm -rf build obj



