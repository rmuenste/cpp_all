// Exercise (C++11): Own jobs and share queue configuration.
// A queue exclusively owns submitted jobs while keeping shared configuration alive.
//
// Tasks:
// 1. Implement JobQueue with a shared_ptr<const Config> and a vector<unique_ptr<Job>>.
//    Add a constructor accepting the shared configuration.
// 2. Implement submit(unique_ptr<Job>) to take ownership and append the job. Assume
//    non-null jobs and configuration.
// 3. Implement run_next() to remove the oldest job and return config.prefix + job.name.
//    Throw out_of_range if the queue is empty.
// 4. Use unique_ptr and make_shared with C++11 syntax; do not use raw owning pointers
//    or make_unique. The weak observer must expire after the queue releases the last
//    shared owner.
//
// Checks: Check ownership transfer, FIFO order, empty-queue errors, and configuration
// lifetime through weak_ptr.
// The starter is intentionally unfinished and will not compile or link yet.
//
// Enable, build, and test from the repository root:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_SMART_POINTERS=ON
// cmake --build --preset gcc-debug --target exercise_cpp11_smart_pointers
// ctest --preset gcc-debug -R '^exercise_cpp11_smart_pointers$'
//
// Disable again:
// cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_SMART_POINTERS=OFF

#include <cassert>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

struct Config { std::string prefix; };
struct Job { std::string name; };

class JobQueue {
public:
    explicit JobQueue(std::shared_ptr<const Config> config);
    void submit(std::unique_ptr<Job> job);
    std::string run_next();
    // TODO: Add ownership members and implement the operations above.
};

int main() {
    auto config = std::make_shared<Config>(Config{"run: "});
    std::weak_ptr<const Config> observer = config;
    {
        JobQueue queue(config);
        config.reset();
        assert(!observer.expired());
        std::unique_ptr<Job> job(new Job{"index"});
        queue.submit(std::move(job));
        assert(!job);
        queue.submit(std::unique_ptr<Job>(new Job{"upload"}));
        assert(queue.run_next() == "run: index");
        assert(queue.run_next() == "run: upload");
        bool empty = false;
        try { queue.run_next(); }
        catch (const std::out_of_range&) { empty = true; }
        assert(empty);
    }
    assert(observer.expired());
}
