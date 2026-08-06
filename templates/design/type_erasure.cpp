#include <cassert>
#include <memory>
#include <utility>

class Drawable {
  struct Concept { virtual ~Concept() = default; virtual int draw() const = 0; };
  template <typename T>
  struct Model final : Concept {
    explicit Model(T value) : value(std::move(value)) {}
    int draw() const override { return value.draw(); }
    T value;
  };

 public:
  template <typename T>
  Drawable(T value) : self_(new Model<T>(std::move(value))) {}
  int draw() const { return self_->draw(); }

 private:
  std::unique_ptr<Concept> self_;
};

struct Circle { int draw() const { return 1; } };
struct Square { int draw() const { return 4; } };

int main() {
  Drawable circle = Circle{};
  Drawable square = Square{};
  assert(circle.draw() + square.draw() == 5);
}
