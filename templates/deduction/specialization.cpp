#include <cassert>
#include <string>

template <typename T>
struct Category { static const char* name() { return "value"; } };

template <typename T>
struct Category<T*> { static const char* name() { return "pointer"; } };

template <>
struct Category<std::string> { static const char* name() { return "string"; } };

int main() {
  assert(std::string{Category<int>::name()} == "value");
  assert(std::string{Category<int*>::name()} == "pointer");
  assert(std::string{Category<std::string>::name()} == "string");
}
