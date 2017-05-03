
#ifndef STATSUTILS_H
#define STATSUTILS_H

#include <vector>

namespace StatsUtils {
// factorial of given (posistive integer)
long long                   factorial(long long value);

template<typename T>
std::vector<std::vector<T> >getCombinations(std::vector<T>set,
                                            int           subSetSize);

template<typename T>
std::vector<std::vector<T> >getCombinationsWithRep(std::vector<T>set,
                                                   int           subSetSize);

template<typename T>
std::vector<std::vector<T> >getPermutations(std::vector<T>set);
}

#include "StatsUtils.tcc"

#endif // ifndef STATSUTILS_H
