tests=test/attiny13a test/attiny85 test/atmega328p

all: demo test
test: $(tests)

.PHONY: demo $(tests)
demo $(tests):
	make -C $@
