#include <cassert>
#include <expected>
#include <string>
#include <string_view>

std::expected<int, std::string> parse_digit(std::string_view text) {
  if (text.size() == 1 && text.front() >= '0' && text.front() <= '9') {
    return text.front() - '0';
  }
  return std::unexpected{"expected one decimal digit"};
}

int main() {
  assert(parse_digit("7").value() == 7);
  const auto error = parse_digit("42");
  assert(!error && error.error() == "expected one decimal digit");
}
