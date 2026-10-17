#include <cassert>
#include <string>
#include <utility>

class Buffer {
    public:

};

int main() {
    Buffer input(1'000'000); // Use 1000000 in C++11.
    Buffer output(10);

    output = std::move(input);

    std::vector<Buffer> results;
    results.push_back(std::move(output));

    // input and output are empty.
    // results[0] owns the original million-element array.
    return 0;
}