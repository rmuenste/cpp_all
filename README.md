# cpp_all

Small, independently runnable examples of important C++ features introduced
from C++11 through C++23, followed by a focused template-programming track.
The collection assumes familiarity with core C++ syntax and RAII.

## Build and test

```sh
cmake --preset gcc-debug
cmake --build --preset gcc-debug
ctest --preset gcc-debug
```

Replace `gcc-debug` with `clang-debug` to use Clang. Build one lesson with
`cmake --build --preset gcc-debug --target cpp17_structured_bindings`, then run
the executable from the matching folder below `build/gcc-debug`.

Every lesson is a separate executable. Compile-time claims use `static_assert`;
runtime claims use `assert` and small amounts of output. There are no external
dependencies and compiler extensions are disabled.

## Contents

- [C++11–23 examples](examples/README.md)
- [Template programming](templates/README.md)
- [Programming exercises](exercises/README.md)

The set is intentionally curated rather than exhaustive. Modules and library
facilities with uneven support in the baseline GCC 13/Clang 18 environment are
listed as future work instead of being represented by non-portable examples.
