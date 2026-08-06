#include <barrier>
#include <cassert>
#include <latch>
#include <semaphore>
#include <thread>

int main() {
  std::latch ready{1};
  std::binary_semaphore may_run{0};
  std::barrier phase{2};
  int value = 0;

  std::jthread worker([&] {
    ready.count_down();
    may_run.acquire();
    value = 42;
    phase.arrive_and_wait();
  });
  ready.wait();
  may_run.release();
  phase.arrive_and_wait();
  assert(value == 42);
}
