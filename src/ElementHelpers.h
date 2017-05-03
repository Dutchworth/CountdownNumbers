#ifndef ELEMENTHELPERS_H
#define ELEMENTHELPERS_H

#include "Element.h"
#include <string>
#include <ostream>
#include <vector>

// print operator
std::ostream & operator<<(std::ostream & os,
                          const Element& element);

// forward declaration of comparison operators
bool operator==(const Element& a,
                const Element& b);
bool operator!=(const Element& a,
                const Element& b);
bool operator<(const Element& a,
               const Element& b);
bool operator>(const Element& a,
               const Element& b);
bool operator<=(const Element& a,
                const Element& b);
bool operator>=(const Element& a,
                const Element& b);

// get string representation of the given operation
std::string getOperationString(const Operation operation);

// gets the result of the given operation on the given values
int         performOperation(const int       a,
                             const Operation operation,
                             const int       b);

// convert a vector of integers to Element with those
std::vector<Element>              convertToElement(std::vector<int>input);

// convert a 2d vector of integers to Element with those values
std::vector<std::vector<Element> >convertToElement(
  std::vector<std::vector<int> >input);

#endif // ifndef ELEMENTHELPERS_H
