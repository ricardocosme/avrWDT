#include <avr/io.hpp>
#include <avr/wdt.hpp>
#define F_CPU 1200000
#include <util/delay.h>

using namespace avr::io;
using namespace avr::wdt;
using namespace avr;

/** Use the watchdog timer in interrupt mode to blink a LED connected
    to the pin PB0
 */

static auto& led{pb0};

/** ISR to blink a LED at each 4s. */
AVRINT_WDT() {
    for(uint8_t i{}; i < 7; ++i) {
        led.toggle();
        _delay_ms(50);
    }
}

int main() {
    led.out(); /** setup PB0 as an output pin */

    /** enable the WDT [1] */
    wdt::on(timeout::at_2s, mode::interrupt, assume_atomic);
    
    interrupt::on(); /** enable interrupts */
    while(true)
        led.high();
}

/** [1] We are using 'assume_atomic' here because we don't need
    interrupts before the call that enables the WDT, so we can save
    some bytes using the policy and enabling the interrupts only after
    the call to 'on()'.
 */
