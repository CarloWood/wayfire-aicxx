# Add cwds (libcwd) support to wayfire.

## Usage

* drop this git submodule in subprojects/aicxx:

```
$ cd subprojects
$ git submodule add https://github.com/CarloWood/wayfire-aicxx.git aicxx
$ cd aicxx
$ git submodule update --init
```

* Create a directory aicxx in the root of the project and link meson.build.

$ mkdir aicxx
$ ln -s subprojects/aicxx/meson.build

* add the following to the root meson.build, right before any other `subdir()` commands:

```
subdir('aicxx')
```

* add `aicxx` as dependency to all targets that will be linked with wayfire (e.g. plugins)
  as well as to wayfire itself.
