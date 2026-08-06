#include <cassert>
#include <coroutine>
#include <utility>

class Generator {
 public:
  struct promise_type {
    int current{};
    Generator get_return_object() { return Generator{Handle::from_promise(*this)}; }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    std::suspend_always yield_value(int value) noexcept { current = value; return {}; }
    void return_void() noexcept {}
    void unhandled_exception() { throw; }
  };

  using Handle = std::coroutine_handle<promise_type>;
  explicit Generator(Handle handle) : handle_(handle) {}
  Generator(Generator&& other) noexcept : handle_(std::exchange(other.handle_, {})) {}
  Generator(const Generator&) = delete;
  ~Generator() { if (handle_) handle_.destroy(); }

  bool next() { handle_.resume(); return !handle_.done(); }
  int value() const { return handle_.promise().current; }

 private:
  Handle handle_;
};

Generator count_to(int limit) {
  for (int value = 1; value <= limit; ++value) co_yield value;
}

int main() {
  auto values = count_to(3);
  int sum = 0;
  while (values.next()) sum += values.value();
  assert(sum == 6);
}
