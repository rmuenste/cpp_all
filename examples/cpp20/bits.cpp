#include <bit>
#include <cassert>
#include <cstdint>

int main() {
  static_assert(std::has_single_bit(8u));
  static_assert(std::bit_width(8u) == 4);
  static_assert(std::rotl(std::uint8_t{1}, 2) == 4);
  assert(std::endian::native == std::endian::little ||
         std::endian::native == std::endian::big);
}
