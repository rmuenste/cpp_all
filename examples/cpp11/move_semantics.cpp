#include <cassert>
#include <string>
#include <utility>

class Buffer {
 public:
  explicit Buffer(std::string data) : data_(std::move(data)) {}
  Buffer(Buffer&&) = default;
  Buffer& operator=(Buffer&&) = default;
  Buffer(const Buffer&) = delete;
  const std::string& data() const { return data_; }

 private:
  std::string data_;
};

int main() {
  Buffer source{"payload"};
  Buffer destination{std::move(source)};
  assert(destination.data() == "payload");
  // A moved-from object remains valid, but its value is generally unspecified.
}
