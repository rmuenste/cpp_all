#include <cassert>

struct Base {
  virtual ~Base() = default;
  virtual int value() const { return 1; }
};

struct Derived final : Base {
  Derived() = default;
  Derived(const Derived&) = delete;
  int value() const override { return 2; }
};

int main() {
  Derived derived;
  Base& base = derived;
  assert(base.value() == 2);
}
