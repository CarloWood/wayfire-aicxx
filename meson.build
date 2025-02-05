# Jump through a lot of hoops to link with cwds.
project('aicxx')

# aicxx requires sys.h to be included as very first header file.
add_project_arguments('-include', 'sys.h', language : 'cpp')
extra_deps = []

if meson.project_name() == 'wayfire'
  # This block only runs if the parent project is wayfire (not for the plugins).

  # cwds is a cmake project.
  cmake = import('cmake')
  aicxx_proj = cmake.subproject('aicxx')

  extra_deps = [
    dependency('libcwd_r', required: true),
    dependency('libelf'),
    dependency('libdw'),
    aicxx_proj.dependency('cwds_ObjLib').as_link_whole(),
  ]
endif

# Declare the final dependency that combines everything.
aicxx_dep = declare_dependency(
  include_directories: '.',         # Needed for -include 'sys.h' and #include "debug.h".
  dependencies: extra_deps
)

# Make this a dependency of the 'aicxx' "project".
meson.override_dependency('aicxx', aicxx_dep)

# Targets of the main project (plugins or wayfire), then must use
# dependencies: [dependency('aicxx'), wayfire], or
# dependencies: [dependency('aicxx'), libwayfire],
# respectively.
