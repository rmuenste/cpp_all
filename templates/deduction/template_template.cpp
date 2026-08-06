#include <cassert>
#include <deque>
#include <vector>

template <template <typename, typename> class Container, typename T>
std::size_t append_twice(Container<T, std::allocator<T>>& values, const T& value) {
  values.push_back(value);
  values.push_back(value);
  return values.size();
}

int main() {
  std::vector<int> vector;
  std::deque<int> deque;
  assert(append_twice(vector, 7) == 2);
  assert(append_twice(deque, 9) == 2);
}
