#ifndef SOLVER_H
#define SOLVER_H

#include "Element.h"
#include <vector>
#include <stack>

namespace Solver {
// returns true if a solution is possible for the given numbers and target
// the found solution is returned by the input by ref: solution
bool solve(std::vector<int>      numbers,
           int                   target,
           std::vector<Element>& solution);
}

#endif // ifndef SOLVER_H
