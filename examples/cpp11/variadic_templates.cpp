#include <cassert>
#include <cstddef>

int sum() { return 0; }

template <typename First, typename... Rest>
int sum(First first, Rest... rest) {
  return static_cast<int>(first) + sum(rest...);
}

template <typename... Ts>
constexpr std::size_t argument_count(Ts&&...) {
  return sizeof...(Ts);
}

int main() {
  static_assert(argument_count(1, 2.0, 'c') == 3, "pack size");
  assert(sum(1, 2, 3, 4) == 10);
}
