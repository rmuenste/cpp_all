#include <cassert>
#include <memory>

int main() {
  std::unique_ptr<int> value = std::make_unique<int>(42);
  auto owns_value = [owned = std::move(value)] { return *owned; };
  assert(!value);
  assert(owns_value() == 42);
}
