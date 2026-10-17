# Generate reproducible retry delays

Use typed durations and seeded jitter to avoid synchronized retries without sleeping in tests.

## Tasks

1. Implement RetryPolicy(milliseconds base, milliseconds jitter, uint32_t seed). Store durations and an mt19937 engine seeded once in the constructor.
2. Reject negative base or jitter with invalid_argument. Assume all delay arithmetic fits in the milliseconds representation.
3. Implement next_delay(unsigned attempt), with attempt starting at zero: base * (attempt + 1) plus uniform integer jitter in the inclusive interval [0, jitter.count()]. Advance the stored engine rather than reseeding it.
4. Return milliseconds. Equal policies given the same calls must produce the same sequence; do not hardcode a library-specific random sequence. Use duration_cast for the seconds check in main().

## Checks

Check reproducibility, bounds, zero jitter, duration conversion, and invalid configuration without waiting in real time.

Complete [chrono_random.cpp](chrono_random.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CHRONO_RANDOM=ON
cmake --build --preset gcc-debug --target exercise_cpp11_chrono_random
ctest --preset gcc-debug -R '^exercise_cpp11_chrono_random$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CHRONO_RANDOM=OFF
```
