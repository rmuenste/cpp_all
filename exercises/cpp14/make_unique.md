# Allocate an owned scratch buffer

Manage an object and its dynamically sized byte array without manual deletion.

## Tasks

1. Implement ScratchBuffer(size_t size), storing its size and a unique_ptr<unsigned char[]>
   allocated with make_unique. All bytes must initially be zero.

2. Implement size() const and mutable/const at(index) accessors. Return references and throw
   out_of_range when index >= size(). A zero-sized buffer is valid.

3. In main(), create the owning pointer named buffer using make_unique<ScratchBuffer> with size
   4.

4. Use no raw new/delete or custom destructor. Let unique_ptr manage both object and array
   ownership.

## Background

- C++14 make_unique<T>(arguments...) creates one T; make_unique<T[]>(count) creates a value-
  initialized array and returns unique_ptr<T[]>. These are distinct overloads.

- The array specialization uses delete[] and supports indexing, but does not store a length or
  check bounds.

- The presence of a unique_ptr member prevents ordinary copying. Member destruction
  automatically releases the array.

## Checks

Check array value-initialization, reference access, const access, bounds errors, zero size, and
moving the outer owner.

Complete [make_unique.cpp](make_unique.cpp). The starter includes the tasks, background,
and assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_MAKE_UNIQUE=ON
cmake --build --preset gcc-debug --target exercise_cpp14_make_unique
ctest --preset gcc-debug -R '^exercise_cpp14_make_unique$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_MAKE_UNIQUE=OFF
```
