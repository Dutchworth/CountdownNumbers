#include "gtest/gtest.h"
#include "Element.h"
#include "ElementHelpers.h"
#include <string>

class ElementTests : public ::testing::Test {
protected:

  Element element1, element2, element3;

  virtual void SetUp()    {
    element1 = Element();
    element2 = Element(10);
    element3 = Element(PLUS);
  }

  virtual void TearDown() {}
};

TEST_F(ElementTests, testEmptyConstructor) {
  Element newElement1;

  EXPECT_EQ(newElement1, element1);
  EXPECT_TRUE(element1.isNumber());
  EXPECT_EQ(0,      element1.getValue());
  EXPECT_EQ(NUMBER, element1.getOperation());
}

TEST_F(ElementTests, testIntConstructor) {
  Element newElement2(10);

  EXPECT_EQ(newElement2, element2);
  EXPECT_TRUE(element2.isNumber());
  EXPECT_EQ(10,     element2.getValue());
  EXPECT_EQ(NUMBER, element2.getOperation());
}

TEST_F(ElementTests, testOperationConstructor) {
  Element newElement3(PLUS);

  EXPECT_EQ(newElement3, element3);
  EXPECT_FALSE(element3.isNumber());
  EXPECT_EQ(0,    element3.getValue());
  EXPECT_EQ(PLUS, element3.getOperation());
}

TEST_F(ElementTests, testCopyConstrustor) {
  Element newElement1(element1);
  Element newElement2(element2);
  Element newElement3(element3);

  EXPECT_EQ(newElement1, element1);
  EXPECT_EQ(newElement2, element2);
  EXPECT_EQ(newElement3, element3);
}

TEST_F(ElementTests, testAssignmentOperator) {
  Element newElement1 = element1;
  Element newElement2 = element2;
  Element newElement3 = element3;

  EXPECT_EQ(newElement1, element1);
  EXPECT_EQ(newElement2, element2);
  EXPECT_EQ(newElement3, element3);
}

TEST_F(ElementTests, testGetValue) {
  EXPECT_EQ(0,  element1.getValue());
  EXPECT_EQ(10, element2.getValue());
  EXPECT_EQ(0,  element3.getValue());
}

TEST_F(ElementTests, testGetOperation) {
  EXPECT_EQ(NUMBER, element1.getOperation());
  EXPECT_EQ(NUMBER, element2.getOperation());
  EXPECT_EQ(PLUS,   element3.getOperation());
}

TEST_F(ElementTests, testIsNumber) {
  EXPECT_TRUE(element1.isNumber());
  EXPECT_TRUE(element2.isNumber());
  EXPECT_FALSE(element3.isNumber());
}

TEST_F(ElementTests, testGetString) {
  std::string expected1 = "0";
  std::string expected2 = "10";
  std::string expected3 = "+";

  EXPECT_EQ(expected1, element1.getString());
  EXPECT_EQ(expected2, element2.getString());
  EXPECT_EQ(expected3, element3.getString());
}
