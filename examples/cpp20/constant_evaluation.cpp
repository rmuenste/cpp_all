#include <cassert>
#include <type_traits>

consteval int compile_time_square(int value) { return value * value; }
constexpr int context() { return std::is_constant_evaluated() ? 1 : 2; }
constinit int initialized_at_compile_time = compile_time_square(3);

int main() {
  constexpr int compile_time = context();
  int runtime = context();
  static_assert(compile_time_square(6) == 36);
  assert(compile_time == 1 && runtime == 2 && initialized_at_compile_time == 9);
}
