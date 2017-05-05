#ifndef ARGUTILS_H
#define ARGUTILS_H

#include <string>
#include <vector>

namespace ArgUtils {
// gets a vector of strings from the given program input
std::vector<std::string>getArgs(int    argc,
                                char **argv);

// Returns a vector of the numbers to be used to create the solution from the
// given user input
std::vector<int>getNumbers(int    argc,
                           char **argv);

int             getTarget(int    argc,
                          char **argv);

bool            correctInput(int    argc,
                             char **argv);
}
#endif // ifndef ARGUTILS_H
