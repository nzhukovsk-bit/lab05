cmake_minimum_required(VERSION 3.10)
project(banking VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB ${PROJECT_NAME}_SOURCES src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} gtest_main gmock_main)
  add_test(NAME check COMMAND check)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  if(BUILD_TESTS)
    target_compile_options(check PRIVATE --coverage -O0 -g)
    target_link_libraries(check PRIVATE --coverage)
    
    add_custom_target(coverage
      COMMAND lcov --capture --directory . --output-file coverage.info
      COMMAND lcov --remove coverage.info '/usr/*' '${CMAKE_CURRENT_SOURCE_DIR}/third-party/*' --output-file coverage.info
      COMMAND lcov --list coverage.info
      COMMAND genhtml coverage.info --output-directory coverage_report
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMENT "Generating coverage report"
    )
  endif()
endif()
