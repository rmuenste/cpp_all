#include <cassert>
#include <set>
#include <string>

int main() {
  std::set<std::string, std::less<>> names{"Ada", "Bjarne", "Grace"};
  // The transparent comparator can compare without constructing a std::string.
  const auto found = names.find("Grace");
  assert(found != names.end() && *found == "Grace");
}
