#include <cassert>

struct Twice {
  static int operator()(int value) { return value * 2; }
};

int main() {
  assert(Twice{}(21) == 42);
  assert(Twice::operator()(10) == 20);
}
