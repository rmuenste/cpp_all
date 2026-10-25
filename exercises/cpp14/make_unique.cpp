// Exercise (C++14): Allocate an owned scratch buffer.
// Manage an object and its dynamically sized byte array without manual deletion.
//
// Tasks:
// 1. Implement ScratchBuffer(size_t size), storing its size and a unique_ptr<unsigned
//    char[]> allocated with make_unique. All bytes must initially be zero.
// 2. Implement size() const and mutable/const at(index) accessors. Return references
//    and throw out_of_range when index >= size(). A zero-sized buffer is valid.
// 3. In main(), create the owning pointer named buffer using make_unique<ScratchBuffer>
//    with size 4.
// 4. Use no raw new/delete or custom destructor. Let unique_ptr manage both object and
//    array ownership.
//
// Background:
// - C++14 make_unique<T>(arguments...) creates one T; make_unique<T[]>(count) creates a
//   value-initialized array and returns unique_ptr<T[]>. These are distinct overloads.
// - The array specialization uses delete[] and supports indexing, but does not store a
//   length or check bounds.
// - The presence of a unique_ptr member prevents ordinary copying. Member destruction
//   automatically releases the array.
//
// Checks: Check array value-initialization, reference access, const access, bounds
// errors, zero size, and moving the outer owner.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_MAKE_UNIQUE=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_make_unique
// ctest --preset gcc-debug -R '^exercise_cpp14_make_unique$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_MAKE_UNIQUE=OFF

#include <cassert>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <utility>

class ScratchBuffer {
public:
    explicit ScratchBuffer(std::size_t size);
    std::size_t size() const;
    unsigned char& at(std::size_t index);
    const unsigned char& at(std::size_t index) const;
    // TODO: Add the array owner and length; implement the operations above.
};

int main() {
    // TODO: Create buffer, an owning pointer to a four-byte ScratchBuffer.
    static_assert(!std::is_copy_constructible<ScratchBuffer>::value, "exclusive ownership");
    assert(buffer->size() == 4);
    for (std::size_t i = 0; i < buffer->size(); ++i) assert(buffer->at(i) == 0);
    buffer->at(1) = 42;
    const ScratchBuffer& view = *buffer;
    static_assert(std::is_same<decltype(view.at(0)), const unsigned char&>::value,
                  "read-only reference");
    assert(view.at(1) == 42);
    bool rejected = false;
    try { buffer->at(4); }
    catch (const std::out_of_range&) { rejected = true; }
    assert(rejected);
    rejected = false;
    try { view.at(4); }
    catch (const std::out_of_range&) { rejected = true; }
    assert(rejected);
    auto owner = std::move(buffer);
    assert(!buffer && owner->at(1) == 42);
    const ScratchBuffer empty{0};
    assert(empty.size() == 0);
    rejected = false;
    try { empty.at(0); }
    catch (const std::out_of_range&) { rejected = true; }
    assert(rejected);
}
