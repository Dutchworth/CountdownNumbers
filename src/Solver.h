#ifndef SOLVER_H
#define SOLVER_H

#include "Element.h"
#include <vector>
#include <stack>

namespace Solver {
// returns all the possible rpn equations for a given subSetSize of the given
// numbers
std::vector<std::stack<Element> >possSolutions(std::vector<int>numbers,
                                               int             subSetSize);
}

#endif // ifndef SOLVER_H
