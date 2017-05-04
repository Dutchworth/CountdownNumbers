#include "gtest/gtest.h"
#include "Solver.h"
#include "Element.h"
#include "ElementHelpers.h"
#include "RpnUtils.h"
#include "SolverTestsValues.h"
#include <vector>
#include <iostream>

class SolverTests : public ::testing::Test {
protected:

  std::vector<int>nums2 = testValues::nums2;

  std::vector<std::vector<Element> >eqs2 = testValues::eqs2;


  virtual void SetUp()    {}

  virtual void TearDown() {}
};

TEST_F(SolverTests, testSolveSimple) {
  std::vector<Element> expected { { Element(5), Element(4), Element(MINUS) } };
  std::vector<Element> actual;

  EXPECT_TRUE(Solver::solve(nums2, 1, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testSolve2Large) {
  std::vector<int> input { { 100, 75, 4, 5, 2, 1 } };
  int target = 870;

  // 5 * (75 - 1 + 100)
  std::vector<Element> expected { { Element(5),
                                    Element(75),
                                    Element(1),
                                    Element(MINUS),
                                    Element(100),
                                    Element(PLUS),
                                    Element(MULTIPLY) } };
  std::vector<Element> actual;
  EXPECT_TRUE(Solver::solve(input, target, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testSolve4Large) {
  std::vector<int> input { { 50, 25, 100, 75, 8, 7 } };
  int target = 252;

  // 7 * (8 + 100) * 25 / 75
  std::vector<Element> expected { { Element(7),
                                    Element(8),
                                    Element(100),
                                    Element(PLUS),
                                    Element(25),
                                    Element(MULTIPLY),
                                    Element(75),
                                    Element(DIVIDE),
                                    Element(MULTIPLY) } };
  std::vector<Element> actual;
  EXPECT_TRUE(Solver::solve(input, target, actual));
  EXPECT_EQ(expected, actual);
}

TEST_F(SolverTests, testSolveNoLarge) {
  std::vector<int> input { { 8, 7, 2, 1, 10, 1 } };
  int target = 832;

  // (1 + 2 + 10) * (1 + 7) * 8
  std::vector<Element> expected { { Element(1),
                                    Element(2),
                                    Element(10),
                                    Element(PLUS),
                                    Element(PLUS),
                                    Element(1),
                                    Element(7),
                                    Element(PLUS),
                                    Element(8),
                                    Element(MULTIPLY),
                                    Element(MULTIPLY) } };
  std::vector<Element> actual;

  EXPECT_TRUE(Solver::solve(input, target, actual));
  EXPECT_EQ(expected, actual);
}
