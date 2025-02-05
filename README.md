# Add cwds (libcwd) support to wayfire.

## Usage

* drop this git submodule in subprojects/aicxx:

```
$ cd subprojects
$ git submodule add https://github.com/CarloWood/wayfire-aicxx.git aicxx
```

* add the following to the root meson.build, right before any other `subdir()` commands:

```
add_project_arguments('-include', 'sys.h', language : 'cpp')
subproject('aicxx')
```

* add `dependency('aicxx')` to all targets that will be linked with wayfire (e.g. plugins)
  as well as to wayfire itself.
