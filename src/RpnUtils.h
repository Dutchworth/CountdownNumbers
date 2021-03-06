#ifndef RPNUTILS_H
#define RPNUTILS_H

#include <stack>
#include <string>
#include <vector>
#include "Element.h"

namespace RpnUtils {
// converts the given stack to a vector for easier print and manipulation
std::vector<Element> convertToVect(std::stack<Element> stack);

// converts the given vector to a stack
std::stack<Element> convertToStack(std::vector<Element> vect);

// returns the evaluated value of the given stack of emelents int rpn format
int evaluateStackRecursive(std::stack<Element>& stack);

// returns the evaluated value of the given stack of elements int rpn format.
// first checks if it's a valid rpn stack.
int evaluateStack(std::stack<Element> stack);

// returns whether the given stack of elements is a valid rpn stack
bool isValidStack(std::vector<Element> vect);
bool isValidStack(std::stack<Element> stack);

// converts the given rpn stack to a string for printing
std::string to_string(std::stack<Element> stack);
}

#endif  // ifndef RPNUTILS_H
