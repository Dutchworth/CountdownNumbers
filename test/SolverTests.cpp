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

// TEST_F(SolverTests, testPossSolutions) {
//   std::vector<std::stack<Element> > possSolsTemp =
//     Solver::possSolutions(nums2, 2);
//   std::vector<std::vector<Element> > possSols;
//
//   for (auto each : possSolsTemp) {
//     possSols.push_back(RpnUtils::convertToVect(each));
//   }
//
//   EXPECT_EQ(eqs2, possSols);
// }

// TEST_F(SolverTests, testSolveSimple) {
//   std::vector<Element> expected { { Element(5), Element(4), Element(MINUS) }
// };
//   std::vector<Element> actual;
//
//   EXPECT_TRUE(Solver::solve(nums2, 1, actual));
//   EXPECT_EQ(expected, actual);
// }

TEST_F(SolverTests, testSolveHard) {
  std::vector<int> input { { 100, 75, 4, 5, 2, 1 } };
  int target = 870;

  std::vector<Element> solution;
  EXPECT_TRUE(Solver::solve(input, target, solution));

  for (auto each: solution) {
    std::cout << each << ' ';
  }
  std::cout << std::endl;
}

TEST_F(SolverTests, testSolveHarder) {
  std::vector<int> input { { 50, 25, 100, 75, 8, 7 } };
  int target = 252;

  std::vector<Element> solution;
  EXPECT_TRUE(Solver::solve(input, target, solution));

  for (auto each: solution) {
    std::cout << each << ' ';
  }
  std::cout << std::endl;
}
