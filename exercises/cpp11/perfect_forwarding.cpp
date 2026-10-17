// Exercise (C++11): Construct owned objects through a factory.
// A generic owning factory must preserve constructor arguments and support move-only
// resources.
//
// Tasks:
// 1. Implement make_owned<T>(Args&&...) returning unique_ptr<T>, using new T(...) and
//    std::forward for each constructor argument.
// 2. Keep the factory generic: it must handle zero arguments, lvalues, rvalues, and a
//    unique_ptr passed by move.
// 3. Use C++11 facilities only. Batch records the selected constructor so the
//    assertions can detect lost value categories.
//
// Checks: Check copy-path versus move-path overload selection, empty construction, and
// move-only ownership transfer.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_PERFECT_FORWARDING=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_perfect_forwarding
// ctest --preset gcc-debug -R '^exercise_cpp11_perfect_forwarding$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_PERFECT_FORWARDING=OFF

#include <cassert>
#include <memory>
#include <utility>
#include <vector>

struct Batch {
    std::vector<int> values;
    bool used_move;
    explicit Batch(const std::vector<int>& input) : values(input), used_move(false) {}
    explicit Batch(std::vector<int>&& input) : values(std::move(input)), used_move(true) {}
};

struct Worker {
    std::unique_ptr<int> resource;
    explicit Worker(std::unique_ptr<int> input) : resource(std::move(input)) {}
};

// TODO: Define the generic forwarding factory.
template <typename T, typename... Args>
std::unique_ptr<T> make_owned(Args&&... args);

int main() {
    std::vector<int> input{1, 2, 3};
    auto copied = make_owned<Batch>(input);
    assert(!copied->used_move && copied->values == input);
    auto moved = make_owned<Batch>(std::vector<int>{4, 5});
    assert(moved->used_move && (moved->values == std::vector<int>{4, 5}));
    auto empty = make_owned<std::vector<int>>();
    assert(empty->empty());
    std::unique_ptr<int> resource(new int(7));
    auto worker = make_owned<Worker>(std::move(resource));
    assert(!resource && *worker->resource == 7);
}
