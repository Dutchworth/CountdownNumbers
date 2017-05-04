#include "Solver.h"
#include "Element.h"
#include "ElementHelpers.h"
#include "StatsUtils.h"
#include "RpnUtils.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace Solver {
bool solve(std::vector<int>numbers, int target, std::vector<Element>& solution) {
  std::vector<Element> possibleOps { { Element(PLUS), Element(MINUS), Element(MULTIPLY), Element(DIVIDE) } };

  std::vector<Element> elements = convertToElement(numbers);

  for (int i = 2; i <= numbers.size(); ++i) {
    int numOps = i - 1;

    std::vector<std::vector<Element> > combsOfNums = StatsUtils::getCombinations(elements, i);
    std::vector<std::vector<Element> > operations  = StatsUtils::getCombinationsWithRep(possibleOps, numOps);

    for (auto eachNumComb : combsOfNums) {
      for (auto eachOpComb : operations) {
        std::vector<Element> newComb = eachNumComb;
        newComb.insert(newComb.end(), eachOpComb.begin(), eachOpComb.end());

        do {
          if (RpnUtils::isValidStack(newComb)) {
            std::stack<Element> newStack = RpnUtils::convertToStack(newComb);

            if (RpnUtils::evaluateStack(newStack) == target) {
              solution = newComb;

              return true;
            }
          }
        } while (std::next_permutation(newComb.begin(), newComb.end()));
      }
    }
  }

  return false;
}
}
