#include <algorithm>
#include <cassert>
#include <vector>

int main() {
  std::vector<int> values{5, 1, 4, 2, 3};
  for (int& value : values) {
    value *= 2;
  }
  std::sort(values.begin(), values.end());
  assert((values == std::vector<int>{2, 4, 6, 8, 10}));
}
