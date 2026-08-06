#include <array>
#include <cassert>
#include <span>
#include <vector>

int sum(std::span<const int> values) {
  int result = 0;
  for (int value : values) result += value;
  return result;
}

int main() {
  const std::array<int, 3> array{1, 2, 3};
  const std::vector<int> vector{4, 5};
  assert(sum(array) == 6 && sum(vector) == 9);
}
