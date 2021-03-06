#include "RpnUtils.h"
#include <algorithm>
#include <string>
#include <vector>
#include "Element.h"
#include "ElementHelpers.h"

std::vector<Element> RpnUtils::convertToVect(std::stack<Element> stack) {
  std::vector<Element> vect;

  int size = stack.size();

  for (int i = 0; i < size; ++i) {
    vect.push_back(stack.top());
    stack.pop();
  }

  std::reverse(vect.begin(), vect.end());

  return vect;
}

std::stack<Element> RpnUtils::convertToStack(std::vector<Element> vect) {
  std::stack<Element> stack;

  for (auto each : vect) {
    stack.push(each);
  }

  return stack;
}

int RpnUtils::evaluateStackRecursive(std::stack<Element>& stack) {
  Element top = stack.top();

  stack.pop();

  if (top.isNumber()) {
    return top.getValue();
  } else {
    int a = evaluateStackRecursive(stack);
    int b = evaluateStackRecursive(stack);

    return performOperation(b, top.getOperation(), a);
  }
}

int RpnUtils::evaluateStack(std::stack<Element> stack) {
  if (isValidStack(stack)) {
    return evaluateStackRecursive(stack);
  } else {
    return 0;
  }
}

bool RpnUtils::isValidStack(std::vector<Element> vect) {
  int counter = 0;

  for (auto each : vect) {
    if (each.isNumber()) {
      ++counter;
    } else {
      --counter;
      --counter;
      ++counter;
    }

    if (counter < 0) {
      return false;
    }
  }

  return counter == 1 && vect.size() && vect.at(0).isNumber() &&
         vect.at(1).isNumber() && !vect.at(vect.size() - 1).isNumber();
}

bool RpnUtils::isValidStack(std::stack<Element> stack) {
  std::vector<Element> vect = convertToVect(stack);
  return isValidStack(vect);
}

std::string RpnUtils::to_string(std::stack<Element> stack) {
  std::vector<Element> vect = convertToVect(stack);
  std::string toReturn = "";

  for (auto each : vect) {
    toReturn += each.getString();
  }

  return toReturn;
}
