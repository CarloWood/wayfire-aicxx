# Jump through a lot of hoops to link with cwds.

libcwd_r_deps = dependency('libcwd_r', required: true)

# cwds is a cmake project.
cmake = import('cmake')
opt_var = cmake.subproject_options()
opt_var.add_cmake_defines({'CMAKE_BUILD_TYPE': 'Debug'})
opt_var.add_cmake_defines({'CMAKE_VERBOSE_MAKEFILE': true})
aicxx_proj = cmake.subproject('aicxx', options: opt_var)
extra_deps = []

if meson.project_name() == 'wayfire'
  # This block only runs if the parent project is wayfire (not for the plugins).
  extra_deps = [
    libcwd_r_deps,
    dependency('libelf'),
    dependency('libdw'),
    aicxx_proj.dependency('cwds_ObjLib').as_link_whole(),
  ]
endif

# Extract the dependencies from aicxx_proj.
aicxx_interface = declare_dependency(
  compile_args: ['-include', 'sys.h'],
  dependencies: [aicxx_proj.dependency('aicxx_headers'), libcwd_r_deps.partial_dependency(compile_args : true, includes : true)]
)

# Declare the final dependency that combines everything.
aicxx = declare_dependency(
  dependencies: [aicxx_interface, extra_deps]
)

# Targets of the main project (plugins or wayfire), then must use
# dependencies: [aicxx_interface, wayfire], or
# dependencies: [aicxx, libwayfire],
# respectively.
