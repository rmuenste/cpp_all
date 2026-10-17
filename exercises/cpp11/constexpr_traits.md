# Encode unsigned packet fields

Size a packet buffer at compile time and restrict a wire encoder to unsigned integers.

## Tasks

1. Implement constexpr payload_bytes(size_t samples), returning samples * 2 for 16-bit samples. Use the C++11 single-return constexpr form; assume no overflow.
2. Implement encode_unsigned(T) returning sizeof(T) bytes in little-endian order, independent of host byte order.
3. Inside the encoder, use static_assert and type traits to accept only unsigned integral types, excluding bool. Reject floating-point and signed types at compile time.

## Checks

Check constant-expression array sizing, byte order, zero encoding, and compile-time rejection by temporarily uncommenting the invalid calls.

Complete [constexpr_traits.cpp](constexpr_traits.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONSTEXPR_TRAITS=ON
cmake --build --preset gcc-debug --target exercise_cpp11_constexpr_traits
ctest --preset gcc-debug -R '^exercise_cpp11_constexpr_traits$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_CONSTEXPR_TRAITS=OFF
```
