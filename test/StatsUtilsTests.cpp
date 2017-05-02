#include "gtest/gtest.h"
#include "StatsUtils.h"
#include <cmath>

class StatsUtilsTests : public ::testing::Test {
protected:

  std::vector<int>nums4 { { 1, 2, 3, 4 } };

  std::vector<std::vector<int> >combs4to1 { { 1 },
                                            { 2 },
                                            { 3 },
                                            { 4 } };
  std::vector<std::vector<int> >combs4to2 { { 1, 2 },
                                            { 1, 3 },
                                            { 1, 4 },
                                            { 2, 3 },
                                            { 2, 4 },
                                            { 3, 4 } };
  std::vector<std::vector<int> >combs4to3 { { 1, 2, 3 },
                                            { 1, 2, 4 },
                                            { 1, 3, 4 },
                                            { 2, 3, 4 } };
  std::vector<std::vector<int> >combs4to4 { { 1, 2, 3, 4 } };

  std::vector<std::vector<int> >perms { { 1, 2, 3, 4 },
                                        { 1, 2, 4, 3 },
                                        { 1, 3, 2, 4 },
                                        { 1, 3, 4, 2 },
                                        { 1, 4, 2, 3 },
                                        { 1, 4, 3, 2 },
                                        { 2, 1, 3, 4 },
                                        { 2, 1, 4, 3 },
                                        { 2, 3, 1, 4 },
                                        { 2, 3, 4, 1 },
                                        { 2, 4, 1, 3 },
                                        { 2, 4, 3, 1 },
                                        { 3, 1, 2, 4 },
                                        { 3, 1, 4, 2 },
                                        { 3, 2, 1, 4 },
                                        { 3, 2, 4, 1 },
                                        { 3, 4, 1, 2 },
                                        { 3, 4, 2, 1 },
                                        { 4, 1, 2, 3 },
                                        { 4, 1, 3, 2 },
                                        { 4, 2, 1, 3 },
                                        { 4, 2, 3, 1 },
                                        { 4, 3, 1, 2 },
                                        { 4, 3, 2, 1 } };

  virtual void SetUp()    {}

  virtual void TearDown() {}
};

TEST_F(StatsUtilsTests, testFactorial) {
  for (unsigned long long i = 0; i <= 6; ++i) {
    // extra 0.5 to force proper rounding
    long long expected = std::tgamma(i + 1) + 0.5;
    long long actual   = StatsUtils::factorial(i);
    EXPECT_EQ(expected, actual);
  }

  EXPECT_EQ(1, StatsUtils::factorial(0));
  EXPECT_EQ(1, StatsUtils::factorial(-1));
}

TEST_F(StatsUtilsTests, testGetCombinations) {
  std::vector<std::vector<int> > new4C1 = StatsUtils::getCombinations<int>(nums4,
                                                                           1);
  EXPECT_EQ(combs4to1, new4C1);

  std::vector<std::vector<int> > new4C2 = StatsUtils::getCombinations<int>(nums4,
                                                                           2);
  EXPECT_EQ(combs4to2, new4C2);

  std::vector<std::vector<int> > new4C3 = StatsUtils::getCombinations<int>(nums4,
                                                                           3);
  EXPECT_EQ(combs4to3, new4C3);

  std::vector<std::vector<int> > new4C4 = StatsUtils::getCombinations<int>(nums4,
                                                                           4);
  EXPECT_EQ(combs4to4, new4C4);
}

TEST_F(StatsUtilsTests, tetsGetPermutations) {
  std::vector<std::vector<int> > newPerms =
    StatsUtils::getPermuations<int>(nums4);
  EXPECT_EQ(perms, newPerms);
}
