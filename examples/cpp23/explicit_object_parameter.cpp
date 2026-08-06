#include <cassert>
#include <type_traits>
#include <utility>

struct Value {
  int data;

  template <typename Self>
  decltype(auto) get(this Self&& self) {
    return (std::forward<Self>(self).data);
  }
};

int main() {
  Value value{42};
  value.get() = 7;
  const Value constant{42};
  static_assert(std::is_same_v<decltype(constant.get()), const int&>);
  assert(value.data == 7 && constant.get() == 42);
}
