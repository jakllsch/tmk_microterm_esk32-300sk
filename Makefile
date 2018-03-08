# Target file name (without extension).
PROJECT = tmk_ht32_microterm

# Directory common source files exist
TMK_DIR = tmk_core

# ChibiOS directory
CHIBIOS = ChibiOS

# ChibiOS-Contrib directory
CHIBIOS_CONTRIB = ChibiOS-Contrib

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC =	matrix_microterm.c \
	led_microterm.c \
	keymap_microterm.c

CONFIG_H = config.h

## chip/board settings
# - the next two should match the directories in
#   <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = HT32
MCU_SERIES = HT32F165x

# Linker script to use
# - it should exist either in <chibios>/os/common/ports/ARMCMx/compilers/GCC/ld/
#   or <this_dir>/ld/
MCU_LDSCRIPT = HT32F1656

# Startup code to use
#  - it should exist in <chibios>/os/common/ports/ARMCMx/compilers/GCC/mk/
MCU_STARTUP = ht32f165x

# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = ESK32-300SK

# Cortex version
MCU = cortex-m3

# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 7

# Vector table for application
# 0x00000000-0x00001000 area is occupied by bootlaoder.*/
# The CORTEX_VTOR... is needed only for MCHCK/Infinity KB
#OPT_DEFS = -DCORTEX_VTOR_INIT=0x00001000
OPT_DEFS =

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes  # Virtual DIP switch configuration
## (Note that for BOOTMAGIC on Teensy LC you have to use a custom .ld script.)
MOUSEKEY_ENABLE = yes   # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
#CONSOLE_ENABLE = yes    # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes       # USB Nkey Rollover

include $(TMK_DIR)/tool/chibios/common.mk
include $(TMK_DIR)/tool/chibios/chibios.mk

program: $(BUILDDIR)/$(PROJECT).bin
	dfu-util -D $(BUILDDIR)/$(PROJECT).bin

