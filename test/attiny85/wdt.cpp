#include <avr/wdt.hpp>
using namespace avr::wdt;

namespace reset {
void on_16ms()
{ on(timeout::at_16ms, mode::reset, atomic_precondition::yes); }
void on_32ms()
{ on(timeout::at_32ms, mode::reset, atomic_precondition::yes); }
void on_64ms()
{ on(timeout::at_64ms, mode::reset, atomic_precondition::yes); }
void on_125ms()
{ on(timeout::at_125ms, mode::reset, atomic_precondition::yes); }
void on_250ms()
{ on(timeout::at_250ms, mode::reset, atomic_precondition::yes); }
void on_500ms()
{ on(timeout::at_500ms, mode::reset, atomic_precondition::yes); }
void on_1s()
{ on(timeout::at_1s, mode::reset, atomic_precondition::yes); }
void on_2s()
{ on(timeout::at_2s, mode::reset, atomic_precondition::yes); }
void on_4s()
{ on(timeout::at_4s, mode::reset, atomic_precondition::yes); }
void on_8s()
{ on(timeout::at_8s, mode::reset, atomic_precondition::yes); }
}

namespace interrupt {
void on_16ms()
{ on(timeout::at_16ms, mode::interrupt, atomic_precondition::yes); }
void on_32ms()
{ on(timeout::at_32ms, mode::interrupt, atomic_precondition::yes); }
void on_64ms()
{ on(timeout::at_64ms, mode::interrupt, atomic_precondition::yes); }
void on_125ms()
{ on(timeout::at_125ms, mode::interrupt, atomic_precondition::yes); }
void on_250ms()
{ on(timeout::at_250ms, mode::interrupt, atomic_precondition::yes); }
void on_500ms()
{ on(timeout::at_500ms, mode::interrupt, atomic_precondition::yes); }
void on_1s()
{ on(timeout::at_1s, mode::interrupt, atomic_precondition::yes); }
void on_2s()
{ on(timeout::at_2s, mode::interrupt, atomic_precondition::yes); }
void on_4s()
{ on(timeout::at_4s, mode::interrupt, atomic_precondition::yes); }
void on_8s()
{ on(timeout::at_8s, mode::interrupt, atomic_precondition::yes); }
}

namespace interrupt_reset {
void on_16ms()
{ on(timeout::at_16ms, mode::interrupt_reset, atomic_precondition::yes); }
void on_32ms()
{ on(timeout::at_32ms, mode::interrupt_reset, atomic_precondition::yes); }
void on_64ms()
{ on(timeout::at_64ms, mode::interrupt_reset, atomic_precondition::yes); }
void on_125ms()
{ on(timeout::at_125ms, mode::interrupt_reset, atomic_precondition::yes); }
void on_250ms()
{ on(timeout::at_250ms, mode::interrupt_reset, atomic_precondition::yes); }
void on_500ms()
{ on(timeout::at_500ms, mode::interrupt_reset, atomic_precondition::yes); }
void on_1s()
{ on(timeout::at_1s, mode::interrupt_reset, atomic_precondition::yes); }
void on_2s()
{ on(timeout::at_2s, mode::interrupt_reset, atomic_precondition::yes); }
void on_4s()
{ on(timeout::at_4s, mode::interrupt_reset, atomic_precondition::yes); }
void on_8s()
{ on(timeout::at_8s, mode::interrupt_reset, atomic_precondition::yes); }
}

void on_dont_assume_atomic()
{ on(timeout::at_16ms, mode::reset); }

void off_assume_atomic()
{ avr::wdt::off(atomic_precondition::yes); }

void off_dont_assume_atomic()
{ avr::wdt::off(); }

void wdt_reset()
{ avr::wdt::reset(); }
