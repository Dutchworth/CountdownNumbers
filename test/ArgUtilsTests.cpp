#include "gtest/gtest.h"
#include "ArgUtils.h"
#include <string>
#include <vector>

class ArgUtilsTests : public ::testing::Test {
protected:

  int argc1    = 8;
  char **argv1 = new char *[argc1];

  std::vector<std::string>expected1 { { "/path/to/file",
                                        "10",
                                        "20",
                                        "25",
                                        "100",
                                        "2",
                                        "7",
                                        "564" } };

  int argc2    = 3;
  char **argv2 = new char *[argc2];

  std::vector<std::string>expected2 { { "/path/to/file",
                                        "10",
                                        "20" } };

  char **argv3 = new char *[argc1];

  virtual void SetUp()    {
    argv1[0] = (char *)"/path/to/file";
    argv1[1] = (char *)"10";
    argv1[2] = (char *)"20";
    argv1[3] = (char *)"25";
    argv1[4] = (char *)"100";
    argv1[5] = (char *)"2";
    argv1[6] = (char *)"7";
    argv1[7] = (char *)"564";

    argv2[0] = (char *)"/path/to/file";
    argv2[1] = (char *)"10";
    argv2[2] = (char *)"20";

    argv3[0] = (char *)"/path/to/file";
    argv3[1] = (char *)"adsfasdf";
    argv3[2] = (char *)"asdfasdf";
    argv3[3] = (char *)"asdfasdf";
    argv3[4] = (char *)"asdfasdf";
    argv3[5] = (char *)"asdfasdf";
    argv3[6] = (char *)"asdfasdf";
    argv3[7] = (char *)"asdfasdf";
  }

  virtual void TearDown() {
    delete[] argv1;
  }
};

TEST_F(ArgUtilsTests, testGetArgs) {
  std::vector<std::string> actual1 = ArgUtils::getArgs(argc1, argv1);
  EXPECT_EQ(expected1, actual1);

  std::vector<std::string> actual2 = ArgUtils::getArgs(argc2, argv2);
  EXPECT_EQ(expected2, actual2);
}

TEST_F(ArgUtilsTests, testGetNumbersHappy) {
  std::vector<int> expected { { 10, 20, 25, 100, 2, 7 } };
  std::vector<int> actual = ArgUtils::getNumbers(argc1, argv1);

  EXPECT_EQ(expected, actual);
}

TEST_F(ArgUtilsTests, testGetNumbersUnHappy) {
  std::vector<int> actual = ArgUtils::getNumbers(argc1, argv3);

  EXPECT_TRUE(actual.empty());
}

TEST_F(ArgUtilsTests, testGetTargetHappy) {
  int expected = 564;
  int actual   = ArgUtils::getTarget(argc1, argv1);

  EXPECT_EQ(expected, actual);
}

TEST_F(ArgUtilsTests, testGetTargetUnHappy) {
  int expected = 1;
  int actual   = ArgUtils::getTarget(argc1, argv3);

  EXPECT_EQ(expected, actual);
}

TEST_F(ArgUtilsTests, testCorrectInput) {
  EXPECT_TRUE(ArgUtils::correctInput(argc1, argv1));
  EXPECT_FALSE(ArgUtils::correctInput(argc2, argv2));
  EXPECT_FALSE(ArgUtils::correctInput(argc1, argv3));
}
