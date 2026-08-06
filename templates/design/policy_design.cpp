#include <cassert>

struct Clamp {
  static int apply(int value) { return value < 0 ? 0 : (value > 100 ? 100 : value); }
};

struct Reject {
  static int apply(int value) { return (value >= 0 && value <= 100) ? value : -1; }
};

template <typename ValidationPolicy>
class Percentage {
 public:
  explicit Percentage(int value) : value_(ValidationPolicy::apply(value)) {}
  int value() const { return value_; }
 private:
  int value_;
};

int main() {
  assert(Percentage<Clamp>{120}.value() == 100);
  assert(Percentage<Reject>{120}.value() == -1);
}
