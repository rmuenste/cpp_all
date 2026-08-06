#include <cassert>
#include <charconv>
#include <functional>
#include <mutex>
#include <string>
#include <tuple>

int main() {
  const auto product = [](int left, int right) { return left * right; };
  assert(std::apply(product, std::tuple{6, 7}) == 42);
  assert(std::invoke(product, 3, 4) == 12);

  int parsed = 0;
  const std::string text = "123";
  const auto result = std::from_chars(text.data(), text.data() + text.size(), parsed);
  assert(result.ec == std::errc{} && parsed == 123);

  std::mutex first;
  std::mutex second;
  std::scoped_lock lock(first, second);
}
