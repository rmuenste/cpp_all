# Configure a retry schedule

Accept a short list of retry delays while rejecting invalid configuration.

## Tasks

1. Implement RetrySchedule with an initializer_list<int> constructor storing delays in milliseconds in a vector<int>. Reject any negative delay with invalid_argument.
2. Expose size() const and total_ms() const. An empty schedule has size and total zero. Assume totals fit in int.
3. In main(), initialize repeated with three copies of 100 using the vector count/value constructor, and explicit_delays with the two values 3 and 100 using braces.

## Checks

Check list construction, empty and invalid schedules, and the difference between vector count/value and initializer-list construction.

Complete [initialization.cpp](initialization.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_INITIALIZATION=ON
cmake --build --preset gcc-debug --target exercise_cpp11_initialization
ctest --preset gcc-debug -R '^exercise_cpp11_initialization$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_INITIALIZATION=OFF
```
