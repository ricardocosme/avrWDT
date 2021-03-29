#include <avr/io.hpp>
#include <avr/wdt.hpp>
#define F_CPU 1200000
#include <util/delay.h>

using namespace avr::io;
using namespace avr::wdt;
using namespace avr;

/** Use the watchdog timer in reset mode to blink a LED connected
    to the pin PB0
 */

static auto& led{pb0};

int main() {
    led.out(); /** setup PB0 as an output pin */
    wdt::on(at_1s, mode::reset, assume_atomic); /** enable the WDT */
    _delay_ms(500);
    while(true)
        led.high();
}

/** [1] We are using 'assume_atomic' to save some bytes and cycles
    because this program doesn't use interruptions.
 */