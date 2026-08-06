#include <array>
#include <cassert>
#include <cstddef>

struct Matrix {
  std::array<int, 6> values{};
  int& operator[](std::size_t row, std::size_t column) { return values[row * 3 + column]; }
  const int& operator[](std::size_t row, std::size_t column) const { return values[row * 3 + column]; }
};

int main() {
  Matrix matrix;
  matrix[1, 2] = 42;
  assert((matrix[1, 2] == 42));
}
