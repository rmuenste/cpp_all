# Move semantics: transfer ownership of a large buffer

Implement a C++11 class `Buffer` that owns a dynamically allocated array of
`double`. Think of it as a large computation result being handed to another
component without duplicating its data.

## Requirements

- Allocate space for a given number of elements in the constructor.
- Release the array in the destructor.
- Disable copying.
- Implement a `noexcept` move constructor and move assignment operator that
  transfer ownership without allocating or copying elements.
- When assigning, release the destination's previous array and handle self-move
  assignment safely.
- Leave the moved-from buffer empty and safe to destroy.
- Expose `size()` and `data()` so ownership transfer can be checked.

## Usage and checks

Make this program work with your implementation:

```cpp
#include <cassert>
#include <utility>
#include <vector>

// Implement Buffer here.

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
}
```

The assignment exercises move assignment; inserting into the vector exercises
move construction. The array's address must stay the same across both moves.

## Build and test

Complete the provided [move_semantics.cpp](move_semantics.cpp) starter. Its
`Buffer` class is intentionally unfinished, so it will not compile yet.

Enable this exercise, build it, and run its assertions from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_MOVE_SEMANTICS=ON
cmake --build --preset gcc-debug --target exercise_cpp11_move_semantics
ctest --preset gcc-debug -R '^exercise_cpp11_move_semantics$'
```

The option stays enabled in this build directory until you turn it off:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_MOVE_SEMANTICS=OFF
```
