// Exercise (C++11): Prepare a sale catalog.
// Filter unavailable products, apply a discount, and sort a small catalog in place.
//
// Tasks:
// 1. Implement prepare_catalog(vector<Product>&). Assume nonnegative prices and stock
//    counts, with unique product IDs.
// 2. Erase products whose stock is zero using the erase/remove_if idiom.
// 3. Use a range-for loop by reference to apply cents -= cents / 10 to each remaining
//    product.
// 4. Sort by discounted price ascending, then by ID ascending when prices match.
//
// Checks: Check filtering, persistent price changes, integer rounding, deterministic
// ties, and empty input.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_RANGE_ALGORITHMS=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_range_algorithms
// ctest --preset gcc-debug -R '^exercise_cpp11_range_algorithms$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_RANGE_ALGORITHMS=OFF

#include <algorithm>
#include <cassert>
#include <vector>

struct Product { int id; int cents; int stock; };

// TODO: Implement filtering, the range-for update, and sorting.
void prepare_catalog(std::vector<Product>& products);

int main() {
    std::vector<Product> products{{3, 1000, 2}, {1, 500, 0},
                                  {2, 1000, 1}, {4, 555, 3}};
    prepare_catalog(products);
    assert(products.size() == 3);
    assert(products[0].id == 4 && products[0].cents == 500);
    assert(products[1].id == 2 && products[1].cents == 900);
    assert(products[2].id == 3 && products[2].cents == 900);
    assert(products[0].stock == 3 && products[1].stock == 1);
    std::vector<Product> empty;
    prepare_catalog(empty);
    assert(empty.empty());
    std::vector<Product> unavailable{{1, 100, 0}};
    prepare_catalog(unavailable);
    assert(unavailable.empty());
}
