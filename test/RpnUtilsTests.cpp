#include "RpnUtils.h"
#include <stack>
#include "Element.h"
#include "gtest/gtest.h"

class RpnUtilsTests : public ::testing::Test {
 private:
  void emptyStack(std::stack<Element>& stack) {
    int size = stack.size();

    for (int i = 0; i < stack.size(); ++i) {
      stack.pop();
    }
  }

 protected:
  std::stack<Element> valid1, valid2, invalid1, invalid2;
  int val1 = 20;
  int val2 = 14;

  virtual void SetUp() {
    valid1.push(Element(5));
    valid1.push(Element(4));
    valid1.push(Element(MULTIPLY));

    valid2.push(Element(5));
    valid2.push(Element(1));
    valid2.push(Element(2));
    valid2.push(Element(PLUS));
    valid2.push(Element(4));
    valid2.push(Element(MULTIPLY));
    valid2.push(Element(PLUS));
    valid2.push(Element(3));
    valid2.push(Element(MINUS));

    invalid1.push(Element(5));
    invalid1.push(Element(5));
  }

  virtual void TearDown() {
    emptyStack(valid1);
    emptyStack(valid2);
  }
};

TEST_F(RpnUtilsTests, testIsValidStack) {
  EXPECT_TRUE(RpnUtils::isValidStack(valid1));
  EXPECT_TRUE(RpnUtils::isValidStack(valid2));

  EXPECT_FALSE(RpnUtils::isValidStack(invalid1));
  EXPECT_FALSE(RpnUtils::isValidStack(invalid2));
}

TEST_F(RpnUtilsTests, testToString) {
  std::string expected1 = "54*";
  std::string actual1 = RpnUtils::to_string(valid1);
  EXPECT_EQ(expected1, actual1);

  std::string expected2 = "512+4*+3-";
  std::string actual2 = RpnUtils::to_string(valid2);
  EXPECT_EQ(expected2, actual2);

  std::string expected3 = "55";
  std::string actual3 = RpnUtils::to_string(invalid1);
  EXPECT_EQ(expected3, actual3);

  std::string expected4 = "";
  std::string actual4 = RpnUtils::to_string(invalid2);
  EXPECT_EQ(expected4, actual4);
}

TEST_F(RpnUtilsTests, testEvaluateStack) {
  EXPECT_EQ(val1, RpnUtils::evaluateStack(valid1));
  EXPECT_EQ(val2, RpnUtils::evaluateStack(valid2));

  EXPECT_EQ(0, RpnUtils::evaluateStack(invalid1));
  EXPECT_EQ(0, RpnUtils::evaluateStack(invalid2));
}
