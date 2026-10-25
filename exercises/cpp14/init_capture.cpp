// Exercise (C++14): Own a payload in a deferred upload.
// Return a move-only callable that owns its upload data and a snapshot of its
// destination.
//
// Tasks:
// 1. Define make_upload(unique_ptr<Payload> payload, const string& destination) before
//    main(), with an auto-deduced return type.
// 2. Return a lambda using init-capture to move payload into its state and copy
//    destination into a separately named captured value. Assume the initial payload is
//    non-null.
// 3. On its first invocation, return destination + ":" + payload.contents and release
//    the captured payload. On later invocations, throw logic_error.
// 4. The callable must remain usable after being moved and after the caller changes
//    destination. Do not require the closure to be copyable.
//
// Background:
// - An init-capture has the form name = expression and initializes state inside the
//   closure when the lambda is created.
// - A closure with a unique_ptr capture is move-only. mutable permits modification of
//   state captured by value; an ordinary lambda call operator is const.
// - C++14 can deduce a function return type from its definition, including an unnamed
//   closure type. That definition must be visible before the call.
//
// Checks: Check ownership transfer, destination snapshotting, moving the closure, and
// rejection of repeated execution.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_INIT_CAPTURE=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_init_capture
// ctest --preset gcc-debug -R '^exercise_cpp14_init_capture$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_INIT_CAPTURE=OFF

#include <cassert>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

struct Payload { std::string contents; };

// TODO: Define make_upload here, including its returned lambda.

int main() {
    auto payload = std::make_unique<Payload>(Payload{"chunk"});
    std::string destination = "archive";
    auto upload = make_upload(std::move(payload), destination);
    assert(!payload);
    static_assert(!std::is_copy_constructible<decltype(upload)>::value, "exclusive ownership");
    static_assert(std::is_move_constructible<decltype(upload)>::value, "movable task");
    destination = "elsewhere";
    auto scheduled = std::move(upload);
    assert(scheduled() == "archive:chunk");
    bool repeated = false;
    try { scheduled(); }
    catch (const std::logic_error&) { repeated = true; }
    assert(repeated);
}
