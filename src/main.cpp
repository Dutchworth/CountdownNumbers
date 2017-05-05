#include "ArgUtils.h"
#include "Solver.h"
#include "Element.h"
#include "ElementHelpers.h"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **argv) {
  if (ArgUtils::helpRequested(argc, argv)) {
    ArgUtils::printHelp(std::cout);
    return 0;
  }

  std::cout << "Countdown Numbers calculator\n";
  std::cout << " ========== \n";


  if (ArgUtils::correctInput(argc, argv)) {
    std::cout << "calculating with:\nnumbers: ";

    std::vector<int> nums = ArgUtils::getNumbers(argc, argv);

    for (auto num : nums) {
      std::cout << num << ' ';
    }
    std::cout << '\n';

    int target = ArgUtils::getTarget(argc, argv);
    std::cout << "target: " << target << '\n';

    std::vector<Element> solution;

    if (Solver::solve(nums, target, solution)) {
      std::cout << " ========== \n";
      std::cout << "Solution found: ";

      for (auto each : solution) {
        std::cout << each << ' ';
      }

      std::cout << " = " << target << '\n';
    }
  } else {
    std::cout <<
      "Bad input. Please try again or use help command for more info.\n";
    return 1;
  }

  return 0;
}
