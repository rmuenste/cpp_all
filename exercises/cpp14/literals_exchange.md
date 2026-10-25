# Read and clear buffered I/O state

Track pending byte counts and event flags in a bounded I/O batch.

## Tasks

1. Define constexpr operator"" _kib(unsigned long long) returning size_t bytes, with 1024 bytes
   per KiB. Assume literal results fit size_t.

2. Define constexpr unsigned readable and writable as binary literals representing distinct
   bits 1 and 2. Use a digit separator in those literals.

3. Implement PendingIo(capacity) with zero initial bytes and event flags. record(bytes, events)
   accumulates bytes and combines flags with bitwise OR.

4. If a record would exceed capacity, throw length_error without changing either pending count
   or flags. Check remaining capacity before adding to avoid overflow.

5. Implement take() returning the previous count and flags as IoBatch, using std::exchange to
   reset both members to zero. This class is used by one thread only.

## Background

- A numeric user-defined literal passes its integer value to an operator with a suffix
  beginning with _. Binary literals use 0b, and digit separators use apostrophes.

- std::exchange(object, replacement) replaces an object and returns its previous value. It is
  an ordinary utility, not an atomic synchronization operation.

- Bitwise OR combines flag bits; unlike logical OR, it preserves the individual bits in its
  integer result.

## Checks

Check literal conversion, bit flags, accumulated state, read-and-clear behavior, exact
capacity, and unchanged state after a rejected record.

Complete [literals_exchange.cpp](literals_exchange.cpp). The starter includes the tasks, background,
and assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_LITERALS_EXCHANGE=ON
cmake --build --preset gcc-debug --target exercise_cpp14_literals_exchange
ctest --preset gcc-debug -R '^exercise_cpp14_literals_exchange$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_LITERALS_EXCHANGE=OFF
```
