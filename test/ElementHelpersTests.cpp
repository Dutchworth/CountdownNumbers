#include "gtest/gtest.h"
#include "ElementHelpers.h"
#include "Element.h"
#include <string>
#include <sstream>
#include <vector>

class ElementHelpersTests : public ::testing::Test {
protected:

  Element element1, element2, element3;


  std::vector<int>vectInt { { 1, 2, 3, 4 } };
  std::vector<Element>vectElement { { Element(1),
                                      Element(2),
                                      Element(3),
                                      Element(4) } };

  std::vector<std::vector<int> >vectInt2d { { 1 }, { 2 }, { 3 }, { 4 } };
  std::vector<std::vector<Element> >vectElement2d { { Element(1) },
                                                    { Element(2) },
                                                    { Element(3) },
                                                    { Element(4) } };

  virtual void SetUp()    {
    element1 = Element();
    element2 = Element(10);
    element3 = Element(PLUS);
  }

  virtual void TearDown() {}
};

TEST_F(ElementHelpersTests, testComparisonOperatorEquals) {
  EXPECT_TRUE(element1 == element1);
  EXPECT_FALSE(element1 == element2);
  EXPECT_FALSE(element1 == element3);

  EXPECT_TRUE(element2 == element2);
  EXPECT_FALSE(element2 == element1);
  EXPECT_FALSE(element2 == element3);

  EXPECT_TRUE(element3 == element3);
  EXPECT_FALSE(element3 == element2);
  EXPECT_FALSE(element3 == element1);
}

TEST_F(ElementHelpersTests, testComparisonOperatorNotEquals) {
  EXPECT_FALSE(element1 != element1);
  EXPECT_TRUE(element1 != element2);
  EXPECT_TRUE(element1 != element3);

  EXPECT_FALSE(element2 != element2);
  EXPECT_TRUE(element2 != element1);
  EXPECT_TRUE(element2 != element3);

  EXPECT_FALSE(element3 != element3);
  EXPECT_TRUE(element3 != element2);
  EXPECT_TRUE(element3 != element1);
}

TEST_F(ElementHelpersTests, testLessThanOperator) {
  EXPECT_FALSE(element1 < element1);
  EXPECT_TRUE(element1 < element2);
  EXPECT_TRUE(element1 < element3);

  EXPECT_FALSE(element2 < element2);
  EXPECT_TRUE(element2 < element3);

  EXPECT_FALSE(element3 < element3);
}

TEST_F(ElementHelpersTests, testGreaterThanOperator) {
  EXPECT_FALSE(element1 > element1);
  EXPECT_FALSE(element1 > element2);
  EXPECT_FALSE(element1 > element3);

  EXPECT_FALSE(element2 > element2);
  EXPECT_FALSE(element2 > element3);

  EXPECT_FALSE(element3 > element3);
}

TEST_F(ElementHelpersTests, testLessThanEqualToOperator) {
  EXPECT_TRUE(element1 <= element1);
  EXPECT_TRUE(element1 <= element2);
  EXPECT_TRUE(element1 <= element3);

  EXPECT_TRUE(element2 <= element2);
  EXPECT_TRUE(element2 <= element3);

  EXPECT_TRUE(element3 <= element3);
}

TEST_F(ElementHelpersTests, testGreaterThanEqualToOperator) {
  EXPECT_TRUE(element1 >= element1);
  EXPECT_FALSE(element1 >= element2);
  EXPECT_FALSE(element1 >= element3);

  EXPECT_TRUE(element2 >= element2);
  EXPECT_FALSE(element2 >= element3);

  EXPECT_TRUE(element3 >= element3);
}

TEST_F(ElementHelpersTests, testPrintOperator) {
  std::string expected1 = "0";
  std::string expected2 = "10";
  std::string expected3 = "+";

  std::ostringstream stream1;
  stream1 << element1;
  std::string actual1 = stream1.str();

  std::ostringstream stream2;
  stream2 << element2;
  std::string actual2 = stream2.str();

  std::ostringstream stream3;
  stream3 << element3;
  std::string actual3 = stream3.str();

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
  EXPECT_EQ(expected3, actual3);
}

TEST_F(ElementHelpersTests, testGetOperationString) {
  std::string expected1 = "+";
  std::string expected2 = "-";
  std::string expected3 = "*";
  std::string expected4 = "/";
  std::string expected5 = "";

  std::string actual1 = getOperationString(PLUS);
  std::string actual2 = getOperationString(MINUS);
  std::string actual3 = getOperationString(MULTIPLY);
  std::string actual4 = getOperationString(DIVIDE);
  std::string actual5 = getOperationString(NUMBER);

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
  EXPECT_EQ(expected3, actual3);
  EXPECT_EQ(expected4, actual4);
  EXPECT_EQ(expected5, actual5);
}

TEST_F(ElementHelpersTests, testPerformOperation) {
  int a = 10;
  int b = 2;

  int expectedPlus     = 12;
  int expectedMinus    = 8;
  int expectedMultiply = 20;
  int expectedDivide   = 5;
  int expectedNumber   = 0;

  EXPECT_EQ(expectedPlus,     performOperation(a, PLUS, b));
  EXPECT_EQ(expectedMinus,    performOperation(a, MINUS, b));
  EXPECT_EQ(expectedMultiply, performOperation(a, MULTIPLY, b));
  EXPECT_EQ(expectedDivide,   performOperation(a, DIVIDE, b));
  EXPECT_EQ(expectedNumber,   performOperation(a, NUMBER, b));
}

TEST_F(ElementHelpersTests, testConvertToElement1d) {
  std::vector<Element> newVectElement = convertToElement(vectInt);
  EXPECT_EQ(vectElement, newVectElement);
}

TEST_F(ElementHelpersTests, testConvertToElement2d) {
  std::vector<std::vector<Element> > newVectElement2d =
    convertToElement(vectInt2d);
  EXPECT_EQ(vectElement2d, newVectElement2d);
}
