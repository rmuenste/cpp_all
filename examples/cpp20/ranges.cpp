#include <cassert>
#include <ranges>
#include <vector>

int main() {
  const std::vector<int> values{1, 2, 3, 4, 5, 6};
  auto result = values
      | std::views::filter([](int value) { return value % 2 == 0; })
      | std::views::transform([](int value) { return value * value; });

  std::vector<int> collected;
  for (int value : result) collected.push_back(value);
  assert((collected == std::vector<int>{4, 16, 36}));
}
