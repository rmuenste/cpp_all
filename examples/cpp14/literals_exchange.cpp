#include <cassert>
#include <utility>

constexpr unsigned mask = 0b1111'0000;

constexpr unsigned long long operator"" _kib(unsigned long long value) {
  return value * 1024;
}

int main() {
  static_assert(mask == 240, "binary literal");
  static_assert(4_kib == 4096, "user-defined literal");
  int current = 7;
  const int previous = std::exchange(current, 9);
  assert(previous == 7 && current == 9);
}
