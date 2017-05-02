#include "StatsUtils.h"

namespace StatsUtils {
long long factorial(long long value) {
  if (value < 1) {
    return 1;
  } else {
    return value * factorial(value - 1);
  }
}
}
