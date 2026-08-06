#include <cassert>
#include <type_traits>

struct Identified { int id = 7; };
struct Named { const char* name = "example"; };

template <typename... Features>
struct Entity : Features... {};

int main() {
  Entity<Identified, Named> entity;
  static_assert(std::is_base_of_v<Identified, decltype(entity)>);
  assert(entity.id == 7 && entity.name[0] == 'e');
}
