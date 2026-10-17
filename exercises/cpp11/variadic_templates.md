# Write a structured log line

Build a tiny logging helper that accepts heterogeneous streamable fields.

## Tasks

1. Implement log_line(ostream&, const Args&...) with a variadic template and C++11 recursive parameter-pack expansion.
2. Write fields in argument order, separated by one space, without a leading or trailing space. End every call with a newline.
3. Support zero arguments, which writes only a newline. Add recursive helper overloads as needed; do not use fold expressions.

## Checks

Check mixed field types, one field, no fields, and consecutive calls on one stream.

Complete [variadic_templates.cpp](variadic_templates.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_VARIADIC_TEMPLATES=ON
cmake --build --preset gcc-debug --target exercise_cpp11_variadic_templates
ctest --preset gcc-debug -R '^exercise_cpp11_variadic_templates$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_VARIADIC_TEMPLATES=OFF
```
