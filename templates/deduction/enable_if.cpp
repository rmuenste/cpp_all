#include <cassert>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type half(T value) {
  return value / 2;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type half(T value) {
  return value / static_cast<T>(2);
}

int main() {
  assert(half(8) == 4);
  assert(half(5.0) == 2.5);
}
