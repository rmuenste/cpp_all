// Exercise (C++11): Process a batch with two workers.
// Collect small job results safely when two workers finish in an arbitrary order.
//
// Tasks:
// 1. Implement process_batch(const vector<int>&). Split the input into two non-
//    overlapping halves and square each value exactly once. Inputs and their squares
//    fit in int.
// 2. Run one half with std::thread and the other with std::async(std::launch::async,
//    ...). Keep input and shared state alive until both workers finish.
// 3. Protect shared result-vector insertions with lock_guard<mutex>. Track completed
//    items with atomic<size_t>. Do not hold the mutex while joining or waiting.
// 4. Join the thread and get() the future before returning BatchResult with all squares
//    and the completed count. Result order is unspecified; handle empty and odd-sized
//    inputs.
//
// Checks: Check counts and sorted results, including duplicates, odd batches, and empty
// input. Do not rely on sleeps or worker scheduling.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONCURRENCY=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_concurrency
// ctest --preset gcc-debug -R '^exercise_cpp11_concurrency$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONCURRENCY=OFF

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cstddef>
#include <future>
#include <mutex>
#include <thread>
#include <vector>

struct BatchResult { std::vector<int> squares; std::size_t processed; };

// TODO: Implement both workers and synchronization.
BatchResult process_batch(const std::vector<int>& input);

int main() {
    auto result = process_batch({3, -2, 3, 0, 5});
    std::sort(result.squares.begin(), result.squares.end());
    assert(result.processed == 5);
    assert((result.squares == std::vector<int>{0, 4, 9, 9, 25}));
    const auto single = process_batch({7});
    assert(single.processed == 1 && (single.squares == std::vector<int>{49}));
    const auto empty = process_batch({});
    assert(empty.processed == 0 && empty.squares.empty());
}
