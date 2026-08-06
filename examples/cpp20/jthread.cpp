#include <atomic>
#include <cassert>
#include <thread>

int main() {
  std::atomic<int> iterations{0};
  std::jthread worker([&](std::stop_token stop) {
    while (!stop.stop_requested()) ++iterations;
  });
  worker.request_stop();
  worker.join();
  assert(iterations.load() >= 0);
}
