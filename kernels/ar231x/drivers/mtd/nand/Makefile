#
# linux/drivers/nand/Makefile
#
# $Id: //depot/sw/linuxsrc/src/kernels/mips-linux-2.4.25/drivers/mtd/nand/Makefile#1 $

O_TARGET	:= nandlink.o

export-objs	:= nand.o nand_ecc.o nand_ids.o

obj-$(CONFIG_MTD_NAND)		+= nand.o nand_ecc.o
obj-$(CONFIG_MTD_NAND_SPIA)	+= spia.o
obj-$(CONFIG_MTD_NAND_AUTCPU12)	+= autcpu12.o
obj-$(CONFIG_MTD_NAND_EDB7312)  += edb7312.o
obj-$(CONFIG_MTD_NAND_IDS)	+= nand_ids.o

include $(TOPDIR)/Rules.make
