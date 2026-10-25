// Exercise (C++14): Count calls without changing their results.
// Wrap an operation with a call counter while preserving its exact return type.
//
// Tasks:
// 1. Define counted_call(size_t& calls, F&& operation) as a function template returning
//    decltype(auto).
// 2. Increment calls once before invoking the operation, including when the operation
//    throws.
// 3. Invoke the callable with its original value category and return its result without
//    copying referenced objects. Support values, mutable references, const references,
//    and void.
// 4. Do not catch exceptions inside the wrapper or return references to local
//    variables.
//
// Background:
// - auto return deduction normally drops references; decltype(auto) uses the decltype
//   rules on the returned expression instead.
// - An unparenthesized name has different decltype rules from a general expression.
//   References do not extend the referred object's lifetime.
// - A return statement may return a void expression from a void-returning function.
//   Forwarding-reference deduction and std::forward apply to callables too.
// - A trailing & or && on a member function restricts calls to lvalue or rvalue
//   objects respectively. The RvalueOnly fixture uses this to check forwarding;
//   you do not need to change it.
//
// Checks: Check exact return types, aliasing, value and void results, callable
// forwarding, and counting an operation that throws.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_DECLTYPE_AUTO=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_decltype_auto
// ctest --preset gcc-debug -R '^exercise_cpp14_decltype_auto$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_DECLTYPE_AUTO=OFF

#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

// TODO: Define this wrapper before main() so its return type can be deduced.
template <typename F>
decltype(auto) counted_call(std::size_t& calls, F&& operation);

// Test fixture: this callable can only be invoked as an rvalue.
struct RvalueOnly {
    int operator()() && { return 11; }
    int operator()() & = delete;
};

int main() {
    std::size_t calls = 0;
    std::string name = "draft";
    auto edit = [&name]() -> std::string& { return name; };
    auto view = [&name]() -> const std::string& { return name; };
    auto read = [] { return 7; };
    auto clear = [&name] { name.clear(); };
    static_assert(std::is_same<decltype(counted_call(calls, edit)), std::string&>::value,
                  "mutable reference preserved");
    static_assert(std::is_same<decltype(counted_call(calls, view)), const std::string&>::value,
                  "const reference preserved");
    static_assert(std::is_same<decltype(counted_call(calls, read)), int>::value, "value result");
    static_assert(std::is_same<decltype(counted_call(calls, clear)), void>::value, "void result");
    assert(calls == 0); // decltype does not execute the expressions above.
    counted_call(calls, edit) = "ready";
    assert(name == "ready" && calls == 1);
    const auto& alias = counted_call(calls, view);
    assert(&alias == &name && calls == 2);
    assert(counted_call(calls, read) == 7 && calls == 3);
    counted_call(calls, clear);
    assert(name.empty() && calls == 4);
    assert(counted_call(calls, RvalueOnly{}) == 11 && calls == 5);
    bool failed = false;
    try { counted_call(calls, []() -> int { throw std::runtime_error("failed"); }); }
    catch (const std::runtime_error&) { failed = true; }
    assert(failed && calls == 6);
}
