# Summarize unpaid invoices

Compute the count and total of unpaid invoices meeting a configurable minimum.

## Tasks

1. Implement summarize(invoices, minimum_cents). Include unpaid invoices with cents >= minimum_cents; do not change the input.
2. Use count_if with a lambda capturing minimum_cents by value for the count.
3. Use for_each with a lambda capturing the total by reference and the threshold by value to accumulate qualifying cents. Assume the total fits in int.

## Checks

Check paid invoices, the inclusive threshold, different thresholds, and an empty input.

Complete [lambdas.cpp](lambdas.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_LAMBDAS=ON
cmake --build --preset gcc-debug --target exercise_cpp11_lambdas
ctest --preset gcc-debug -R '^exercise_cpp11_lambdas$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_LAMBDAS=OFF
```
