COM=6
filename = main
sdcc_path = 'C:\Program Files\SDCC\bin\sdcc.exe'
fm_path = 'C:\Program Files (x86)\Flash Magic\fm.exe'

all: compile eraseAndFlash clean

compile: $(filename).c
	$(sdcc_path) -mmcs51 $(filename).c

erase:
	$(fm_path) 'DEVICE(89C51RD2Hxx, 11.0592, 0) COM($(COM),9600) ERASE(0, PROTECTISP)'

flash: $(filename).ihx
	$(fm_path) 'DEVICE(89C51RD2Hxx, 11.0592, 0) COM($(COM),9600) HEXFILE($(filename).ihx, NOCHECKSUMS, NOFILL, PROTECTISP)'

eraseAndFlash: $(filename).ihx
	$(fm_path) 'DEVICE(89C51RD2Hxx, 11.0592, 0) COM($(COM),9600) ERASE(0, PROTECTISP) HEXFILE($(filename).ihx, NOCHECKSUMS, NOFILL, PROTECTISP)'

setPaths:
	$(fm_path)

clean:
	rm $(filename).asm $(filename).ihx $(filename).lk $(filename).lst $(filename).map $(filename).mem $(filename).rel $(filename).rst $(filename).sym