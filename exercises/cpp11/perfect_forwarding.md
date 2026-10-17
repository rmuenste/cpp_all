# Construct owned objects through a factory

A generic owning factory must preserve constructor arguments and support move-only resources.

## Tasks

1. Implement make_owned<T>(Args&&...) returning unique_ptr<T>, using new T(...) and std::forward for each constructor argument.
2. Keep the factory generic: it must handle zero arguments, lvalues, rvalues, and a unique_ptr passed by move.
3. Use C++11 facilities only. Batch records the selected constructor so the assertions can detect lost value categories.

## Checks

Check copy-path versus move-path overload selection, empty construction, and move-only ownership transfer.

Complete [perfect_forwarding.cpp](perfect_forwarding.cpp). The starter includes these tasks and
assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_PERFECT_FORWARDING=ON
cmake --build --preset gcc-debug --target exercise_cpp11_perfect_forwarding
ctest --preset gcc-debug -R '^exercise_cpp11_perfect_forwarding$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP11_PERFECT_FORWARDING=OFF
```
