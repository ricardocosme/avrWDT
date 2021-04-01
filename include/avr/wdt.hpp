#pragma once

#include "avr/wdt/atomic_precondition.hpp"
#include "avr/wdt/detail/bits.hpp"
#include "avr/wdt/detail/off.hpp"
#include "avr/wdt/detail/on.hpp"
#include "avr/wdt/timeout.hpp"

#include <avr/io.hpp>

namespace avr { namespace wdt {

[[gnu::always_inline]] inline void reset() 
{ asm("wdr"); }

/** Watchdog timer mode

    reset: System Reset mode
    interrupt: Interrupt mode
    interrupt_reset: Interrupt and System Reset mode
 */
enum class mode {
    reset,
#if AVR_IO_WDT_HAS_INTERRUPT_MODE
    interrupt,
    interrupt_reset,
#endif
};

/** Enable watchdog timer

    timeout_: one of the possible timeouts defined at
    'avr/wdt/timeout.hpp'.

    mode_: watchdor timer mode. Take a look at the enum class 'mode'.

    [optional] policy: see 'avr/wdt/atomic_precondition.hpp'.

    Example:

      //Turn on the watchdog in Interrupt mode with a timeout of 500ms
      on(timeout::at_500ms, mode::interrupt);
   
      //Turn on the watchdog in System Reset mode with a timeout of 4s
      on(timeout::at_4s);
   
      //Turn on the watchdog in System Reset mode with a timeout of 1s
      //assuming that interrupts are disabled before the call to on()
      on(timeout::at_1s, mode::interrupt, atomic_precondition::yes);
 */
inline void on(timeout timeout_,
               mode mode_ = mode::reset,
               atomic_precondition policy = atomic_precondition::no) 
{
    uint8_t enable;
    if(mode_ == mode::reset) enable = avr::io::wde.bv();
#if AVR_IO_WDT_HAS_INTERRUPT_MODE
    else if(mode_ == mode::interrupt) enable = detail::_wdie.bv();
    else enable = avr::io::wde.bv() | detail::_wdie.bv();
#endif
    detail::on(enable, timeout_, policy);
}

/** Disable watchdog timer 

    [optional] policy: see 'avr/wdt/atomic_precondition.hpp'.
*/
inline void off(atomic_precondition policy = atomic_precondition::no) 
{ detail::off(policy); }

}}
