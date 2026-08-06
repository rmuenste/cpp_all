function(add_cpp_example name standard source)
  add_executable(${name} ${source})
  target_compile_features(${name} PRIVATE cxx_std_${standard})
  set_target_properties(${name} PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )

  if(MSVC)
    target_compile_options(${name} PRIVATE /W4)
    if(CPP_ALL_WARNINGS_AS_ERRORS)
      target_compile_options(${name} PRIVATE /WX)
    endif()
  else()
    target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
    if(CPP_ALL_WARNINGS_AS_ERRORS)
      target_compile_options(${name} PRIVATE -Werror)
    endif()
  endif()

  if(BUILD_TESTING)
    add_test(NAME ${name} COMMAND ${name})
    set_tests_properties(${name} PROPERTIES LABELS "cpp${standard}")
  endif()
endfunction()
