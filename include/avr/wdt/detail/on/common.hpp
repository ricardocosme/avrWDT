#pragma once

#include "avr/wdt/atomic_precondition.hpp"
#include "avr/wdt/timeout.hpp"

#include <avr/interrupt.hpp>
#include <avr/io.hpp>

namespace avr { namespace wdt { namespace detail {

using namespace avr::io;

inline void on(uint8_t enable, timeout timeout_) {
    asm("wdr");
//optimize when the device doesn't require timed sequence
#if AVR_IO_WDT_NEEDS_ON_TIMED_SEQ
    //start timed sequence
    // detail::_wdtcr.set(detail::_wdce, wde);
    detail::_wdtcr = detail::_wdce | wde;
#endif
    if(timeout::at_16ms == timeout_) detail::_wdtcr = enable;
    else if(timeout::at_32ms == timeout_)
        detail::_wdtcr = enable | wdp0;
    else if(timeout::at_64ms == timeout_)
        detail::_wdtcr = enable | wdp1;
    else if(timeout::at_125ms == timeout_)
        detail::_wdtcr = enable | wdp1 | wdp0;
    else if(timeout::at_250ms == timeout_)
        detail::_wdtcr = enable | wdp2;
    else if(timeout::at_500ms == timeout_)
        detail::_wdtcr = enable | wdp2 | wdp0;
    else if(timeout::at_1s == timeout_)
        detail::_wdtcr = enable | wdp2 | wdp1;
    else if(timeout::at_2s == timeout_)
        detail::_wdtcr = enable | wdp2 | wdp1 | wdp0;
#if AVR_IO_WDT_HAS_WDP3
    else if(timeout::at_4s == timeout_)
        detail::_wdtcr = enable | wdp3;
    else if(timeout::at_8s == timeout_)
        detail::_wdtcr = enable | wdp3 | wdp0;
#endif
}

inline void on(uint8_t enable, timeout timeout_, atomic_precondition policy) {
    if(policy == atomic_precondition::no) {
        interrupt::atomic<> s;
        on(enable, timeout_);
    } else
        on(enable, timeout_);
}

}}}
