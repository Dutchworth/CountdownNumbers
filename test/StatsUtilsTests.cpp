#include "gtest/gtest.h"
#include "StatsUtils.h"
#include <cmath>

class StatsUtilsTests : public ::testing::Test {
private:

  void empty2dVect(std::vector<std::vector<int> >& vect) {
    vect.clear();
  }

protected:

  std::vector<int>nums4 { { 1, 2, 3, 4 } };
  std::vector<std::vector<int> >combs4to3;

  virtual void SetUp() {
    combs4to3.push_back(std::vector<int>({ 1, 2, 3 }));
    combs4to3.push_back(std::vector<int>({ 1, 2, 4 }));
    combs4to3.push_back(std::vector<int>({ 1, 3, 4 }));
    combs4to3.push_back(std::vector<int>({ 2, 3, 4 }));
  }

  virtual void TearDown() {
    empty2dVect(combs4to3);
  }
};

TEST_F(StatsUtilsTests, testFactorial) {
  for (unsigned long long i = 0; i <= 6; ++i) {
    unsigned long long expected = std::tgamma(i + 1) + 0.5; // extra 0.5 to
                                                            // force proper
                                                            // rounding
    unsigned long long actual = StatsUtils::factorial(i);
    EXPECT_EQ(expected, actual);
  }

  EXPECT_EQ(1, StatsUtils::factorial(-1));
}

TEST_F(StatsUtilsTests, testGetCombinations) {
  std::vector<std::vector<int> > new4C3 = StatsUtils::getCombinations(nums4, 3);

  EXPECT_EQ(combs4to3, new4C3);
}
