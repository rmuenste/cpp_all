#include <cassert>
#include <type_traits>

struct Idle {};
struct Running {};
struct Stopped {};
struct Start {};
struct Stop {};

template <typename State, typename Event>
struct Transition;
template <> struct Transition<Idle, Start> { using type = Running; };
template <> struct Transition<Running, Stop> { using type = Stopped; };

template <typename State, typename Event>
using Next = typename Transition<State, Event>::type;

int main() {
  static_assert(std::is_same_v<Next<Idle, Start>, Running>);
  static_assert(std::is_same_v<Next<Running, Stop>, Stopped>);
  // Next<Idle, Stop> invalid; unsupported transitions fail at compile time.
  assert(true);
}
