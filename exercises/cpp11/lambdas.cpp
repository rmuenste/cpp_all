// Exercise (C++11): Summarize unpaid invoices.
// Compute the count and total of unpaid invoices meeting a configurable minimum.
//
// Tasks:
// 1. Implement summarize(invoices, minimum_cents). Include unpaid invoices with cents
//    >= minimum_cents; do not change the input.
// 2. Use count_if with a lambda capturing minimum_cents by value for the count.
// 3. Use for_each with a lambda capturing the total by reference and the threshold by
//    value to accumulate qualifying cents. Assume the total fits in int.
//
// Checks: Check paid invoices, the inclusive threshold, different thresholds, and an
// empty input.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_LAMBDAS=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_lambdas
// ctest --preset gcc-debug -R '^exercise_cpp11_lambdas$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_LAMBDAS=OFF

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

struct Invoice { int cents; bool paid; };
struct Summary { std::size_t count; int cents; };

// TODO: Implement this function using the required lambda captures.
Summary summarize(const std::vector<Invoice>& invoices, int minimum_cents);

int main() {
    const std::vector<Invoice> invoices{{500, false}, {1500, true},
                                        {1000, false}, {2000, false}};
    const auto result = summarize(invoices, 1000);
    assert(result.count == 2 && result.cents == 3000);
    const auto all_unpaid = summarize(invoices, 0);
    assert(all_unpaid.count == 3 && all_unpaid.cents == 3500);
    const auto none = summarize(invoices, 3000);
    assert(none.count == 0 && none.cents == 0);
    const auto empty = summarize({}, 0);
    assert(empty.count == 0 && empty.cents == 0);
    assert(invoices[0].cents == 500 && !invoices[0].paid);
}
