cmake_minimum_required(VERSION 2.8)

project(SourceSubdir)

set (MAIN_SOURCES
  Element.cpp
  ElementHelpers.cpp
  RpnUtils.cpp
  StatsUtils.cpp
  Solver.cpp
  ArgUtils.cpp
)

add_library(sourceLib ${MAIN_SOURCES})
