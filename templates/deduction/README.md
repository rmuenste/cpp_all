# Deduction and constraints

Recommended order:

1. `templates_argument_deduction`
2. `templates_reference_collapsing`
3. `templates_specialization`
4. `templates_template_template`
5. `templates_enable_if`
6. `templates_detection_idiom`
7. `templates_constraints_comparison`
8. `templates_tag_dispatch`

The final four targets compare techniques for choosing an implementation.
Concepts are generally preferred for public constraints; SFINAE and tag
dispatch remain important when reading older libraries or customizing internals.
