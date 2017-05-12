cmake_minimum_required(VERSION 2.8)

project(TestSubdir)

set(TEST_SOURCES
  RunAllTests.cpp
  ElementTests.cpp
  ElementHelpersTests.cpp
  RpnUtilsTests.cpp
  StatsUtilsTests.cpp
  SolverTests.cpp
  ArgUtilsTests.cpp
)

include_directories(${SourceSubdir_SOURCE_DIR})

add_executable(CountdownNumbers-runUnitTests ${TEST_SOURCES})
target_link_libraries(CountdownNumbers-runUnitTests sourceLib gtest gtest_main)
