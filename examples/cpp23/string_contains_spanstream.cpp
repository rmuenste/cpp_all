#include <array>
#include <cassert>
#include <spanstream>
#include <string>

int main() {
  const std::string text = "modern C++23";
  assert(text.contains("C++"));

  std::array<char, 32> storage{};
  std::ospanstream output{storage};
  output << "value=" << 42;
  const auto written = output.span();
  assert(std::string(written.begin(), written.end()) == "value=42");
}
