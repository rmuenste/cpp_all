#include <cassert>
#include <concepts>

namespace detail {
void describe() = delete;

template <typename T>
concept HasMemberDescribe = requires(const T& value) {
  { value.describe() } -> std::convertible_to<int>;
};
}

struct Describe {
  template <detail::HasMemberDescribe T>
  int operator()(const T& value) const { return value.describe(); }

  int operator()(int value) const { return value; }
};

inline constexpr Describe describe{};

struct Widget { int describe() const { return 42; } };

int main() {
  assert(describe(Widget{}) == 42);
  assert(describe(7) == 7);
}
