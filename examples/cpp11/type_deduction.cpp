// auto follows template-like deduction; decltype preserves expression rules.
#include <cassert>
#include <type_traits>

int main() {
  const int value = 42;
  auto copy = value;
  decltype(value) constant = 7;
  decltype((value)) reference = value;

  static_assert(std::is_same<decltype(copy), int>::value, "auto drops top-level const");
  static_assert(std::is_same<decltype(constant), const int>::value, "decltype(name)");
  static_assert(std::is_same<decltype(reference), const int&>::value, "decltype((expr))");
  assert(copy == 42 && reference == 42);
}
