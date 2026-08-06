#include <cassert>

constexpr int factorial(int value) {
  int result = 1;
  for (int current = 2; current <= value; ++current) {
    result *= current;
  }
  return result;
}

int main() {
  static_assert(factorial(5) == 120, "C++14 constexpr permits loops and locals");
  assert(factorial(6) == 720);
}
