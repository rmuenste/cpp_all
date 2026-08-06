# Compile-time programming

The examples move from value packs to type-level data and validation:
`templates_recursive_vs_fold`, `templates_type_list`,
`templates_tuple_iteration`, `templates_compile_time_lookup`,
`templates_state_machine`, and `templates_dependent_names`.

Prefer direct `constexpr` code when it expresses the problem. Type-level
machinery is most useful when the output itself must be a type or when an
invalid program should be rejected during compilation.
