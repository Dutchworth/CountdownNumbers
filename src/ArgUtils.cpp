#include "ArgUtils.h"
#include <string>
#include <vector>
#include <stdexcept>

std::vector<std::string>ArgUtils::getArgs(int argc, char **argv) {
  std::vector<std::string> args;

  for (int i = 0; i < argc; ++i) {
    args.push_back(std::string(argv[i]));
  }

  return args;
}

std::vector<int>ArgUtils::getNumbers(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);

  std::vector<int> nums;

  try {
    for (int i = 1; i < 7; ++i) {
      nums.push_back(std::stoi(args.at(i)));
    }
  } catch (std::invalid_argument except) {
    nums.clear();
    return nums;
  }

  return nums;
}

int ArgUtils::getTarget(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);

  try {
    return std::stoi(args.at(7));
  } catch (std::invalid_argument except) {
    return 1;
  }
}

bool ArgUtils::correctInput(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);

  if (argc < 8) {
    return false;
  } else {
    for (int i = 1; i < argc; ++i) {
      try {
        std::stoi(args.at(i));
      } catch (std::invalid_argument except) {
        return false;
      }
    }
  }

  return true;
}
