#
# Copyright (c) 2022, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

DEVICE = RZFIVE
FILENAME_ADD = _RZFIVE_SMARC
CONNECT  = DDR_C_011_D4_01_2
SWIZZLE  = T3BCUD2

#CPU
CPU     = 
AArch   = RISCV
ALIGN   = -mstrict-align
BOOTDIR     = riscv_boot
OUTPUT_DIR  = riscv_output
OBJECT_DIR  = riscv_obj
CROSS_COMPILE ?= riscv64-unknown-linux-gnu-

CFLAGS += -O0 -fno-stack-protector -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
FILE_NAME   = $(OUTPUT_DIR)/sieve$(FILENAME_ADD)

CFLAGS += -DRZFIVE=1
CFLAGS += -DDDR_C_011_D4_01_2=1
CFLAGS += -DSWIZZLE_T3BCUD2=1

MEMORY_DEF = memory_sieve.def

LIBS        = -L$(subst libc.a, ,$(shell $(CC) -print-file-name=libc.a 2> /dev/null)) -lc
LIBS        += -L$(subst libgcc.a, ,$(shell $(CC) -print-libgcc-file-name 2> /dev/null)) -lgcc -lm

INCLUDE_DIR = include
DDR_COMMON = ddr/common
DDR_SOC    = ddr/five

OUTPUT_FILE = $(FILE_NAME).axf

#Object file
OBJ_FILE_BOOT =				\
	$(OBJECT_DIR)/start.o

SRC_FILE :=				\
	main.c				\
	cpudrv.c			\
	sys/sysc.c			\
	sys/rzfive_cpg.c		\
	sys/tzc_400.c			\
	sieve.c			\
	ddr/common/ddr.c 		\
	ddr/five/ddr_five.c


OBJ_FILE := $(addprefix $(OBJECT_DIR)/,$(patsubst %.c,%.o,$(SRC_FILE)))

#Dependency File
DEPEND_FILE = $(patsubst %.lib, ,$(OBJ_FILE:%.o=%.d))

###################################################
#C compiler
CC = $(CROSS_COMPILE)gcc
#Assembler
AS = $(CROSS_COMPILE)as
#Linker
LD = $(CROSS_COMPILE)ld
#Liblary
AR = $(CROSS_COMPILE)ar
#Object dump
OBJDUMP = $(CROSS_COMPILE)objdump
#Object copy
OBJCOPY = $(CROSS_COMPILE)objcopy

#clean
CL = rm -rf

###################################################
# Suffixes
.SUFFIXES : .s .c .o

###################################################
# Command

.PHONY: all
all: $(OBJECT_DIR) $(OUTPUT_DIR) $(OBJ_FILE_BOOT) $(OBJ_FILE) $(OUTPUT_FILE)

#------------------------------------------
# Make Directory
#------------------------------------------
$(OBJECT_DIR):
	-mkdir "$(OBJECT_DIR)"

$(OUTPUT_DIR):
	-mkdir "$(OUTPUT_DIR)"

#------------------------------------------
# Compile
#------------------------------------------
$(OBJECT_DIR)/%.o:$(BOOTDIR)/%.s
	$(AS)  -g $(CPU) --MD $(patsubst %.o,%.d,$@) -I $(BOOTDIR) -I $(INCLUDE_DIR) -I $(DDR_COMMON) -I $(DDR_SOC) $< -o $@

$(OBJECT_DIR)/%.o:%.c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) -g -Os $(ALIGN) $(CPU) -MMD -MP -c -I $(BOOTDIR) -I $(INCLUDE_DIR) -I $(DDR_COMMON) -I $(DDR_SOC) $< -o $@ $(CFLAGS)

#------------------------------------------
# Linker
#------------------------------------------
$(OUTPUT_FILE): $(OBJ_FILE_BOOT) $(OBJ_FILE) $(MEMORY_DEF)
	$(LD) $(OBJ_FILE_BOOT) $(OBJ_FILE) 	\
	-T '$(MEMORY_DEF)'			\
	-o '$(OUTPUT_FILE)'			\
	-Map '$(FILE_NAME).map' 		\
	-static					\
	$(LIBS)

#   Make MOT file
	$(OBJCOPY) -O srec --srec-forceS3 "$(OUTPUT_FILE)" "$(FILE_NAME).mot"

#   Make Binary file
	$(OBJCOPY) -O binary "$(OUTPUT_FILE)" "$(FILE_NAME).bin"

#   Dis assemble
	$(OBJDUMP) -d -S "$(OUTPUT_FILE)" > "$(FILE_NAME)_disasm.txt"

#	Time Stamp
	@echo ==========  `date`  ==========
	@echo ========== !!! Compile Complete !!! ==========


.PHONY: clean
clean:
	$(CL)  $(OBJECT_DIR)/* $(OUTPUT_DIR)/*

-include $(DEPEND_FILE)
