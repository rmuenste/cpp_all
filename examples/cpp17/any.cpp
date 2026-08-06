#include <any>
#include <cassert>
#include <string>

int main() {
  std::any value = 42;
  assert(std::any_cast<int>(value) == 42);
  value = std::string{"runtime type"};
  assert(std::any_cast<std::string>(&value) != nullptr);
  assert(std::any_cast<int>(&value) == nullptr);
}
