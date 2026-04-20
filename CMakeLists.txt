cmake_minimum_required(VERSION 3.10)
project(banking VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

# Отключаем предупреждения как ошибки для Google Test
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 OLD)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
file(GLOB BANKING_SOURCES src/*.cpp)
add_library(banking STATIC ${BANKING_SOURCES})

# Tests
if(BUILD_TESTS)
  enable_testing()
  
  # Отключаем флаги -Werror для Google Test
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
  
  # Google Test
  add_subdirectory(third-party/gtest)
  
  # Восстанавливаем флаги для нашего кода
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")
  
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests)
  
  # Test executable
  file(GLOB TEST_SOURCES tests/*.cpp)
  add_executable(check ${TEST_SOURCES})
  
  # Link libraries
  target_link_libraries(check banking gtest_main gmock_main pthread)
  
  add_test(NAME check COMMAND check)
  
  # Coverage support
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(check PRIVATE --coverage -O0 -g)
    target_link_options(check PRIVATE --coverage)
    
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
