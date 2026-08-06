#include <cassert>

template <typename T>
constexpr T pi = T(3.1415926535897932385L);

int main() {
  static_assert(pi<int> == 3, "conversion follows the selected type");
  assert(pi<double> > 3.14 && pi<double> < 3.15);
}
