#include <cassert>
#include <map>
#include <string>

int main() {
  const std::map<std::string, int> versions{{"C++", 17}};
  if (const auto found = versions.find("C++"); found != versions.end()) {
    assert(found->second == 17);
  } else {
    assert(false);
  }

  switch (const int remainder = 7 % 3; remainder) {
    case 1: break;
    default: assert(false);
  }
}
