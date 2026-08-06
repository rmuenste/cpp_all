#include <cassert>
#include <utility>

struct Receiver {
  int operator()(const int&) const { return 1; }
  int operator()(int&&) const { return 2; }
};

template <typename T>
int relay(T&& value) {
  return Receiver{}(std::forward<T>(value));
}

int main() {
  int value = 7;
  assert(relay(value) == 1);
  assert(relay(7) == 2);
}
