#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <numeric>
#include <vector>

class Scores {
 public:
  Scores(std::initializer_list<int> values) : values_(values) {}
  int total() const { return std::accumulate(values_.begin(), values_.end(), 0); }

 private:
  std::vector<int> values_;
};

int main() {
  Scores scores{10, 20, 30};
  int exact{42};
  // int narrowed{3.5}; // Error: braced initialization rejects narrowing.
  assert(scores.total() == 60 && exact == 42);
}
