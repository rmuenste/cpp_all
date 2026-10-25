// Exercise (C++14): Read and clear buffered I/O state.
// Track pending byte counts and event flags in a bounded I/O batch.
//
// Tasks:
// 1. Define constexpr operator"" _kib(unsigned long long) returning size_t bytes, with
//    1024 bytes per KiB. Assume literal results fit size_t.
// 2. Define constexpr unsigned readable and writable as binary literals representing
//    distinct bits 1 and 2. Use a digit separator in those literals.
// 3. Implement PendingIo(capacity) with zero initial bytes and event flags.
//    record(bytes, events) accumulates bytes and combines flags with bitwise OR.
// 4. If a record would exceed capacity, throw length_error without changing either
//    pending count or flags. Check remaining capacity before adding to avoid overflow.
// 5. Implement take() returning the previous count and flags as IoBatch, using
//    std::exchange to reset both members to zero. This class is used by one thread
//    only.
//
// Background:
// - A numeric user-defined literal passes its integer value to an operator with a
//   suffix beginning with _. Binary literals use 0b, and digit separators use
//   apostrophes.
// - std::exchange(object, replacement) replaces an object and returns its previous
//   value. It is an ordinary utility, not an atomic synchronization operation.
// - Bitwise OR combines flag bits; unlike logical OR, it preserves the individual bits
//   in its integer result.
//
// Checks: Check literal conversion, bit flags, accumulated state, read-and-clear
// behavior, exact capacity, and unchanged state after a rejected record.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_LITERALS_EXCHANGE=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_literals_exchange
// ctest --preset gcc-debug -R '^exercise_cpp14_literals_exchange$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_LITERALS_EXCHANGE=OFF

#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <utility>

// TODO: Define _kib, readable, and writable here.

struct IoBatch { std::size_t bytes; unsigned events; };

class PendingIo {
public:
    explicit PendingIo(std::size_t capacity);
    void record(std::size_t bytes, unsigned events);
    IoBatch take();
    // TODO: Add state and implement these operations.
};

int main() {
    static_assert(1_kib == 1'024 && 4_kib == 4096, "binary size units");
    static_assert(readable == 1 && writable == 2, "separate flag bits");
    PendingIo pending(4_kib);
    const auto initial = pending.take();
    assert(initial.bytes == 0 && initial.events == 0);
    pending.record(1_kib, readable);
    pending.record(512, writable);
    const auto batch = pending.take();
    assert(batch.bytes == 1536 && batch.events == (readable | writable));
    const auto cleared = pending.take();
    assert(cleared.bytes == 0 && cleared.events == 0);
    pending.record(3_kib, readable);
    bool rejected = false;
    try { pending.record(2_kib, writable); }
    catch (const std::length_error&) { rejected = true; }
    assert(rejected);
    const auto unchanged = pending.take();
    assert(unchanged.bytes == 3_kib && unchanged.events == readable);
    pending.record(4_kib, writable);
    const auto full = pending.take();
    assert(full.bytes == 4_kib && full.events == writable);
}
