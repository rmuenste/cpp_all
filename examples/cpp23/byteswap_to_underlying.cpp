#include <bit>
#include <cassert>
#include <cstdint>
#include <utility>

enum class Permission : std::uint16_t { read = 0x0001 };

int main() {
  static_assert(std::byteswap(std::uint16_t{0x1234}) == 0x3412);
  static_assert(std::to_underlying(Permission::read) == 1);
  assert(std::to_underlying(Permission::read) == 1);
}
