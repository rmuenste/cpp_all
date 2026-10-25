// Exercise (C++14): Normalize unsigned image samples.
// Express type-dependent sample properties as reusable compile-time variables.
//
// Tasks:
// 1. Define the constexpr variable template is_sample<T>: true for unsigned integral
//    types except bool, and false otherwise.
// 2. Define the constexpr variable template max_sample<T>, of type T, using
//    numeric_limits<T>::max(). Use it only with supported sample types.
// 3. Implement normalize(T sample) returning double in [0, 1], with zero mapping to
//    zero and max_sample<T> mapping to one. Use the variable templates rather than
//    repeating their expressions.
// 4. Reject unsupported types inside normalize with static_assert. Perform floating-
//    point division so intermediate sample values retain their fractional part.
//
// Background:
// - A C++14 variable template declares a family of variables indexed by template
//   arguments; name<T> selects one specialization.
// - Type traits expose compile-time properties through ::value.
//   numeric_limits<T>::max() gives the largest representable value, not a byte count.
// - Dividing two integers performs integer division even if the result is subsequently
//   stored in a double.
//
// Checks: Check compile-time type properties and maxima, endpoint normalization, a
// fractional result, and rejected types.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_VARIABLE_TEMPLATES=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_variable_templates
// ctest --preset gcc-debug -R '^exercise_cpp14_variable_templates$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_VARIABLE_TEMPLATES=OFF

#include <cassert>
#include <cstdint>
#include <limits>
#include <type_traits>

// TODO: Define is_sample<T>, max_sample<T>, and normalize(T) here.

int main() {
    static_assert(is_sample<std::uint8_t> && is_sample<std::uint16_t>, "unsigned samples");
    static_assert(!is_sample<int> && !is_sample<bool> && !is_sample<double>, "unsupported types");
    static_assert(max_sample<std::uint8_t> == 255, "8-bit maximum");
    static_assert(max_sample<std::uint16_t> == 65535, "16-bit maximum");
    assert(normalize(std::uint8_t{0}) == 0.0);
    assert(normalize(std::uint8_t{255}) == 1.0);
    assert(normalize(std::uint16_t{65535}) == 1.0);
    const double midpoint = normalize(std::uint16_t{32768});
    assert(midpoint > 0.5 && midpoint < 0.5001);
    // Each call must fail to compile when individually uncommented:
    // normalize(-1);
    // normalize(true);
    // normalize(0.5);
}
