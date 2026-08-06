#include <cassert>
#include <string>

int main() {
  const auto add = [](const auto& left, const auto& right) { return left + right; };
  assert(add(2, 3) == 5);
  assert(add(std::string{"modern "}, std::string{"C++"}) == "modern C++");
}
