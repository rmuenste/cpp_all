#include <cassert>

template <typename Derived>
class Counter {
 public:
  void increment() { ++static_cast<Derived&>(*this).value; }
};

struct Score : Counter<Score> { int value = 0; };

int main() {
  Score score;
  score.increment();
  score.increment();
  assert(score.value == 2);
}
