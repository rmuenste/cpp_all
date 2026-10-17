# Programming exercises

Short exercises grouped by the C++ standard they require. Each exercise describes
the task and provides a usage example or checks, leaving the implementation to you.

## C++11

- [Move semantics: transfer ownership of a large buffer](cpp11/move_semantics.md)

Each exercise includes a Markdown task, an unfinished `.cpp` file alongside it,
and instructions to enable, build, and test its CMake target. Unfinished starters
are expected not to compile until implemented. Each exercise defaults to off so
it does not interrupt the normal build or test run.

## Adding an exercise

1. Put the task and starter in `exercises/cpp<standard>/<topic>.md` and `.cpp`.
   Begin the `.cpp` with comments containing the exercise's purpose, numbered
   tasks, expected checks, and exact configure, build, test, and disable commands.
   Keep these comments consistent with the Markdown task so the exercise can be
   completed without switching files.
2. Register it in that directory's `CMakeLists.txt`:

   ```cmake
   add_cpp_exercise(exercise_cpp11_topic 11 topic.cpp)
   ```

3. For a new standard directory, add `add_subdirectory(cpp<standard>)` to
   `exercises/CMakeLists.txt`.
4. Link the task here and include its exact configure, build, and test commands
   in the task. The helper creates an opt-in option named `BUILD_` followed by
   the uppercase target name, such as `BUILD_EXERCISE_CPP11_TOPIC`.

Enabled exercises use the same compiler warnings and CTest registration as the
examples. Use a Debug preset so the starter's assertions are active.
