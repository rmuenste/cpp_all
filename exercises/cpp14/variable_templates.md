# Normalize unsigned image samples

Express type-dependent sample properties as reusable compile-time variables.

## Tasks

1. Define the constexpr variable template is_sample<T>: true for unsigned integral types except
   bool, and false otherwise.

2. Define the constexpr variable template max_sample<T>, of type T, using
   numeric_limits<T>::max(). Use it only with supported sample types.

3. Implement normalize(T sample) returning double in [0, 1], with zero mapping to zero and
   max_sample<T> mapping to one. Use the variable templates rather than repeating their
   expressions.

4. Reject unsupported types inside normalize with static_assert. Perform floating-point
   division so intermediate sample values retain their fractional part.

## Background

- A C++14 variable template declares a family of variables indexed by template arguments;
  name<T> selects one specialization.

- Type traits expose compile-time properties through ::value. numeric_limits<T>::max() gives
  the largest representable value, not a byte count.

- Dividing two integers performs integer division even if the result is subsequently stored in
  a double.

## Checks

Check compile-time type properties and maxima, endpoint normalization, a fractional result, and
rejected types.

Complete [variable_templates.cpp](variable_templates.cpp). The starter includes the tasks, background,
and assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_VARIABLE_TEMPLATES=ON
cmake --build --preset gcc-debug --target exercise_cpp14_variable_templates
ctest --preset gcc-debug -R '^exercise_cpp14_variable_templates$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_VARIABLE_TEMPLATES=OFF
```
