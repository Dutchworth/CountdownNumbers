#ifndef SOLVER_H
#define SOLVER_H

namespace Solver {
bool                              solveRecursive(std::vector<int>numbers,
                                                 int             target);

std::vector<std::vector<Element> >possSolutions(std::vector<int>numbers);
}

#endif // ifndef SOLVER_H
