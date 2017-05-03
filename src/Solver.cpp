#include "Solver.h"
#include "Element.h"
#include "ElementHelpers.h"
#include "StatsUtils.h"
#include "RpnUtils.h"
#include <vector>

namespace Solver {
std::vector<std::stack<Element> >possSolutions(std::vector<int>numbers,
                                               int             subSetSize) {
  int numGiven = numbers.size();
  int numOps   = subSetSize - 1;

  std::vector<Element> possibleOps { { Element(PLUS), Element(MINUS), Element(MULTIPLY), Element(DIVIDE) } };

  std::vector<Element> elements                  = convertToElement(numbers);
  std::vector<std::vector<Element> > combsOfNums = StatsUtils::getCombinations(elements, subSetSize);
  std::vector<std::vector<Element> > operations  = StatsUtils::getCombinationsWithRep(possibleOps, numOps);

  std::vector<std::stack<Element> > toReturn;

  for (auto eachNumComb : combsOfNums) {
    for (auto eachOpComb : operations) {
      eachNumComb.insert(eachNumComb.end(), eachOpComb.begin(), eachOpComb.end());

      for (auto eachPerm : StatsUtils::getPermutations(eachNumComb)) {
        if (RpnUtils::isValidStack(eachPerm)) {
          toReturn.push_back(RpnUtils::convertToStack(eachPerm));
        }
      }
    }
  }

  return toReturn;
}
}
