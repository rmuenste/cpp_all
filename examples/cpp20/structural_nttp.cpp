#include <cassert>
#include <cstddef>

template <std::size_t N>
struct FixedString {
  char value[N];
  constexpr FixedString(const char (&text)[N]) { for (std::size_t i = 0; i < N; ++i) value[i] = text[i]; }
};

template <FixedString Name>
struct Field {
  static constexpr auto name = Name;
};

int main() {
  using Id = Field<"id">;
  static_assert(Id::name.value[0] == 'i');
  assert(Id::name.value[1] == 'd');
}
