#include <cassert>
#include <compare>

struct Version {
  int major;
  int minor;
  auto operator<=>(const Version&) const = default;
};

int main() {
  static_assert(Version{2, 0} > Version{1, 9});
  assert((Version{1, 2} == Version{1, 2}));
}
