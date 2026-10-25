// Exercise (C++14): Order two dispatch queues with one comparator.
// Reuse one sorting rule across queue entries whose keys have different types.
//
// Tasks:
// 1. In main(), define by_priority as one generic lambda with two const auto&
//    parameters.
// 2. Order higher priorities first. For equal priorities, order smaller keys first.
//    Comparing an entry with itself must return false.
// 3. Use the same lambda with both provided sorts. Keep the input structures and their
//    field types unchanged.
//
// Background:
// - Each auto parameter of a C++14 generic lambda is independently deduced, as if its
//   call operator were a function template.
// - A sorting comparator describes a strict ordering; it means "comes before", not
//   "comes before or equals".
//
// Checks: Check priority order, numeric and string tie-breakers, equivalent entries,
// and an empty queue.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_GENERIC_LAMBDAS=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_generic_lambdas
// ctest --preset gcc-debug -R '^exercise_cpp14_generic_lambdas$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_GENERIC_LAMBDAS=OFF

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

struct Ticket { int key; int priority; };
struct Notification { std::string key; int priority; };

int main() {
    // TODO: Define the generic lambda by_priority here.

    std::vector<Ticket> tickets{{3, 1}, {9, 3}, {2, 1}, {1, 3}};
    std::sort(tickets.begin(), tickets.end(), by_priority);
    assert(tickets[0].key == 1 && tickets[1].key == 9);
    assert(tickets[2].key == 2 && tickets[3].key == 3);
    assert(tickets[0].priority == 3 && tickets[3].priority == 1);
    assert(!by_priority(tickets[0], tickets[0]));

    std::vector<Notification> notifications{{"upload", 2}, {"alert", 5}, {"index", 2}};
    std::sort(notifications.begin(), notifications.end(), by_priority);
    assert(notifications[0].key == "alert");
    assert(notifications[1].key == "index" && notifications[2].key == "upload");
    assert(!by_priority(Notification{"same", 1}, Notification{"same", 1}));
    std::vector<Ticket> empty;
    std::sort(empty.begin(), empty.end(), by_priority);
    assert(empty.empty());
}
