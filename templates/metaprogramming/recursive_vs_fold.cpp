#include <cassert>

constexpr int recursive_sum() { return 0; }

template <typename First, typename... Rest>
constexpr int recursive_sum(First first, Rest... rest) {
  return first + recursive_sum(rest...);
}

template <typename... Ts>
constexpr int fold_sum(Ts... values) {
  return (0 + ... + values);
}

int main() {
  static_assert(recursive_sum(1, 2, 3) == 6);
  static_assert(fold_sum(1, 2, 3) == 6);
  assert(fold_sum(20, 22) == 42);
}
