add_cpp_example(cpp23_if_consteval 23 if_consteval.cpp)
add_cpp_example(cpp23_static_call_operator 23 static_call_operator.cpp)
add_cpp_example(cpp23_multidimensional_subscript 23 multidimensional_subscript.cpp)
add_cpp_example(cpp23_decay_copy 23 decay_copy.cpp)
add_cpp_example(cpp23_range_for_lifetime 23 range_for_lifetime.cpp)
add_cpp_example(cpp23_optional_monadic 23 optional_monadic.cpp)
add_cpp_example(cpp23_byteswap_to_underlying 23 byteswap_to_underlying.cpp)
add_cpp_example(cpp23_string_contains_spanstream 23 string_contains_spanstream.cpp)

include(CheckCXXSourceCompiles)
include(CMakePushCheckState)
cmake_push_check_state(RESET)
if(MSVC)
  set(CMAKE_REQUIRED_FLAGS "/std:c++latest")
else()
  set(CMAKE_REQUIRED_FLAGS "-std=c++23")
endif()
check_cxx_source_compiles(
  "struct X { int value; int get(this X const& self) { return self.value; } }; int main() { return X{0}.get(); }"
  CPP_ALL_HAS_EXPLICIT_THIS_PARAMETER
)
cmake_pop_check_state()

if(CPP_ALL_HAS_EXPLICIT_THIS_PARAMETER)
  add_cpp_example(cpp23_explicit_object_parameter 23 explicit_object_parameter.cpp)
else()
  message(STATUS "Skipping cpp23_explicit_object_parameter: compiler does not support deducing this")
endif()

cmake_push_check_state(RESET)
if(MSVC)
  set(CMAKE_REQUIRED_FLAGS "/std:c++latest")
else()
  set(CMAKE_REQUIRED_FLAGS "-std=c++23")
endif()
check_cxx_source_compiles(
  "#include <expected>\nint main() { std::expected<int, int> value = 42; return value.value(); }"
  CPP_ALL_HAS_STD_EXPECTED
)
cmake_pop_check_state()

if(CPP_ALL_HAS_STD_EXPECTED)
  add_cpp_example(cpp23_expected 23 expected.cpp)
else()
  message(STATUS "Skipping cpp23_expected: standard library/compiler combination does not provide std::expected")
endif()
