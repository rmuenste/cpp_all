// Exercise (C++11): Look up and edit service settings.
// Write a generic settings lookup that preserves references and constness.
//
// Tasks:
// 1. Implement lookup(settings, key) as a function template using a C++11 trailing
//    return type with decltype(settings.at(key)). Let at() report missing keys.
// 2. In main(), declare snapshot with auto so changing it does not edit settings.
// 3. Declare live with auto& so changing it edits settings in place.
// 4. Declare read_only using decltype((read_view.at("workers"))) and initialize it
//    through lookup(read_view, "workers"). It must alias the stored value.
//
// Checks: The static assertions check exact types; runtime assertions check copying,
// aliasing, and missing-key handling.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_TYPE_DEDUCTION=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_type_deduction
// ctest --preset gcc-debug -R '^exercise_cpp11_type_deduction$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_TYPE_DEDUCTION=OFF

#include <cassert>
#include <map>
#include <stdexcept>
#include <string>
#include <type_traits>

// TODO: Define the lookup function template here.

int main() {
    std::map<std::string, int> settings{{"workers", 4}};
    const auto& read_view = settings;
    // TODO: Declare snapshot, live, and read_only as described above.

    static_assert(std::is_same<decltype(snapshot), int>::value, "value copy");
    static_assert(std::is_same<decltype(live), int&>::value, "mutable alias");
    static_assert(std::is_same<decltype(read_only), const int&>::value, "const alias");
    static_assert(std::is_same<decltype(lookup(read_view, "workers")), const int&>::value,
                  "lookup must preserve constness");
    snapshot = 8;
    assert(snapshot == 8 && settings.at("workers") == 4);
    live = 6;
    assert(settings.at("workers") == 6 && read_only == 6);
    assert(&read_only == &settings.at("workers"));
    bool missing = false;
    try { lookup(settings, "missing"); }
    catch (const std::out_of_range&) { missing = true; }
    assert(missing);
}
