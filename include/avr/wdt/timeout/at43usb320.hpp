#pragma once

#include "avr/wdt/detail/global.hpp"
#include "avr/wdt/detail/is_same.hpp"

namespace avr { namespace wdt { 

struct at_8ms_t{};
struct at_16ms_t{};
struct at_34ms_t{};
struct at_66ms_t{};
struct at_131ms_t{};
struct at_262ms_t{};
struct at_524ms_t{};
struct at_1s_t{};

AVR_WDT_INLINE_GLOBAL(at_8ms)
AVR_WDT_INLINE_GLOBAL(at_16ms)
AVR_WDT_INLINE_GLOBAL(at_34ms)
AVR_WDT_INLINE_GLOBAL(at_66ms)
AVR_WDT_INLINE_GLOBAL(at_131ms)
AVR_WDT_INLINE_GLOBAL(at_262ms)
AVR_WDT_INLINE_GLOBAL(at_524ms)
AVR_WDT_INLINE_GLOBAL(at_1s)

template<typename Timeout>
struct is_timeout {
    static constexpr bool value =
        detail::is_same<Timeout, at_8ms_t>::value
        | detail::is_same<Timeout, at_16ms_t>::value
        | detail::is_same<Timeout, at_34ms_t>::value
        | detail::is_same<Timeout, at_66ms_t>::value
        | detail::is_same<Timeout, at_131ms_t>::value
        | detail::is_same<Timeout, at_262ms_t>::value
        | detail::is_same<Timeout, at_524ms_t>::value
        | detail::is_same<Timeout, at_1s_t>::value
        ;
};
             
}}
