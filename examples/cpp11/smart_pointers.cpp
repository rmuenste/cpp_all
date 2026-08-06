#include <cassert>
#include <memory>

int main() {
  std::unique_ptr<int> unique(new int(7));
  std::unique_ptr<int> transferred = std::move(unique);
  assert(!unique && *transferred == 7);

  std::shared_ptr<int> shared = std::make_shared<int>(9);
  std::weak_ptr<int> observer = shared;
  {
    std::shared_ptr<int> second_owner = observer.lock();
    assert(second_owner && shared.use_count() == 2);
  }
  assert(shared.use_count() == 1);
}
