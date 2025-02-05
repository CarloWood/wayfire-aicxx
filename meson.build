# Jump through a lot of hoops to link with cwds.
project('aicxx')

libcwd_r_deps = dependency('libcwd_r', required: true)
extra_deps = libcwd_r_deps.partial_dependency(compile_args : true, includes : true)

if meson.project_name() == 'wayfire'
  # This block only runs if the parent project is wayfire (not for the plugins).

  # cwds is a cmake project.
  cmake = import('cmake')
  aicxx_proj = cmake.subproject('aicxx')

  extra_deps = [
    libcwd_r_deps,
    dependency('libelf'),
    dependency('libdw'),
    aicxx_proj.dependency('cwds_ObjLib').as_link_whole(),
  ]
endif

# Declare the final dependency that combines everything.
aicxx_deps = declare_dependency(
  include_directories: '.',         # Needed for -include 'sys.h' and #include "debug.h".
  dependencies: extra_deps
)

# Make this a dependency of the 'aicxx' "project".
meson.override_dependency('aicxx', aicxx_deps)

# Targets of the main project (plugins or wayfire), then must use
# dependencies: [dependency('aicxx'), wayfire], or
# dependencies: [dependency('aicxx'), libwayfire],
# respectively.
