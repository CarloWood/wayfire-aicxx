// Piggyback on cwds

#pragma once

#define NAMESPACE_DEBUG wf::debug
#define NAMESPACE_DEBUG_START namespace wf::debug {
#define NAMESPACE_DEBUG_END }

#include "cwds/debug.h"

// Declare a new debug channel.
#ifdef CWDEBUG
NAMESPACE_DEBUG_CHANNELS_START
extern channel_ct pixdecor;
NAMESPACE_DEBUG_CHANNELS_END
#endif
