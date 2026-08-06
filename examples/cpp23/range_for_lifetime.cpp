#include <cassert>
#include <vector>

struct Holder {
  std::vector<int> values;
  const std::vector<int>& get() const { return values; }
};

Holder make_holder() { return {{1, 2, 3}}; }

int main() {
  int sum = 0;
#if defined(__cpp_range_based_for) && __cpp_range_based_for >= 202211L
  // C++23 extends the intermediate temporary Holder's lifetime through the loop.
  for (int value : make_holder().get()) sum += value;
#else
  // Safe spelling for compilers that accept C++23 but have not implemented P2718.
  for (Holder holder = make_holder(); int value : holder.get()) sum += value;
#endif
  assert(sum == 6);
}
