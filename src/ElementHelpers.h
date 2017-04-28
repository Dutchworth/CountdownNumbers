#ifndef ELEMENTHELPERS_H
#define ELEMENTHELPERS_H

#include "Element.h"
#include <string>
#include <ostream>

// print operator
std::ostream & operator<<(std::ostream & os,
                          const Element& element);

// forward declaration of comparison operator
bool operator==(const Element& a,
                const Element& b);
bool operator!=(const Element& a,
                const Element& b);

// get string representation of the given operation
std::string getOperationString(const Operation operation);

// gets the result of the given operation on the given values
int         performOperation(const int       a,
                             const Operation operation,
                             const int       b);

#endif // ifndef ELEMENTHELPERS_H
