#include <cassert>
#include <string>
#include <tuple>

template <typename Tuple, typename Function, std::size_t... Indices>
void for_each_impl(Tuple&& tuple, Function function, std::index_sequence<Indices...>) {
  (function(std::get<Indices>(std::forward<Tuple>(tuple))), ...);
}

template <typename Tuple, typename Function>
void for_each(Tuple&& tuple, Function function) {
  constexpr auto size = std::tuple_size_v<std::remove_reference_t<Tuple>>;
  for_each_impl(std::forward<Tuple>(tuple), function, std::make_index_sequence<size>{});
}

int main() {
  int visits = 0;
  for_each(std::tuple{1, 2.0, std::string{"three"}}, [&](const auto&) { ++visits; });
  assert(visits == 3);
}
