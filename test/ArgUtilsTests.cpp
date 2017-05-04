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

  virtual void SetUp()    {
    argv1[0] = (char *)"/path/to/file";
    argv1[1] = (char *)"10";
    argv1[2] = (char *)"20";
    argv1[3] = (char *)"25";
    argv1[4] = (char *)"100";
    argv1[5] = (char *)"2";
    argv1[6] = (char *)"7";
    argv1[7] = (char *)"564";
  }

  virtual void TearDown() {
    delete[] argv1;
  }
};

TEST_F(ArgUtilsTests, testGetArgs) {
  std::vector<std::string> actual1 = ArgUtils::getArgs(argc1, argv1);

  EXPECT_EQ(expected1, actual1);
}
