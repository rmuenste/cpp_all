#include <cassert>
#include <string>

template <typename... Ts>
auto sum(Ts... values) {
  return (values + ...);
}

template <typename... Ts>
bool all(Ts... values) {
  return (values && ...);
}

int main() {
  assert(sum(1, 2, 3, 4) == 10);
  assert(sum(std::string{"fold"}, std::string{" expression"}) == "fold expression");
  assert(all(true, 1, 2));
}
