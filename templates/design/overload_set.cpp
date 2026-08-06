#include <cassert>
#include <string>
#include <variant>

template <typename... Callables>
struct Overload : Callables... { using Callables::operator()...; };
template <typename... Callables>
Overload(Callables...) -> Overload<Callables...>;

int main() {
  std::variant<int, std::string> value = 42;
  const auto visitor = Overload{
      [](int number) { return number; },
      [](const std::string& text) { return static_cast<int>(text.size()); }};
  assert(std::visit(visitor, value) == 42);
  value = std::string{"four"};
  assert(std::visit(visitor, value) == 4);
}
