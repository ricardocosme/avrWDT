#pragma once

#include "avr/wdt/detail/global.hpp"
#include "avr/wdt/detail/is_same.hpp"

namespace avr { namespace wdt { 

struct at_47ms_t{};
struct at_94ms_t{};
struct at_190ms_t{};
struct at_380ms_t{};
struct at_750ms_t{};
struct at_1500ms_t{};
struct at_3s_t{};
struct at_6s_t{};

AVR_WDT_INLINE_GLOBAL(at_47ms)
AVR_WDT_INLINE_GLOBAL(at_94ms)
AVR_WDT_INLINE_GLOBAL(at_190ms)
AVR_WDT_INLINE_GLOBAL(at_380ms)
AVR_WDT_INLINE_GLOBAL(at_750ms)
AVR_WDT_INLINE_GLOBAL(at_1500ms)
AVR_WDT_INLINE_GLOBAL(at_3s)
AVR_WDT_INLINE_GLOBAL(at_6s)

template<typename Timeout>
struct is_timeout {
    static constexpr bool value =
        detail::is_same<Timeout, at_47ms_t>::value
        | detail::is_same<Timeout, at_94ms_t>::value
        | detail::is_same<Timeout, at_190ms_t>::value
        | detail::is_same<Timeout, at_380ms_t>::value
        | detail::is_same<Timeout, at_750ms_t>::value
        | detail::is_same<Timeout, at_1500ms_t>::value
        | detail::is_same<Timeout, at_3s_t>::value
        | detail::is_same<Timeout, at_6s_t>::value
        ;
};
             
}}
