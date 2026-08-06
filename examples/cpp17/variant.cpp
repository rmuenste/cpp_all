#include <cassert>
#include <string>
#include <variant>

template <typename... Ts>
struct Overloaded : Ts... { using Ts::operator()...; };
template <typename... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

int main() {
  std::variant<int, std::string> value = std::string{"hello"};
  const auto length = std::visit(Overloaded{
      [](int number) { return static_cast<std::size_t>(number); },
      [](const std::string& text) { return text.size(); }}, value);
  assert(length == 5);
}
