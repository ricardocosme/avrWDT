#include <avr/wdt.hpp>
using namespace avr::wdt;

namespace reset {
void on_16ms()
{ on(at_16ms, mode::reset, assume_atomic); }
void on_32ms()
{ on(at_32ms, mode::reset, assume_atomic); }
void on_64ms()
{ on(at_64ms, mode::reset, assume_atomic); }
void on_125ms()
{ on(at_125ms, mode::reset, assume_atomic); }
void on_250ms()
{ on(at_250ms, mode::reset, assume_atomic); }
void on_500ms()
{ on(at_500ms, mode::reset, assume_atomic); }
void on_1s()
{ on(at_1s, mode::reset, assume_atomic); }
void on_2s()
{ on(at_2s, mode::reset, assume_atomic); }
void on_4s()
{ on(at_4s, mode::reset, assume_atomic); }
void on_8s()
{ on(at_8s, mode::reset, assume_atomic); }
}

namespace interrupt {
void on_16ms()
{ on(at_16ms, mode::interrupt, assume_atomic); }
void on_32ms()
{ on(at_32ms, mode::interrupt, assume_atomic); }
void on_64ms()
{ on(at_64ms, mode::interrupt, assume_atomic); }
void on_125ms()
{ on(at_125ms, mode::interrupt, assume_atomic); }
void on_250ms()
{ on(at_250ms, mode::interrupt, assume_atomic); }
void on_500ms()
{ on(at_500ms, mode::interrupt, assume_atomic); }
void on_1s()
{ on(at_1s, mode::interrupt, assume_atomic); }
void on_2s()
{ on(at_2s, mode::interrupt, assume_atomic); }
void on_4s()
{ on(at_4s, mode::interrupt, assume_atomic); }
void on_8s()
{ on(at_8s, mode::interrupt, assume_atomic); }
}

namespace interrupt_reset {
void on_16ms()
{ on(at_16ms, mode::interrupt_reset, assume_atomic); }
void on_32ms()
{ on(at_32ms, mode::interrupt_reset, assume_atomic); }
void on_64ms()
{ on(at_64ms, mode::interrupt_reset, assume_atomic); }
void on_125ms()
{ on(at_125ms, mode::interrupt_reset, assume_atomic); }
void on_250ms()
{ on(at_250ms, mode::interrupt_reset, assume_atomic); }
void on_500ms()
{ on(at_500ms, mode::interrupt_reset, assume_atomic); }
void on_1s()
{ on(at_1s, mode::interrupt_reset, assume_atomic); }
void on_2s()
{ on(at_2s, mode::interrupt_reset, assume_atomic); }
void on_4s()
{ on(at_4s, mode::interrupt_reset, assume_atomic); }
void on_8s()
{ on(at_8s, mode::interrupt_reset, assume_atomic); }
}

void on_dont_assume_atomic()
{ on(at_16ms, mode::reset); }

void off_assume_atomic()
{ avr::wdt::off(assume_atomic); }

void off_dont_assume_atomic()
{ avr::wdt::off(); }

void wdt_reset()
{ avr::wdt::reset(); }
