# Viz @ 2021.05.15

TARGET := hello-os.img
OBJS := entry.o main.o vgastr.o

ASM := /opt/homebrew/Cellar/nasm/2.15.05/bin/nasm
CC  := /opt/homebrew/Cellar/x86_64-elf-gcc/11.1.0/bin/x86_64-elf-gcc
LD  := /opt/homebrew/Cellar/x86_64-elf-binutils/2.36.1/bin/x86_64-elf-ld

ASMFLAGS := -f elf32
CFLAGS   := -c -Os -std=c99 -m32 -Wall -Wextra -Werror -fno-pie -fno-stack-protector -fomit-frame-pointer -fno-builtin -fno-common -ffreestanding
LDFLAGS  := -s -static -T layout.ld -n -m elf_i386

.PHONY: all clean run

all: clean run

run: $(TARGET)
	qemu-system-x86_64 -drive 'file=$<,format=raw,index=0,media=disk'
clean:
	rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<
%.o: %.c *.h
	$(CC) $(CFLAGS) -o $@ $<
