# Define a noncopyable output sink

Expose a polymorphic writer API with an explicitly noncopyable in-memory implementation.

## Tasks

1. Define abstract Writer with a defaulted virtual destructor and pure virtual void write(const string&).
2. Define MemoryWriter final deriving from Writer. Default its default constructor, delete its copy constructor and copy assignment, and mark write as override.
3. Append writes to a private string and expose const string& text() const. Work through Writer& without losing polymorphic behavior.

## Checks

Check default construction, disabled copying, and append behavior through the abstract interface.

Complete [class_controls.cpp](class_controls.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CLASS_CONTROLS=ON
cmake --build --preset gcc-debug --target exercise_cpp11_class_controls
ctest --preset gcc-debug -R '^exercise_cpp11_class_controls$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CLASS_CONTROLS=OFF
```
