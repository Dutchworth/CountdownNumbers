#ifndef ARGUTILS_H
#define ARGUTILS_H

#include <string>
#include <vector>

namespace ArgUtils {
// gets a vector of strings from the given program input
std::vector<std::string>getArgs(int    argc,
                                char **argv);
}
#endif // ifndef ARGUTILS_H
