#pragma once

#include "avr/wdt/detail/type_traits/integral_constant.hpp"

namespace avr { namespace wdt { namespace detail {

template<typename T1, typename T2>
struct is_same : false_type {};

template<typename T1>
struct is_same<T1, T1> : true_type {};

}}}
