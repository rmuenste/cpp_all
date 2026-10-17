// Exercise (C++11): Generate reproducible retry delays.
// Use typed durations and seeded jitter to avoid synchronized retries without sleeping
// in tests.
//
// Tasks:
// 1. Implement RetryPolicy(milliseconds base, milliseconds jitter, uint32_t seed).
//    Store durations and an mt19937 engine seeded once in the constructor.
// 2. Reject negative base or jitter with invalid_argument. Assume all delay arithmetic
//    fits in the milliseconds representation.
// 3. Implement next_delay(unsigned attempt), with attempt starting at zero: base *
//    (attempt + 1) plus uniform integer jitter in the inclusive interval [0,
//    jitter.count()]. Advance the stored engine rather than reseeding it.
// 4. Return milliseconds. Equal policies given the same calls must produce the same
//    sequence; do not hardcode a library-specific random sequence. Use duration_cast
//    for the seconds check in main().
//
// Checks: Check reproducibility, bounds, zero jitter, duration conversion, and invalid
// configuration without waiting in real time.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CHRONO_RANDOM=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_chrono_random
// ctest --preset gcc-debug -R '^exercise_cpp11_chrono_random$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CHRONO_RANDOM=OFF

#include <cassert>
#include <chrono>
#include <cstdint>
#include <random>
#include <stdexcept>

using Milliseconds = std::chrono::milliseconds;

class RetryPolicy {
public:
    RetryPolicy(Milliseconds base, Milliseconds jitter, std::uint32_t seed);
    Milliseconds next_delay(unsigned attempt);
    // TODO: Add state and implement the operations above.
};

int main() {
    RetryPolicy first(Milliseconds{100}, Milliseconds{25}, 1234);
    RetryPolicy second(Milliseconds{100}, Milliseconds{25}, 1234);
    for (unsigned attempt = 0; attempt < 10; ++attempt) {
        const auto delay = first.next_delay(attempt);
        assert(delay == second.next_delay(attempt));
        const Milliseconds minimum{100 * (attempt + 1)};
        assert(delay >= minimum && delay <= minimum + Milliseconds{25});
    }
    RetryPolicy fixed(Milliseconds{1500}, Milliseconds{0}, 1);
    const auto delay = fixed.next_delay(0);
    assert(delay == Milliseconds{1500});
    // TODO: Declare whole_seconds using duration_cast<std::chrono::seconds>.
    assert(whole_seconds.count() == 1);
    assert(fixed.next_delay(1) == Milliseconds{3000});
    bool rejected = false;
    try { RetryPolicy invalid(Milliseconds{0}, Milliseconds{-1}, 1); }
    catch (const std::invalid_argument&) { rejected = true; }
    assert(rejected);
    rejected = false;
    try { RetryPolicy invalid(Milliseconds{-1}, Milliseconds{0}, 1); }
    catch (const std::invalid_argument&) { rejected = true; }
    assert(rejected);
}
