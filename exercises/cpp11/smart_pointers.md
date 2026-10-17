# Own jobs and share queue configuration

A queue exclusively owns submitted jobs while keeping shared configuration alive.

## Tasks

1. Implement JobQueue with a shared_ptr<const Config> and a vector<unique_ptr<Job>>. Add a constructor accepting the shared configuration.
2. Implement submit(unique_ptr<Job>) to take ownership and append the job. Assume non-null jobs and configuration.
3. Implement run_next() to remove the oldest job and return config.prefix + job.name. Throw out_of_range if the queue is empty.
4. Use unique_ptr and make_shared with C++11 syntax; do not use raw owning pointers or make_unique. The weak observer must expire after the queue releases the last shared owner.

## Checks

Check ownership transfer, FIFO order, empty-queue errors, and configuration lifetime through weak_ptr.

Complete [smart_pointers.cpp](smart_pointers.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_SMART_POINTERS=ON
cmake --build --preset gcc-debug --target exercise_cpp11_smart_pointers
ctest --preset gcc-debug -R '^exercise_cpp11_smart_pointers$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_SMART_POINTERS=OFF
```
