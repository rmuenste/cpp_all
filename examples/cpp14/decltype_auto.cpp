#include <cassert>
#include <type_traits>
#include <vector>

decltype(auto) element(std::vector<int>& values, std::size_t index) {
  return values[index];
}

int main() {
  std::vector<int> values{1, 2, 3};
  static_assert(std::is_same<decltype(element(values, 0)), int&>::value, "reference preserved");
  element(values, 1) = 42;
  assert(values[1] == 42);
}
