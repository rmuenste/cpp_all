// Exercise (C++11): Encode unsigned packet fields.
// Size a packet buffer at compile time and restrict a wire encoder to unsigned
// integers.
//
// Tasks:
// 1. Implement constexpr payload_bytes(size_t samples), returning samples * 2 for
//    16-bit samples. Use the C++11 single-return constexpr form; assume no overflow.
// 2. Implement encode_unsigned(T) returning sizeof(T) bytes in little-endian order,
//    independent of host byte order.
// 3. Inside the encoder, use static_assert and type traits to accept only unsigned
//    integral types, excluding bool. Reject floating-point and signed types at compile
//    time.
//
// Checks: Check constant-expression array sizing, byte order, zero encoding, and
// compile-time rejection by temporarily uncommenting the invalid calls.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONSTEXPR_TRAITS=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_constexpr_traits
// ctest --preset gcc-debug -R '^exercise_cpp11_constexpr_traits$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONSTEXPR_TRAITS=OFF

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <vector>

// TODO: Define the constexpr function and constrained encoder.
constexpr std::size_t payload_bytes(std::size_t samples);
template <typename T>
std::vector<unsigned char> encode_unsigned(T value);

int main() {
    static_assert(payload_bytes(3) == 6, "three 16-bit samples");
    static_assert(payload_bytes(0) == 0, "empty payload");
    std::array<unsigned char, payload_bytes(3)> payload{};
    assert(payload.size() == 6);
    const auto bytes = encode_unsigned(std::uint32_t{0x12345678u});
    assert((bytes == std::vector<unsigned char>{0x78, 0x56, 0x34, 0x12}));
    assert((encode_unsigned(std::uint16_t{0}) == std::vector<unsigned char>{0, 0}));
    // These must each fail to compile when uncommented:
    // encode_unsigned(-1);
    // encode_unsigned(1.5);
    // encode_unsigned(true);
}
