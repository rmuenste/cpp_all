#include <cassert>
#include <cstddef>

enum class Color { red, green, blue };

bool is_null(const int* pointer) { return pointer == nullptr; }

int main() {
  int* pointer = nullptr;
  Color color = Color::green;
  assert(is_null(pointer));
  assert(color != Color::red);
  static_assert(sizeof(nullptr) == sizeof(std::nullptr_t), "nullptr has its own type");
}
