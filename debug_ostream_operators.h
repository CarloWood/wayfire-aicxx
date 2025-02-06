#include "cwds/debug_ostream_operators.h"

#define AI_CASE_RETURN(x) do { case x: return #x; } while(0)

#include "wayland-server-protocol.h"
inline char const* to_string(wl_pointer_button_state state)
{
  switch (state)
  {
    AI_CASE_RETURN(WL_POINTER_BUTTON_STATE_RELEASED);
    AI_CASE_RETURN(WL_POINTER_BUTTON_STATE_PRESSED);
  }
  return "Unknown wl_pointer_button_state";
}

inline std::ostream& operator<<(std::ostream& os, wl_pointer_button_state state)
{
  return os << to_string(state);
}

#include "wlr/types/wlr_pointer.h"
inline std::ostream& operator<<(std::ostream& os, wlr_pointer_button_event const& ev)
{
  os << '{';
  os << "pointer:" << ev.pointer <<
    ", time_msec:" << ev.time_msec <<
    ", button:" << ev.button <<
    ", state:" << ev.state;
  os << '}';
  return os;
}

// Plugin specific debug ostream operators should go here.
#include "../../aicxx/debug_ostream_operators.h"
