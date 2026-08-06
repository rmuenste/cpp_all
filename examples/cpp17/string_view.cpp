#include <cassert>
#include <string>
#include <string_view>

std::string_view trim_prefix(std::string_view text, std::size_t count) {
  text.remove_prefix(count);
  return text;
}

int main() {
  const std::string owner = "prefix:value";
  const std::string_view view = trim_prefix(owner, 7);
  assert(view == "value");
  // A string_view does not own characters; `owner` must outlive `view`.
}
