#pragma once

#include "avr/wdt/detail/bits.hpp"
#include "avr/wdt/detail/enable_if.hpp"
#include "avr/wdt/detail/on.hpp"
#include "avr/wdt/interruptible.hpp"
#include "avr/wdt/timeout.hpp"

#include <avr/io.hpp>
#include <avr/interrupt.hpp>

namespace avr { namespace wdt {

/** Watchdog timer mode

    reset: System Reset mode
    interrupt: Interrupt mode
    interrupt_reset: Interrupt and System Reset mode
 */
enum class mode {
    reset,
    interrupt,
    interrupt_reset
};

/** Enable watchdog timer

    timeout: one of the possible timeouts defined at
    'avr/wdt/timeout.hpp'.

    mode_: watchdor timer mode. Take a look at the enum class mode.

    [optional] interruptible_: policy to define if the operation to
    enable the WDT assumes by precondition that it can't be
    interrupted. The default behaviour is disable interrupts and
    restore the initial state of SREG at the end of the operation. If
    'non_interruptible' is passed then the operation assumes that the
    caller have disabled interrupts or interrupts aren't be used.

    Example:

      //Turn on the watchdog in Interrupt mode with a timeout of 500ms
      on(at_500ms, mode::interrupt);
   
      //Turn on the watchdog in System Reset mode with a timeout of 4s
      on(at_4s);
   
      //Turn on the watchdog in System Reset mode with a timeout of 1s
      //assuming that interrupts were disabled before the call to on()
      on(at_1s, mode::interrupt, non_interruptible);
 */
template<typename Timeout, typename Interruptible = interruptible_t,
         typename = detail::enable_if<is_timeout<Timeout>::value> >
inline void on(Timeout timeout,
               mode mode_ = mode::reset,
               Interruptible interruptible_ = Interruptible{}) noexcept
{
    uint8_t enable;
    if(mode_ == mode::reset) enable = avr::io::wde.bv();
    else if(mode_ == mode::interrupt) enable = detail::_wdie.bv();
    else enable = avr::io::wde.bv() | detail::_wdie.bv();
    detail::on(enable, timeout, interruptible_);
}

}}
