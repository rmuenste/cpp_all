# Register each unfinished exercise behind its own opt-in build option.
function(add_cpp_exercise name standard source)
  string(TOUPPER "BUILD_${name}" build_option)
  option(${build_option} "Build and test the ${name} exercise" OFF)
  if(${build_option})
    add_cpp_example(${name} ${standard} ${source})
  endif()
endfunction()
