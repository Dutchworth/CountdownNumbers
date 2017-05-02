#include "StatsUtils.h"
#include <algorithm>

long long StatsUtils::factorial(long long value) {
  if (value < 1) {
    return 1;
  } else {
    return value * factorial(value - 1);
  }
}

std::vector<std::vector<int> >StatsUtils::getCombinations(std::vector<int>set,
                                                          int             subSetSize)
{
  std::sort(set.begin(), set.end());

  std::vector<std::vector<int> > vect2d;

  if (subSetSize <= 1) {
    for (auto each : set) {
      vect2d.push_back(std::vector<int>{ { each } });
    }
  } else {
    auto setCopy = set;

    for (int i = 0; i < set.size(); ++i) {
      int item = set.at(i);

      setCopy.erase(setCopy.begin());

      for (auto subCombo : getCombinations(setCopy, subSetSize - 1)) {
        subCombo.insert(subCombo.begin(), item);
        vect2d.push_back(subCombo);
      }
    }
  }

  return vect2d;
}

std::vector<std::vector<int> >StatsUtils::getPermuations(std::vector<int>set) {
  std::sort(set.begin(), set.end());

  std::vector<std::vector<int> > vect2d;

  if (set.size() <= 1) {
    for (auto each : set) {
      vect2d.push_back(std::vector<int>{ { each } });
    }
  } else {
    for (int i = 0; i < set.size(); ++i) {
      int item = set.at(i);

      auto setCopy = set;
      setCopy.erase(setCopy.begin() + i);

      for (auto subPerm : getPermuations(setCopy)) {
        subPerm.insert(subPerm.begin(), item);
        vect2d.push_back(subPerm);
      }
    }
  }

  return vect2d;
}
