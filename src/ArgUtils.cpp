#include "ArgUtils.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ostream>

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

bool ArgUtils::helpRequested(int argc, char **argv) {
  std::vector<std::string> args = getArgs(argc, argv);
  std::vector<std::string> helpCommands { { "help", "h", "--help", "--h", "-help", "-h" } };

  for (auto each : args) {
    if (std::find(helpCommands.begin(), helpCommands.end(), each) != helpCommands.end()) {
      return true;
    }
  }

  return false;
}

void ArgUtils::printHelp(std::ostream& out) {
  out << "Countdown Numbers calculator\n";
  out << " ========== \n";
  out << "This programs takes input of the 6 numbers to be used to create the solution.\n";
  out << "These should then be followed by the target number that the solution should reach.\n";
  out << " ========== \n";
  out << "The program uses a brute force method of calculating all possible solutions from the given numbers.\n";
  out << "The first solution that returns the given target is output in Reverse Polish Notation (conversion to infix coming soon).\n";
  out << " ========== \n";
}
