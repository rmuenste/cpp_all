#include <cassert>
#include <source_location>
#include <string_view>

struct Event {
  std::string_view file;
  std::string_view function;
};

Event capture(std::source_location where = std::source_location::current()) {
  return {where.file_name(), where.function_name()};
}

int main() {
  const Event event = capture();
  assert(event.file.find("source_location.cpp") != std::string_view::npos);
  assert(!event.function.empty());
}
