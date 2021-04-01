#pragma once

namespace avr { namespace wdt {

/** Policy to define if the operation to enable the WDT assumes by
    precondition that it can't be interrupted. The default behaviour
    is disable interrupts and restore the initial state of SREG at the
    end of the operation. If 'atomic_precondition::yes' is passed then
    the operation assumes that the caller have disabled interrupts or
    interrupts aren't being used.
*/
enum class atomic_precondition {
    yes,
    no,
};

}}
