// Exercise (C++11): Transfer ownership of a large buffer.
// Model handing a large computation result to another component without
// duplicating its data. Implement Buffer, which owns an array of double.
//
// Tasks:
// 1. Allocate space for the requested number of elements in the constructor.
// 2. Release the array in the destructor.
// 3. Disable copying.
// 4. Implement a noexcept move constructor and move assignment operator that
//    transfer ownership without allocating or copying elements.
// 5. In move assignment, release the destination's previous array and handle
//    self-move assignment safely.
// 6. Leave moved-from buffers empty and safe to destroy.
// 7. Expose size() and data() so the assertions in main() pass.
//
// Check: Assignment uses move assignment; vector insertion uses move
// construction. The original array's address must stay the same across both.
// The starter is intentionally unfinished and will not compile yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_MOVE_SEMANTICS=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_move_semantics
// ctest --preset gcc-debug -R '^exercise_cpp11_move_semantics$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_MOVE_SEMANTICS=OFF

#include <cassert>
#include <utility>
#include <vector>

class Buffer {
public:
    // TODO: Implement ownership, move operations, size(), and data().
};

int main() {
    Buffer input(1000000);
    Buffer output(10);
    const double* original = input.data();

    output = std::move(input);
    assert(input.size() == 0 && input.data() == nullptr);
    assert(output.size() == 1000000 && output.data() == original);

    std::vector<Buffer> results;
    results.push_back(std::move(output));
    assert(output.size() == 0 && output.data() == nullptr);
    assert(results[0].size() == 1000000);
    assert(results[0].data() == original);
    return 0;
}
