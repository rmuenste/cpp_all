#include <cassert>
#include <vector>

template <typename Container>
typename Container::value_type first(const Container& container) {
  typename Container::const_iterator iterator = container.begin();
  return *iterator;
}

template <typename T>
struct Wrapper {
  template <typename U>
  static U convert(T value) { return static_cast<U>(value); }
};

template <typename T>
int invoke_convert(T value) {
  return Wrapper<T>::template convert<int>(value);
}

int main() {
  assert(first(std::vector<int>{42}) == 42);
  assert(invoke_convert(3.5) == 3);
}
