// Exercise (C++14): Export a tuple of metrics as numeric samples.
// Convert a fixed tuple of differently typed measurements into an ordered array of
// doubles.
//
// Tasks:
// 1. Implement constexpr to_samples_impl(const Tuple&, index_sequence<I...>), returning
//    array<double, sizeof...(I)>. Convert each selected tuple element to double in
//    index order.
// 2. Implement constexpr to_samples(const tuple<Ts...>&), returning array<double,
//    sizeof...(Ts)>. Generate indices for the entire tuple with make_index_sequence and
//    pass them to the helper.
// 3. Handle an empty tuple and repeated element types. Use index-pack expansion rather
//    than recursion, runtime indexing, std::apply, or fold expressions.
//
// Background:
// - index_sequence<I...> encodes size_t constants in a type. make_index_sequence<N>
//   names index_sequence<0, 1, ..., N-1>, with an empty sequence for N == 0.
// - std::get<I>(tuple) requires a compile-time index; a runtime loop variable cannot
//   supply I.
// - A trailing ... expands its whole preceding pattern once per pack element. For
//   example, tag<I>{}... conceptually becomes tag<0>{}, tag<1>{}, tag<2>{} for indices
//   0, 1, 2. No manual extraction of the first index is needed.
// - std::array is an aggregate containing its element storage. Double braces can
//   initialize the aggregate and that storage; an empty expansion must also be valid.
//
// Checks: Check compile-time conversion, field order, repeated types, empty input, and
// that the exported array is an independent snapshot.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_INTEGER_SEQUENCE=ON
// cmake --build --preset gcc-debug --target exercise_cpp14_integer_sequence
// ctest --preset gcc-debug -R '^exercise_cpp14_integer_sequence$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_INTEGER_SEQUENCE=OFF

#include <array>
#include <cassert>
#include <cstddef>
#include <tuple>
#include <utility>

// TODO: Define the helper first, then the public conversion template.
template <typename Tuple, std::size_t... I>
constexpr std::array<double, sizeof...(I)> to_samples_impl(
    const Tuple& metrics, std::index_sequence<I...>);

template <typename... Ts>
constexpr std::array<double, sizeof...(Ts)> to_samples(const std::tuple<Ts...>& metrics);

int main() {
    constexpr auto samples = to_samples(std::tuple<int, float, double>{7, 0.5f, 12.25});
    static_assert(samples.size() == 3, "one sample per field");
    static_assert(samples[0] == 7.0 && samples[1] == 0.5 && samples[2] == 12.25,
                  "compile-time conversion preserves order");
    const auto repeated = to_samples(std::tuple<int, int>{4, 9});
    assert(repeated[0] == 4.0 && repeated[1] == 9.0);
    constexpr auto empty = to_samples(std::tuple<>{});
    static_assert(empty.size() == 0, "empty row");
    auto row = std::make_tuple(3, 2.5);
    const auto snapshot = to_samples(row);
    std::get<0>(row) = 99;
    assert(snapshot[0] == 3.0 && snapshot[1] == 2.5);
}
