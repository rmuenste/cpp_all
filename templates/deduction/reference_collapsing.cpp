#include <cassert>
#include <type_traits>

template <typename T>
constexpr bool receives_lvalue(T&&) {
  return std::is_lvalue_reference<T&&>::value;
}

int main() {
  int value = 42;
  static_assert(receives_lvalue(value), "T becomes int&, then int& && collapses to int&");
  static_assert(!receives_lvalue(42), "an rvalue keeps an rvalue reference");
  assert(receives_lvalue(value));
}
