#include <cassert>
#include <type_traits>

int main() {
  const int value = 42;
  auto copy = auto(value);
  static_assert(std::is_same_v<decltype(copy), int>);
  copy = 7;
  assert(value == 42 && copy == 7);
}
