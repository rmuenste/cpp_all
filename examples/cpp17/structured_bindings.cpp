#include <cassert>
#include <map>
#include <string>
#include <tuple>

int main() {
  const auto record = std::make_tuple(7, std::string{"Ada"});
  const auto& [id, name] = record;
  assert(id == 7 && name == "Ada");

  std::map<std::string, int> scores{{"C++", 20}};
  for (const auto& [language, score] : scores) {
    assert(language == "C++" && score == 20);
  }
}
