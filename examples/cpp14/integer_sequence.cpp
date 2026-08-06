#include <array>
#include <cassert>
#include <utility>

template <std::size_t... Indices>
constexpr std::array<std::size_t, sizeof...(Indices)> make_indices(
    std::index_sequence<Indices...>) {
  return {{Indices...}};
}

int main() {
  constexpr auto indices = make_indices(std::make_index_sequence<4>{});
  static_assert(indices[0] == 0 && indices[3] == 3, "expanded index pack");
  assert(indices.size() == 4);
}
