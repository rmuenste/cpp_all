#include <array>
#include <cassert>
#include <string_view>
#include <utility>

constexpr std::array names{
    std::pair{1, std::string_view{"one"}},
    std::pair{2, std::string_view{"two"}},
    std::pair{3, std::string_view{"three"}}};

constexpr std::string_view lookup(int key) {
  for (const auto& [candidate, name] : names) {
    if (candidate == key) return name;
  }
  return "unknown";
}

int main() {
  static_assert(lookup(2) == "two");
  assert(lookup(9) == "unknown");
}
