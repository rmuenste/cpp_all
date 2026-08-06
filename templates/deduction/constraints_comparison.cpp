#include <cassert>
#include <concepts>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, T> legacy_increment(T value) {
  return value + 1;
}

template <std::integral T>
T modern_increment(T value) {
  return value + 1;
}

template <typename T>
concept ModernIncrementable = requires(T value) { modern_increment(value); };

int main() {
  static_assert(ModernIncrementable<int>);
  static_assert(!ModernIncrementable<double>);
  assert(legacy_increment(41) == modern_increment(41));
}
