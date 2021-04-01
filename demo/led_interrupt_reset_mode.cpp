#include <avr/io.hpp>
#include <avr/wdt.hpp>
#define F_CPU 1200000
#include <util/delay.h>

using namespace avr::io;
using namespace avr::wdt;
using namespace avr;

/** Use the watchdog timer in interrupt and reset mode to blink a LED
    connected to the pin PB0
 */

static auto& led{pb0};

AVRINT_WDT() {
    for(uint8_t i{0}; i < 7; ++i) {
        led.toggle();
        _delay_ms(30);
    }
}

int main() {
    led.out(); /** setup PB0 as an output pin */
    
    /** enable the WDT */
    wdt::on(timeout::at_1s, mode::interrupt_reset, atomic_precondition::yes);
    
    interrupt::on();
    _delay_ms(500);
    while(true)
        led.high();
}

/** [1] We are using 'atomic_precondition::yes' to save some bytes and
    cycles because this program doesn't use interrupts.
 */
