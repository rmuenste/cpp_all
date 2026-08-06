#include <cassert>
#include <memory>
#include <string>

struct Record {
  Record(int id, std::string name) : id(id), name(std::move(name)) {}
  int id;
  std::string name;
};

int main() {
  auto record = std::make_unique<Record>(7, "Ada");
  assert(record->id == 7 && record->name == "Ada");
}
