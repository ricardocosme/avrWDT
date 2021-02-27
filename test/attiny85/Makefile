avr_io_inc=../../../avrIO/include
avr_int_inc=../../../avrINT/include
mcu=attiny85
stdcxx=c++11

all: wdt.diff

%.diff: wdt.hex expected_wdt.hex
	diff wdt.hex expected_wdt.hex > wdt.diff

%.hex: %.o
	avr-objcopy -O ihex $< $@

%.s: %.o
	avr-objdump -d $< > $@
	cat $@

%.o: %.cpp
	avr-g++ -std=$(stdcxx) -Os -mmcu=$(mcu) -Wall -I../../include \
	-I$(avr_io_inc) -I$(avr_int_inc) -c $<

.PHONY: clean
clean:
	rm -f *.hex *.o *.s *.diff

