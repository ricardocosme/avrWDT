#pragma once

#include "avr/wdt/detail/global.hpp"
#include "avr/wdt/detail/type_traits/is_same.hpp"

namespace avr { namespace wdt { 

struct at_16ms_t{};
struct at_32ms_t{};
struct at_64ms_t{};
struct at_125ms_t{};
struct at_250ms_t{};
struct at_500ms_t{};
struct at_1s_t{};
struct at_2s_t{};
struct at_4s_t{};
struct at_8s_t{};

AVR_WDT_INLINE_GLOBAL(at_16ms)
AVR_WDT_INLINE_GLOBAL(at_32ms)
AVR_WDT_INLINE_GLOBAL(at_64ms)
AVR_WDT_INLINE_GLOBAL(at_125ms)
AVR_WDT_INLINE_GLOBAL(at_250ms)
AVR_WDT_INLINE_GLOBAL(at_500ms)
AVR_WDT_INLINE_GLOBAL(at_1s)
AVR_WDT_INLINE_GLOBAL(at_2s)
AVR_WDT_INLINE_GLOBAL(at_4s)
AVR_WDT_INLINE_GLOBAL(at_8s)

template<typename Timeout>
struct is_timeout {
    static constexpr bool value =
        detail::is_same<Timeout, at_16ms_t>::value
        | detail::is_same<Timeout, at_32ms_t>::value
        | detail::is_same<Timeout, at_64ms_t>::value
        | detail::is_same<Timeout, at_125ms_t>::value
        | detail::is_same<Timeout, at_250ms_t>::value
        | detail::is_same<Timeout, at_500ms_t>::value
        | detail::is_same<Timeout, at_1s_t>::value
        | detail::is_same<Timeout, at_2s_t>::value
        | detail::is_same<Timeout, at_4s_t>::value
        | detail::is_same<Timeout, at_8s_t>::value
        ;
};
             
}}
