# Count calls without changing their results

Wrap an operation with a call counter while preserving its exact return type.

## Tasks

1. Define counted_call(size_t& calls, F&& operation) as a function template returning
   decltype(auto).

2. Increment calls once before invoking the operation, including when the operation throws.

3. Invoke the callable with its original value category and return its result without copying
   referenced objects. Support values, mutable references, const references, and void.

4. Do not catch exceptions inside the wrapper or return references to local variables.

## Background

- auto return deduction normally drops references; decltype(auto) uses the decltype rules on
  the returned expression instead.

- An unparenthesized name has different decltype rules from a general expression. References do
  not extend the referred object's lifetime.

- A return statement may return a void expression from a void-returning function. Forwarding-
  reference deduction and std::forward apply to callables too.

- A trailing & or && on a member function restricts calls to lvalue or rvalue objects
  respectively. The RvalueOnly fixture uses this to check forwarding; you do not need
  to change it.

## Checks

Check exact return types, aliasing, value and void results, callable forwarding, and counting
an operation that throws.

Complete [decltype_auto.cpp](decltype_auto.cpp). The starter includes the tasks, background,
and assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_DECLTYPE_AUTO=ON
cmake --build --preset gcc-debug --target exercise_cpp14_decltype_auto
ctest --preset gcc-debug -R '^exercise_cpp14_decltype_auto$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_DECLTYPE_AUTO=OFF
```
