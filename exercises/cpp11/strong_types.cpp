// Exercise (C++11): Format request log entries.
// Keep log severity and request identifiers distinct in a logging API.
//
// Tasks:
// 1. Define enum class LogLevel with info, warning, and error values.
// 2. Define RequestId with an explicit int constructor and a value() const accessor.
//    Integers must not implicitly become request IDs.
// 3. Implement format_entry(LogLevel, const RequestId*). A nullptr means a global
//    entry; otherwise include the request ID. Match the strings in main().
//
// Checks: Check scoped enum conversion, explicit IDs, and logging with and without
// request context.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_STRONG_TYPES=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_strong_types
// ctest --preset gcc-debug -R '^exercise_cpp11_strong_types$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_STRONG_TYPES=OFF

#include <cassert>
#include <string>
#include <type_traits>

// TODO: Define LogLevel, RequestId, and format_entry here.

int main() {
    static_assert(!std::is_convertible<int, RequestId>::value, "explicit IDs");
    static_assert(!std::is_convertible<LogLevel, int>::value, "scoped severity");
    const RequestId request{42};
    assert(request.value() == 42);
    assert(format_entry(LogLevel::info, &request) == "[info] request=42");
    assert(format_entry(LogLevel::warning, &request) == "[warning] request=42");
    assert(format_entry(LogLevel::error, nullptr) == "[error] global");
}
