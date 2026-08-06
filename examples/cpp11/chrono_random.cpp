#include <cassert>
#include <chrono>
#include <random>

int main() {
  const std::chrono::milliseconds duration{1500};
  assert(std::chrono::duration_cast<std::chrono::seconds>(duration).count() == 1);

  std::mt19937 first(1234);
  std::mt19937 second(1234);
  assert(first() == second()); // Engines are deterministic for the same seed.
}
