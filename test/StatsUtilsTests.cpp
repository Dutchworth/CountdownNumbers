#include "StatsUtils.h"
#include <cmath>
#include "Element.h"
#include "ElementHelpers.h"
#include "StatsUtilsTestsValues.h"
#include "gtest/gtest.h"

class StatsUtilsTests : public ::testing::Test {
 protected:
  std::vector<int> nums4 = testValues::nums4;

  std::vector<std::vector<int> > combs4to1 = testValues::combs4to1;
  std::vector<std::vector<int> > combs4to2 = testValues::combs4to2;
  std::vector<std::vector<int> > combs4to3 = testValues::combs4to3;
  std::vector<std::vector<int> > combs4to4 = testValues::combs4to4;

  std::vector<std::vector<int> > perms = testValues::perms;

  std::vector<std::vector<int> > combsReps4to1 = testValues::combsReps4to1;
  std::vector<std::vector<int> > combsReps4to2 = testValues::combsReps4to2;
  std::vector<std::vector<int> > combsReps4to3 = testValues::combsReps4to3;
  std::vector<std::vector<int> > combsReps4to4 = testValues::combsReps4to4;

  // expected values for tests using element class

  std::vector<Element> elements = convertToElement(nums4);

  std::vector<std::vector<Element> > elementsCombs1 =
      convertToElement(combs4to1);
  std::vector<std::vector<Element> > elementsCombs2 =
      convertToElement(combs4to2);
  std::vector<std::vector<Element> > elementsCombs3 =
      convertToElement(combs4to3);
  std::vector<std::vector<Element> > elementsCombs4 =
      convertToElement(combs4to4);

  std::vector<std::vector<Element> > elementPerms = convertToElement(perms);

  std::vector<std::vector<Element> > elementsCombs1Rep =
      convertToElement(combsReps4to1);
  std::vector<std::vector<Element> > elementsCombs2Rep =
      convertToElement(combsReps4to2);
  std::vector<std::vector<Element> > elementsCombs3Rep =
      convertToElement(combsReps4to3);
  std::vector<std::vector<Element> > elementsCombs4Rep =
      convertToElement(combsReps4to4);

  virtual void SetUp() {
    // do nothing, values already setup
  }

  virtual void TearDown() {
    // do nothing, values will be destroyed be class destructor
  }
};

TEST_F(StatsUtilsTests, testFactorial) {
  for (unsigned long long i = 0; i <= 6; ++i) {
    // extra 0.5 to force proper rounding
    long long expected = std::tgamma(i + 1) + 0.5;
    long long actual = StatsUtils::factorial(i);
    EXPECT_EQ(expected, actual);
  }

  EXPECT_EQ(1, StatsUtils::factorial(0));
  EXPECT_EQ(1, StatsUtils::factorial(-1));
}

TEST_F(StatsUtilsTests, testGetCombinations) {
  std::vector<std::vector<int> > new4C1 =
      StatsUtils::getCombinations<int>(nums4, 1);
  EXPECT_EQ(combs4to1, new4C1);

  std::vector<std::vector<int> > new4C2 =
      StatsUtils::getCombinations<int>(nums4, 2);
  EXPECT_EQ(combs4to2, new4C2);

  std::vector<std::vector<int> > new4C3 =
      StatsUtils::getCombinations<int>(nums4, 3);
  EXPECT_EQ(combs4to3, new4C3);

  std::vector<std::vector<int> > new4C4 =
      StatsUtils::getCombinations<int>(nums4, 4);
  EXPECT_EQ(combs4to4, new4C4);
}

TEST_F(StatsUtilsTests, tetsGetPermutations) {
  std::vector<std::vector<int> > newPerms =
      StatsUtils::getPermutations<int>(nums4);
  EXPECT_EQ(perms, newPerms);
}

TEST_F(StatsUtilsTests, testGetCombinationsWithRepetion) {
  std::vector<std::vector<int> > new4C1 =
      StatsUtils::getCombinationsWithRep<int>(nums4, 1);
  EXPECT_EQ(combsReps4to1, new4C1);

  std::vector<std::vector<int> > new4C2 =
      StatsUtils::getCombinationsWithRep<int>(nums4, 2);
  EXPECT_EQ(combsReps4to2, new4C2);

  std::vector<std::vector<int> > new4C3 =
      StatsUtils::getCombinationsWithRep<int>(nums4, 3);
  EXPECT_EQ(combsReps4to3, new4C3);

  std::vector<std::vector<int> > new4C4 =
      StatsUtils::getCombinationsWithRep<int>(nums4, 4);
  EXPECT_EQ(combsReps4to4, new4C4);
}

TEST_F(StatsUtilsTests, testGetCombinationsElement) {
  std::vector<std::vector<Element> > newElements1 =
      StatsUtils::getCombinations<Element>(elements, 1);
  EXPECT_EQ(elementsCombs1, newElements1);

  std::vector<std::vector<Element> > newElements2 =
      StatsUtils::getCombinations<Element>(elements, 2);
  EXPECT_EQ(elementsCombs2, newElements2);

  std::vector<std::vector<Element> > newElements3 =
      StatsUtils::getCombinations<Element>(elements, 3);
  EXPECT_EQ(elementsCombs3, newElements3);

  std::vector<std::vector<Element> > newElements4 =
      StatsUtils::getCombinations<Element>(elements, 4);
  EXPECT_EQ(elementsCombs4, newElements4);
}

TEST_F(StatsUtilsTests, testGetCombinationsWithRepetionElement) {
  std::vector<std::vector<Element> > newElements1 =
      StatsUtils::getCombinationsWithRep<Element>(elements, 1);
  EXPECT_EQ(elementsCombs1Rep, newElements1);

  std::vector<std::vector<Element> > newElements2 =
      StatsUtils::getCombinationsWithRep<Element>(elements, 2);
  EXPECT_EQ(elementsCombs2Rep, newElements2);

  std::vector<std::vector<Element> > newElements3 =
      StatsUtils::getCombinationsWithRep<Element>(elements, 3);
  EXPECT_EQ(elementsCombs3Rep, newElements3);

  std::vector<std::vector<Element> > newElements4 =
      StatsUtils::getCombinationsWithRep<Element>(elements, 4);
  EXPECT_EQ(elementsCombs4Rep, newElements4);
}

TEST_F(StatsUtilsTests, tetsGetPermutationsElement) {
  std::vector<std::vector<Element> > newPerms =
      StatsUtils::getPermutations<Element>(elements);
  EXPECT_EQ(elementPerms, newPerms);
}
