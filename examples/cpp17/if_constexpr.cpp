#include <cassert>
#include <string>
#include <type_traits>

template <typename T>
std::size_t measure(const T& value) {
  if constexpr (std::is_integral_v<T>) {
    return static_cast<std::size_t>(value);
  } else {
    return value.size();
  }
}

int main() {
  assert(measure(4) == 4);
  assert(measure(std::string{"hello"}) == 5);
}
