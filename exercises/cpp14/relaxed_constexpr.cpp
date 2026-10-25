// Exercise (C++14): Choose a bounded buffer capacity.
// Use the same capacity calculation in compile-time buffer declarations and runtime
// requests.
//
// Tasks:
// 1. Implement constexpr next_capacity(size_t requested), returning the smallest power
//    of two at least as large as requested. Zero requests a capacity of one.
// 2. Cap supported requests at 1024. Throw length_error for a larger request, before
//    performing growth arithmetic.
// 3. Use a local variable and a loop, as allowed by C++14 constexpr rules. The function
//    must work both in constant expressions and with runtime arguments.
//
// Background:
// - C++14 constexpr function bodies can contain local variables, branches, and loops.
//   constexpr permits compile-time evaluation; it does not require every call to occur
//   at compile time.
// - Array template extents and static_assert conditions require constant expressions. A
//   path that throws can execute at runtime but cannot be evaluated successfully as a
//   constant expression.
//
// Checks: Check zero and exact powers, rounding up, a compile-time array extent, and
// runtime rejection beyond the limit.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_RELAXED_CONSTEXPR=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_relaxed_constexpr
// ctest --preset gcc-debug -R '^exercise_cpp14_relaxed_constexpr$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_RELAXED_CONSTEXPR=OFF

#include <array>
#include <cassert>
#include <cstddef>
#include <stdexcept>

// TODO: Define the function before its constant-expression uses below.
constexpr std::size_t next_capacity(std::size_t requested);

int main() {
    static_assert(next_capacity(0) == 1, "minimum capacity");
    static_assert(next_capacity(1) == 1 && next_capacity(2) == 2, "exact powers");
    static_assert(next_capacity(3) == 4 && next_capacity(17) == 32, "round up");
    static_assert(next_capacity(1024) == 1024, "largest supported capacity");
    std::array<unsigned char, next_capacity(17)> buffer{};
    assert(buffer.size() == 32);
    std::size_t requested = 65;
    assert(next_capacity(requested) == 128);
    bool rejected = false;
    try { next_capacity(1025); }
    catch (const std::length_error&) { rejected = true; }
    assert(rejected);
}
