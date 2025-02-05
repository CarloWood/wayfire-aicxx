# Add cwds (libcwd) support to wayfire.

## Usage

* drop this git submodule in subprojects
* add `subproject('aicxx')` to the root meson.build
* add `dependency('aicxx')` to all targets that will be linked with wayfire (e.g. plugins)
  as well as to wayfire itself.

