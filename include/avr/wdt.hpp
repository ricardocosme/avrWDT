#pragma once

#include "avr/wdt/assume_atomic.hpp"
#include "avr/wdt/detail/bits.hpp"
#include "avr/wdt/detail/off.hpp"
#include "avr/wdt/detail/on.hpp"
#include "avr/wdt/detail/type_traits/enable_if.hpp"
#include "avr/wdt/timeout.hpp"

#include <avr/io.hpp>

namespace avr { namespace wdt {

[[gnu::always_inline]] inline void reset() noexcept
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

    timeout: one of the possible timeouts defined at
    'avr/wdt/timeout.hpp'.

    mode_: watchdor timer mode. Take a look at the enum class 'mode'.

    [optional] assume_atomic_: policy to define if the operation to
    enable the WDT assumes by precondition that it can't be
    interrupted. The default behaviour is disable interrupts and
    restore the initial state of SREG at the end of the operation. If
    'assume_atomic' is passed then the operation assumes that the
    caller have disabled interrupts or interrupts aren't used.

    Example:

      //Turn on the watchdog in Interrupt mode with a timeout of 500ms
      on(at_500ms, mode::interrupt);
   
      //Turn on the watchdog in System Reset mode with a timeout of 4s
      on(at_4s);
   
      //Turn on the watchdog in System Reset mode with a timeout of 1s
      //assuming that interrupts are disabled before the call to on()
      on(at_1s, mode::interrupt, assume_atomic);
 */
template<typename Timeout, typename AssumeAtomic = dont_assume_atomic_t>
AVR_WDT_REQUIRES_TIMEOUT
inline void on(Timeout timeout,
               mode mode_ = mode::reset,
               AssumeAtomic assume_atomic_ = AssumeAtomic{}) noexcept
{
    uint8_t enable;
    if(mode_ == mode::reset) enable = avr::io::wde.bv();
#if AVR_IO_WDT_HAS_INTERRUPT_MODE
    else if(mode_ == mode::interrupt) enable = detail::_wdie.bv();
    else enable = avr::io::wde.bv() | detail::_wdie.bv();
#endif
    detail::on(enable, timeout, assume_atomic_);
}

/** Disable watchdog timer 

    [optional] assume_atomic_: policy to define if the operation to
    enable the WDT assumes by precondition that it can't be
    interrupted. The default behaviour is disable interrupts and
    restore the initial state of SREG at the end of the operation. If
    'assume_atomic' is passed then the operation assumes that the
    caller have disabled interrupts or interrupts aren't used.
*/
template<typename AssumeAtomic = dont_assume_atomic_t>
inline void off(AssumeAtomic assume_atomic_ = AssumeAtomic{}) noexcept
{ detail::off(assume_atomic_); }

}}
