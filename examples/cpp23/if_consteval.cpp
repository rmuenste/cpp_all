#include <cassert>

constexpr int classify() {
  if consteval {
    return 1;
  } else {
    return 2;
  }
}

int main() {
  static_assert(classify() == 1);
  assert(classify() == 2);
}
