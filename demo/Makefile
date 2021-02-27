avr_io_inc=../../avrIO/include
avr_int_inc=../../avrINT/include
mcu=attiny13a
device=t13

all: led.elf led_reset_mode.elf led_interrupt_reset_mode.elf

%.elf: %.cpp
	avr-g++ -std=c++11 -Os -mmcu=$(mcu) -I../include \
	-I$(avr_io_inc) -I$(avr_int_inc) -o $@ $<
	avr-size $@

%.s: %.elf
	avr-objdump -d $< > $@
	cat $@

.PHONY: flash clean

flash-%: %.elf
	avrdude -p $(device) -c usbasp -P usb flash -U flash:w:$<

clean:
	rm -f *.elf *.s
