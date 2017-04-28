cmake_minimum_required(VERSION 2.8)

project(TestSubdir)

set(TEST_SOURCES
  RunAllTests.cpp
  ElementTests.cpp
)

include_directories(${SourceSubdir_SOURCE_DIR})

add_executable(runUnitTests ${TEST_SOURCES})
target_link_libraries(runUnitTests sourceLib gtest gtest_main)
