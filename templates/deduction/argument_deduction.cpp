#include <cassert>
#include <type_traits>

template <typename T>
constexpr bool by_value_is_const(T) { return std::is_const<T>::value; }

template <typename T>
constexpr bool by_reference_is_const(T&) { return std::is_const<T>::value; }

template <typename T>
void same_type(T, T) {}

int main() {
  const int value = 42;
  static_assert(!by_value_is_const(value), "top-level const is dropped by value");
  static_assert(by_reference_is_const(value), "references preserve cv qualification");
  same_type(1, 2);
  // same_type(1, 2.0); // Error: T cannot be both int and double.
  assert(value == 42);
}
