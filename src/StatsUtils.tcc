#ifndef STATSUTILS_TCC
#define STATSUTILS_TCC

#include <algorithm>

namespace StatsUtils {
template<typename T>
std::vector<std::vector<T> >getCombinations(std::vector<T>set,
                                            int           subSetSize) {
  std::sort(set.begin(), set.end());

  std::vector<std::vector<T> > vect2d;

  if (subSetSize <= 1) {
    for (auto each : set) {
      vect2d.push_back(std::vector<T>{ { each } });
    }
  } else {
    auto setCopy = set;

    for (int i = 0; i < set.size(); ++i) {
      T item = set.at(i);

      setCopy.erase(setCopy.begin());

      for (auto subCombo : getCombinations(setCopy, subSetSize - 1)) {
        subCombo.insert(subCombo.begin(), item);
        vect2d.push_back(subCombo);
      }
    }
  }

  return vect2d;
}

template<typename T>
std::vector<std::vector<T> >getPermuations(std::vector<T>set) {
  std::sort(set.begin(), set.end());

  std::vector<std::vector<T> > vect2d;

  if (set.size() <= 1) {
    for (auto each : set) {
      vect2d.push_back(std::vector<T>{ { each } });
    }
  } else {
    for (int i = 0; i < set.size(); ++i) {
      T item = set.at(i);

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
}

#endif // ifndef STATSUTILS_TCC