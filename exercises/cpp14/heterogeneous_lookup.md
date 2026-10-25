# Find assets without constructing temporary keys

Index asset records by name while accepting lightweight C-string lookup keys.

## Tasks

1. Complete AssetLess with an is_transparent type alias and the three declared comparison
   overloads.

2. Compare names lexicographically for Asset/Asset, Asset/const char*, and const char*/Asset.
   The same name must compare equivalent regardless of the other fields.

3. Compare C-string probes directly with stored strings without creating temporary Asset or
   string objects. Assume probes are non-null, null-terminated strings and names contain no
   embedded nulls.

4. Keep the set and find calls unchanged: heterogeneous lookup must find a const char* key in a
   set of Asset objects.

## Background

- A transparent comparator advertises an is_transparent nested type. Its presence enables C++14
  associative-container lookup overloads for other key types.

- The marker does not implement comparison: the comparator must accept both stored-key/probe
  and probe/stored-key operands with one consistent strict weak ordering.

- std::string supports comparisons with C strings without first constructing another
  std::string. std::string_view is not available in C++14.

## Checks

Check successful and missing probes, lexical ordering, equal-name records, and empty keys.

Complete [heterogeneous_lookup.cpp](heterogeneous_lookup.cpp). The starter includes the tasks, background,
and assertions; it is intentionally unfinished and will not compile or link yet.

## Build and test

Run from the repository root:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_HETEROGENEOUS_LOOKUP=ON
cmake --build --preset gcc-debug --target exercise_cpp14_heterogeneous_lookup
ctest --preset gcc-debug -R '^exercise_cpp14_heterogeneous_lookup$'
```

Disable again when needed:

```sh
cmake --preset gcc-debug -DBUILD_EXERCISE_CPP14_HETEROGENEOUS_LOOKUP=OFF
```
