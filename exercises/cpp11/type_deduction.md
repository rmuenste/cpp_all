# Look up and edit service settings

Write a generic settings lookup that preserves references and constness.

## Tasks

1. Implement lookup(settings, key) as a function template using a C++11 trailing return type with decltype(settings.at(key)). Let at() report missing keys.
2. In main(), declare snapshot with auto so changing it does not edit settings.
3. Declare live with auto& so changing it edits settings in place.
4. Declare read_only using decltype((read_view.at("workers"))) and initialize it through lookup(read_view, "workers"). It must alias the stored value.

## Checks

The static assertions check exact types; runtime assertions check copying, aliasing, and missing-key handling.

Complete [type_deduction.cpp](type_deduction.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_TYPE_DEDUCTION=ON
cmake --build --preset gcc-debug --target exercise_cpp11_type_deduction
ctest --preset gcc-debug -R '^exercise_cpp11_type_deduction$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_TYPE_DEDUCTION=OFF
```
