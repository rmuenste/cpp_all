#include <cassert>
#include <type_traits>

template <typename... Ts>
struct TypeList {};

template <typename List>
struct Size;
template <typename... Ts>
struct Size<TypeList<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)> {};

template <typename T, typename List>
struct Contains;
template <typename T, typename... Ts>
struct Contains<T, TypeList<Ts...>> : std::bool_constant<(std::is_same_v<T, Ts> || ...)> {};

template <typename List, template <typename> class Transform>
struct Map;
template <typename... Ts, template <typename> class Transform>
struct Map<TypeList<Ts...>, Transform> { using type = TypeList<typename Transform<Ts>::type...>; };

int main() {
  using Numbers = TypeList<int, long, double>;
  using Pointers = Map<Numbers, std::add_pointer>::type;
  static_assert(Size<Numbers>::value == 3);
  static_assert(Contains<double, Numbers>::value);
  static_assert(std::is_same_v<Pointers, TypeList<int*, long*, double*>>);
  assert(Size<Pointers>::value == 3);
}
