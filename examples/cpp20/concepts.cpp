#include <cassert>
#include <concepts>

template <typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

template <Arithmetic T>
T twice(T value) {
  return value + value;
}

int main() {
  static_assert(Arithmetic<int>);
  static_assert(!Arithmetic<void*>);
  assert(twice(21) == 42);
}
