// Exercise (C++11): Define a noncopyable output sink.
// Expose a polymorphic writer API with an explicitly noncopyable in-memory
// implementation.
//
// Tasks:
// 1. Define abstract Writer with a defaulted virtual destructor and pure virtual void
//    write(const string&).
// 2. Define MemoryWriter final deriving from Writer. Default its default constructor,
//    delete its copy constructor and copy assignment, and mark write as override.
// 3. Append writes to a private string and expose const string& text() const. Work
//    through Writer& without losing polymorphic behavior.
//
// Checks: Check default construction, disabled copying, and append behavior through the
// abstract interface.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CLASS_CONTROLS=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_class_controls
// ctest --preset gcc-debug -R '^exercise_cpp11_class_controls$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CLASS_CONTROLS=OFF

#include <cassert>
#include <string>
#include <type_traits>

// TODO: Define Writer and MemoryWriter here.

void write_status(Writer& writer) {
    writer.write("ready");
    writer.write("\n");
}

int main() {
    static_assert(std::is_abstract<Writer>::value, "interface only");
    static_assert(std::has_virtual_destructor<Writer>::value, "polymorphic destruction");
    static_assert(std::is_default_constructible<MemoryWriter>::value, "default construction");
    static_assert(!std::is_copy_constructible<MemoryWriter>::value, "no copying");
    static_assert(!std::is_copy_assignable<MemoryWriter>::value, "no copy assignment");
    MemoryWriter writer;
    assert(writer.text().empty());
    write_status(writer);
    writer.write("done");
    assert(writer.text() == "ready\ndone");
}
