#include <cassert>
#include <optional>
#include <string>

int main() {
  const std::optional<int> value = 21;
  const auto result = value
      .transform([](int number) { return number * 2; })
      .and_then([](int number) -> std::optional<std::string> {
        return std::to_string(number);
      });
  assert(result == "42");
}
