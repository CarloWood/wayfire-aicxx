cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0126 NEW)
cmake_policy(SET CMP0156 NEW)
cmake_policy(SET CMP0179 NEW)
project(aicxx_wrapper)
set(top_srcdir "${CMAKE_CURRENT_SOURCE_DIR}")

# Add the root directory to the module path so it can find cwm4/cmake.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${top_srcdir}/cwm4/cmake")
include(AICxxProject)

# Now include the actual cwds project.
include(AICxxSubmodules)

# We need cwds to be relocatable.
set_property(TARGET cwds_ObjLib PROPERTY POSITION_INDEPENDENT_CODE ON)

# Put `init()` and `init_thread()` in the right namespace.
target_compile_definitions(cwds_ObjLib
  PUBLIC
    "NAMESPACE_DEBUG=wf::debug"
    "NAMESPACE_DEBUG_START=namespace wf::debug {"
    "NAMESPACE_DEBUG_END=}"
)

# Specify the interface for this 'aicxx_wrapper' "project".
add_library(aicxx_headers INTERFACE)
target_include_directories(aicxx_headers INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)
