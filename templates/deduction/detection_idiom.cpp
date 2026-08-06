#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T, typename = void>
struct has_size : std::false_type {};

template <typename T>
struct has_size<T, std::void_t<decltype(std::declval<const T&>().size())>> : std::true_type {};

int main() {
  static_assert(has_size<std::vector<int>>::value);
  static_assert(!has_size<int>::value);
  assert(has_size<std::vector<int>>::value);
}
