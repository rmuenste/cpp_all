# Prepare a sale catalog

Filter unavailable products, apply a discount, and sort a small catalog in place.

## Tasks

1. Implement prepare_catalog(vector<Product>&). Assume nonnegative prices and stock counts, with unique product IDs.
2. Erase products whose stock is zero using the erase/remove_if idiom.
3. Use a range-for loop by reference to apply cents -= cents / 10 to each remaining product.
4. Sort by discounted price ascending, then by ID ascending when prices match.

## Checks

Check filtering, persistent price changes, integer rounding, deterministic ties, and empty input.

Complete [range_algorithms.cpp](range_algorithms.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_RANGE_ALGORITHMS=ON
cmake --build --preset gcc-debug --target exercise_cpp11_range_algorithms
ctest --preset gcc-debug -R '^exercise_cpp11_range_algorithms$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_RANGE_ALGORITHMS=OFF
```
