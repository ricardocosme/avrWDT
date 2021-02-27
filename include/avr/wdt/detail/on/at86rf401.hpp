#pragma once

#include "avr/wdt/assume_atomic.hpp"
#include "avr/wdt/timeout.hpp"

#include <avr/io.hpp>
#include <avr/interrupt.hpp>

namespace avr { namespace wdt { namespace detail {

using namespace avr::io;

inline void on_impl(uint8_t enable, at_2K_t) noexcept
{ detail::_wdtcr = enable; }

inline void on_impl(uint8_t enable, at_4K_t) noexcept
{ detail::_wdtcr = enable | wdp0; }

inline void on_impl(uint8_t enable, at_8K_t) noexcept
{ detail::_wdtcr = enable | wdp1; }

inline void on_impl(uint8_t enable, at_16K_t) noexcept
{ detail::_wdtcr = enable | wdp1 | wdp0; }

inline void on_impl(uint8_t enable, at_32K_t) noexcept
{ detail::_wdtcr = enable | wdp2; }

inline void on_impl(uint8_t enable, at_64K_t) noexcept
{ detail::_wdtcr = enable | wdp2 | wdp0; }

inline void on_impl(uint8_t enable, at_128K_t) noexcept
{ detail::_wdtcr = enable | wdp2 | wdp1; }

inline void on_impl(uint8_t enable, at_256K_t) noexcept
{ detail::_wdtcr = enable | wdp2 | wdp1 | wdp0; }

template<typename Timeout>
inline void on(uint8_t enable, Timeout timeout) noexcept {
    asm("wdr");
//optimize when the device doesn't require timed sequence
#if AVR_IO_WDT_NEEDS_ON_TIMED_SEQ
    //start timed sequence
    detail::_wdtcr.set(detail::_wdce, wde);
#endif
    on_impl(enable, timeout);
}

template<typename Timeout>
inline void on(uint8_t enable, Timeout timeout, dont_assume_atomic_t) noexcept {
    auto s = avr::interrupt::make_atomic();
    on(enable, timeout);
}

template<typename Timeout>
inline void on(uint8_t enable, Timeout timeout, assume_atomic_t) noexcept
{ on(enable, timeout); }

}}}
