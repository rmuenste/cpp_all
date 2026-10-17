// Exercise (C++11): Configure a retry schedule.
// Accept a short list of retry delays while rejecting invalid configuration.
//
// Tasks:
// 1. Implement RetrySchedule with an initializer_list<int> constructor storing delays
//    in milliseconds in a vector<int>. Reject any negative delay with invalid_argument.
// 2. Expose size() const and total_ms() const. An empty schedule has size and total
//    zero. Assume totals fit in int.
// 3. In main(), initialize repeated with three copies of 100 using the vector
//    count/value constructor, and explicit_delays with the two values 3 and 100 using
//    braces.
//
// Checks: Check list construction, empty and invalid schedules, and the difference
// between vector count/value and initializer-list construction.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_INITIALIZATION=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_initialization
// ctest --preset gcc-debug -R '^exercise_cpp11_initialization$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_INITIALIZATION=OFF

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>

class RetrySchedule {
public:
    explicit RetrySchedule(std::initializer_list<int> delays);
    std::size_t size() const;
    int total_ms() const;
    // TODO: Add storage and implement the operations above.
};

int main() {
    RetrySchedule schedule{100, 250, 500};
    assert(schedule.size() == 3 && schedule.total_ms() == 850);
    RetrySchedule empty{};
    assert(empty.size() == 0 && empty.total_ms() == 0);
    bool rejected = false;
    try { RetrySchedule invalid{100, -1}; }
    catch (const std::invalid_argument&) { rejected = true; }
    assert(rejected);

    // TODO: Declare repeated and explicit_delays using the required forms.
    assert((repeated == std::vector<int>{100, 100, 100}));
    assert((explicit_delays == std::vector<int>{3, 100}));
}
