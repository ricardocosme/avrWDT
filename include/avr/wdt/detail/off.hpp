#pragma once

#include "avr/wdt/assume_atomic.hpp"
#include "avr/wdt/detail/bits.hpp"

#include <avr/io.hpp>
#include <avr/interrupt.hpp>

namespace avr { namespace wdt { namespace detail {

[[gnu::always_inline]]
inline void off() noexcept {
    using namespace avr::io;
    asm("wdr");
#if AVR_IO_WDT_HAS_WDRF
    detail::_mcusr.clear(wdrf);
#endif
#if AVR_IO_WDT_NEEDS_OFF_TIMED_SEQ
    detail::_wdtcr.set(detail::_wdce, wde);
#endif
    detail::_wdtcr = 0x00;
}

inline void off(dont_assume_atomic_t) noexcept {
    avr::interrupt::atomic s;
    off();
}

inline void off(assume_atomic_t) noexcept
{ off(); }

}}}
