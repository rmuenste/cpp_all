#include <cassert>
#include <optional>
#include <string_view>

std::optional<int> parse_digit(std::string_view text) {
  if (text.size() == 1 && text.front() >= '0' && text.front() <= '9') {
    return text.front() - '0';
  }
  return std::nullopt;
}

int main() {
  assert(parse_digit("7").value() == 7);
  assert(!parse_digit("42"));
  assert(parse_digit("x").value_or(-1) == -1);
}
