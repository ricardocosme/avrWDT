#pragma once

#include "avr/wdt/detail/global.hpp"
#include "avr/wdt/detail/is_same.hpp"

namespace avr { namespace wdt { 

struct at_14ms_t{};
struct at_28ms_t{};
struct at_56ms_t{};
struct at_110ms_t{};
struct at_220ms_t{};
struct at_450ms_t{};
struct at_900ms_t{};
struct at_1800ms_t{};

AVR_WDT_INLINE_GLOBAL(at_14ms)
AVR_WDT_INLINE_GLOBAL(at_28ms)
AVR_WDT_INLINE_GLOBAL(at_56ms)
AVR_WDT_INLINE_GLOBAL(at_110ms)
AVR_WDT_INLINE_GLOBAL(at_220ms)
AVR_WDT_INLINE_GLOBAL(at_450ms)
AVR_WDT_INLINE_GLOBAL(at_900ms)
AVR_WDT_INLINE_GLOBAL(at_1800ms)

template<typename Timeout>
struct is_timeout {
    static constexpr bool value =
        detail::is_same<Timeout, at_14ms_t>::value
        | detail::is_same<Timeout, at_28ms_t>::value
        | detail::is_same<Timeout, at_56ms_t>::value
        | detail::is_same<Timeout, at_110ms_t>::value
        | detail::is_same<Timeout, at_220ms_t>::value
        | detail::is_same<Timeout, at_450ms_t>::value
        | detail::is_same<Timeout, at_900ms_t>::value
        | detail::is_same<Timeout, at_1800ms_t>::value
        ;
};
             
}}
