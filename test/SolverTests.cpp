#include "gtest/gtest.h"
#include "Solver.h"
#include "Element.h"
#include "ElementHelpers.h"
#include "RpnUtils.h"
#include "SolverTestsValues.h"
#include <vector>

class SolverTests : public ::testing::Test {
protected:

  std::vector<int>nums2 = testValues::nums2;

  std::vector<std::vector<Element> >eqs = testValues::eqs;


  virtual void SetUp() {}

  virtual void TearDown() {
    eqs.clear();
  }
};

TEST_F(SolverTests, testPossSolutions) {
  std::vector<std::stack<Element> > possSolsTemp =
    Solver::possSolutions(nums2, 2);
  std::vector<std::vector<Element> > possSols;

  for (auto each : possSolsTemp) {
    possSols.push_back(RpnUtils::convertToVect(each));
  }

  EXPECT_EQ(eqs, possSols);
}
