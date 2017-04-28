#include "gtest/gtest.h"
#include "Element.h"
#include "ElementHelpers.h"

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
  EXPECT_TRUE(element1.isNumber());
  EXPECT_EQ(0,      element1.getValue());
  EXPECT_EQ(NUMBER, element1.getOperation());
}
