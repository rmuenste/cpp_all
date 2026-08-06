#include <cassert>
#include <iterator>
#include <list>
#include <vector>

template <typename Iterator>
void advance_by(Iterator& iterator, int distance, std::random_access_iterator_tag) {
  iterator += distance;
}

template <typename Iterator>
void advance_by(Iterator& iterator, int distance, std::input_iterator_tag) {
  while (distance-- > 0) ++iterator;
}

template <typename Iterator>
void advance_by(Iterator& iterator, int distance) {
  using Category = typename std::iterator_traits<Iterator>::iterator_category;
  advance_by(iterator, distance, Category{});
}

int main() {
  std::vector<int> vector{1, 2, 3};
  auto vector_it = vector.begin();
  advance_by(vector_it, 2);
  std::list<int> list{4, 5, 6};
  auto list_it = list.begin();
  advance_by(list_it, 2);
  assert(*vector_it == 3 && *list_it == 6);
}
