# Order two dispatch queues with one comparator

Reuse one sorting rule across queue entries whose keys have different types.

## Tasks

1. In main(), define by_priority as one generic lambda with two const auto& parameters.

2. Order higher priorities first. For equal priorities, order smaller keys first. Comparing an
   entry with itself must return false.

3. Use the same lambda with both provided sorts. Keep the input structures and their field
   types unchanged.

## Background

- Each auto parameter of a C++14 generic lambda is independently deduced, as if its call
  operator were a function template.

- A sorting comparator describes a strict ordering; it means "comes before", not "comes before
  or equals".

## Checks

Check priority order, numeric and string tie-breakers, equivalent entries, and an empty queue.

Complete [generic_lambdas.cpp](generic_lambdas.cpp). The starter includes the tasks, background,
and assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_GENERIC_LAMBDAS=ON
cmake --build --preset gcc-debug --target exercise_cpp14_generic_lambdas
ctest --preset gcc-debug -R '^exercise_cpp14_generic_lambdas$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_GENERIC_LAMBDAS=OFF
```
