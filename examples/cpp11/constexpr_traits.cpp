#include <cassert>
#include <type_traits>

constexpr int square(int value) { return value * value; }

template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_even(T value) {
  return value % 2 == 0;
}

int main() {
  static_assert(square(6) == 36, "constant expression");
  static_assert(std::is_integral<decltype(square(1))>::value, "trait query");
  assert(is_even(42));
}
