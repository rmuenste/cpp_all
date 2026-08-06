#include <cassert>
#include <filesystem>

int main() {
  const std::filesystem::path path = std::filesystem::path{"examples"} / "cpp17" / "demo.cpp";
  assert(path.filename() == "demo.cpp");
  assert(path.extension() == ".cpp");
  assert(path.parent_path().filename() == "cpp17");
}
