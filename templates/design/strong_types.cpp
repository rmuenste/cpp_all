#include <cassert>

struct MetersTag {};
struct SecondsTag {};

template <typename T, typename Tag>
class Strong {
 public:
  explicit Strong(T value) : value_(value) {}
  T value() const { return value_; }
 private:
  T value_;
};

using Meters = Strong<double, MetersTag>;
using Seconds = Strong<double, SecondsTag>;

int main() {
  const Meters distance{100.0};
  const Seconds duration{9.58};
  // distance = duration; // Error: tags make these distinct types.
  assert(distance.value() / duration.value() > 10.0);
}
