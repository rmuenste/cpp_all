#include <cassert>
#include <string>
#include <utility>

template <typename T>
struct NamedValue {
  std::string name;
  T value;
};

template <typename T>
NamedValue(const char*, T) -> NamedValue<T>;

int main() {
  NamedValue answer{"answer", 42};
  std::pair point{2, 3.5};
  assert(answer.value == 42 && point.second == 3.5);
}
