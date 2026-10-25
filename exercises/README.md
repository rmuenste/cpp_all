# Programming exercises

Short exercises grouped by the C++ standard they require. Each exercise describes
the task and provides a usage example or checks, leaving the implementation to you.

## C++11

| Topic | Exercise |
| --- | --- |
| `type_deduction` | [Look up and edit service settings](cpp11/type_deduction.md) |
| `strong_types` | [Format request log entries](cpp11/strong_types.md) |
| `initialization` | [Configure a retry schedule](cpp11/initialization.md) |
| `move_semantics` | [Transfer ownership of a large buffer](cpp11/move_semantics.md) |
| `smart_pointers` | [Own jobs and share queue configuration](cpp11/smart_pointers.md) |
| `lambdas` | [Summarize unpaid invoices](cpp11/lambdas.md) |
| `range_algorithms` | [Prepare a sale catalog](cpp11/range_algorithms.md) |
| `variadic_templates` | [Write a structured log line](cpp11/variadic_templates.md) |
| `perfect_forwarding` | [Construct owned objects through a factory](cpp11/perfect_forwarding.md) |
| `constexpr_traits` | [Encode unsigned packet fields](cpp11/constexpr_traits.md) |
| `class_controls` | [Define a noncopyable output sink](cpp11/class_controls.md) |
| `concurrency` | [Process a batch with two workers](cpp11/concurrency.md) |
| `chrono_random` | [Generate reproducible retry delays](cpp11/chrono_random.md) |

## C++14

| Topic | Exercise |
| --- | --- |
| `generic_lambdas` | [Order two dispatch queues with one comparator](cpp14/generic_lambdas.md) |
| `init_capture` | [Own a payload in a deferred upload](cpp14/init_capture.md) |
| `decltype_auto` | [Count calls without changing their results](cpp14/decltype_auto.md) |
| `variable_templates` | [Normalize unsigned image samples](cpp14/variable_templates.md) |
| `relaxed_constexpr` | [Choose a bounded buffer capacity](cpp14/relaxed_constexpr.md) |
| `make_unique` | [Allocate an owned scratch buffer](cpp14/make_unique.md) |
| `integer_sequence` | [Export a tuple of metrics as numeric samples](cpp14/integer_sequence.md) |
| `heterogeneous_lookup` | [Find assets without constructing temporary keys](cpp14/heterogeneous_lookup.md) |
| `literals_exchange` | [Read and clear buffered I/O state](cpp14/literals_exchange.md) |

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
   Include a short background note for unfamiliar syntax, especially how a pack
   expansion repeats a complete expression and pairs corresponding pack elements.
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
