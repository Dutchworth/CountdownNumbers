#ifndef RPNUTILS_H
#define  RPNUTILS_H

#include "Element.h"
#include <stack>
#include <vector>
#include <string>

class RpnUtils {
private:

  static std::vector<Element>convertToVect(std::stack<Element>stack);

  // returns the evaluated value of the given stack of emelents int rpn format
  static int                 evaluateStackRecursive(std::stack<Element>& stack);

public:

  static int         evaluateStack(std::stack<Element>stack);

  // returns whether the given stack of elements is a valid rpn stack
  static bool        isValidStack(std::stack<Element>stack);

  static std::string to_string(std::stack<Element>stack);
};

#endif // ifndef RPNUTILS_H
