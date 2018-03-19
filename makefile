
.c.o:
	$(CC) $(CCFLAGS) $<

.s.o:
	$(AS) $(ASFLAGS) $<

AS = m68k-elf-gcc
ASFLAGS = -c -Wa,-m68020

CC = m68k-elf-gcc
CCFLAGS = -m68020 -Wa,-m68020 -c

LD = m68k-elf-ld

FILES = startup.o main.o worms.o stringio.o sys.o

all: $(FILES)
	$(LD) -Ttext 0x80000 -o worms $(FILES)
	m68k-elf-objcopy --target srec worms worms.srec

