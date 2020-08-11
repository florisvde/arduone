# This Makefile will compile a .c file called 'filename.c' with SDCC into a 8051 .ihx file called 'filename.ihx'.
# Then FlashMagic will erase block 0, and flash 'filename.ihx' onto the ArduOne connected to COM-port number 'COM'.

# The variables below can be edited, but be sure not to add any spaces before or after the declerations.

# COM-port number:
COM=6

# The name of the .c file to be compiled and flashed:
filename=main

# In cases where del doesn't work, change 'del' to 'rm' or 'erase' or 'Remove-Item'
remove_cmd=del

# This solved some problems on some machines, thanks to: https://stat545.com/make-windows.html and https://github.com/STAT545-UBC/Discussion/issues/54
SHELL=cmd.exe

all: compile erase flash clean

compile: $(filename).c
	if not exist objs mkdir objs
	sdcc -mmcs51 $(filename).c -o objs/

erase:
	FM DEVICE(89C51RD2Hxx, 11.0592, 0) COM($(COM),9600) ERASE(0, PROTECTISP)

flash: objs/$(filename).ihx
	FM DEVICE(89C51RD2Hxx, 11.0592, 0) COM($(COM),9600) HEXFILE(objs\$(filename).ihx, NOCHECKSUMS, NOFILL, PROTECTISP)

clean:
	if exist objs rd /Q /S objs