#include <atomic>
#include <cassert>
#include <future>
#include <mutex>
#include <thread>

int main() {
  std::mutex mutex;
  int protected_value = 0;
  std::atomic<int> atomic_value{0};
  std::thread worker([&] {
    std::lock_guard<std::mutex> lock(mutex);
    protected_value = 21;
    atomic_value.store(21);
  });
  worker.join();

  auto future = std::async(std::launch::async, [] { return 21; });
  assert(protected_value + atomic_value.load() + future.get() == 63);
}
