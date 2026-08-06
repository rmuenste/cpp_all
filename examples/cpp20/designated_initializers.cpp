#include <cassert>

struct Options {
  int retries = 3;
  bool verbose = false;
};

int main() {
  Options options{.retries = 5, .verbose = true};
  assert(options.retries == 5 && options.verbose);
}
