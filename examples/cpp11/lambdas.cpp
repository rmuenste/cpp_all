#include <algorithm>
#include <cassert>
#include <vector>

int main() {
  std::vector<int> values{1, 2, 3, 4};
  int threshold = 2;
  const auto count = std::count_if(values.begin(), values.end(),
                                   [threshold](int value) { return value > threshold; });

  int sum = 0;
  std::for_each(values.begin(), values.end(), [&sum](int value) { sum += value; });
  assert(count == 2 && sum == 10);
}
