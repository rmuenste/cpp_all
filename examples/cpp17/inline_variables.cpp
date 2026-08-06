#include <cassert>

struct Configuration {
  inline static int instances = 0;
  static constexpr const char* name = "cpp_all";
};

int main() {
  ++Configuration::instances;
  assert(Configuration::instances == 1);
  assert(Configuration::name[0] == 'c');
}
