#include <array>
#include <cassert>
#include <cstddef>

template <typename Left, typename Right>
struct Sum {
  const Left& left;
  const Right& right;
  double operator[](std::size_t index) const { return left[index] + right[index]; }
};

struct Vector {
  std::array<double, 3> values;
  double operator[](std::size_t index) const { return values[index]; }
  template <typename Expression>
  Vector& operator=(const Expression& expression) {
    for (std::size_t i = 0; i < values.size(); ++i) values[i] = expression[i];
    return *this;
  }
};

template <typename Left, typename Right>
Sum<Left, Right> operator+(const Left& left, const Right& right) { return {left, right}; }

int main() {
  Vector first{{1, 2, 3}};
  Vector second{{4, 5, 6}};
  Vector result{{0, 0, 0}};
  result = first + second; // Evaluated directly into result without a temporary Vector.
  assert(result[0] == 5 && result[2] == 9);
}
