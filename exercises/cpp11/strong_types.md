# Format request log entries

Keep log severity and request identifiers distinct in a logging API.

## Tasks

1. Define enum class LogLevel with info, warning, and error values.
2. Define RequestId with an explicit int constructor and a value() const accessor. Integers must not implicitly become request IDs.
3. Implement format_entry(LogLevel, const RequestId*). A nullptr means a global entry; otherwise include the request ID. Match the strings in main().

## Checks

Check scoped enum conversion, explicit IDs, and logging with and without request context.

Complete [strong_types.cpp](strong_types.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_STRONG_TYPES=ON
cmake --build --preset gcc-debug --target exercise_cpp11_strong_types
ctest --preset gcc-debug -R '^exercise_cpp11_strong_types$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_STRONG_TYPES=OFF
```
