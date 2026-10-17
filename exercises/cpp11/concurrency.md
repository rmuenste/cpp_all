# Process a batch with two workers

Collect small job results safely when two workers finish in an arbitrary order.

## Tasks

1. Implement process_batch(const vector<int>&). Split the input into two non-overlapping halves and square each value exactly once. Inputs and their squares fit in int.
2. Run one half with std::thread and the other with std::async(std::launch::async, ...). Keep input and shared state alive until both workers finish.
3. Protect shared result-vector insertions with lock_guard<mutex>. Track completed items with atomic<size_t>. Do not hold the mutex while joining or waiting.
4. Join the thread and get() the future before returning BatchResult with all squares and the completed count. Result order is unspecified; handle empty and odd-sized inputs.

## Checks

Check counts and sorted results, including duplicates, odd batches, and empty input. Do not rely on sleeps or worker scheduling.

Complete [concurrency.cpp](concurrency.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONCURRENCY=ON
cmake --build --preset gcc-debug --target exercise_cpp11_concurrency
ctest --preset gcc-debug -R '^exercise_cpp11_concurrency$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONCURRENCY=OFF
```
