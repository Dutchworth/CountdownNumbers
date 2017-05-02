
#ifndef STATSUTILS_H
#define STATSUTILS_H

#include <vector>

namespace StatsUtils {
// factorial of given (posistive integer)
long long                     factorial(long long value);

std::vector<std::vector<int> >getCombinations(std::vector<int>set,
                                              int             subSetSize);

std::vector<std::vector<int> >getPermuations(std::vector<int>set);
}

#endif // ifndef STATSUTILS_H
