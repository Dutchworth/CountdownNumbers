#include "ElementHelpers.h"
#include <string>
#include <ostream>
#include <vector>

// print operator
std::ostream & operator<<(std::ostream& os, const Element& element) {
  return os << element.getString();
}

// comparison operators
bool operator==(const Element& a, const Element& b) {
  return (a.isNumber() == b.isNumber()) && (a.getValue() == b.getValue()) &&
         (a.getOperation() == b.getOperation());
}

bool operator!=(const Element& a, const Element& b) {
  return !(a == b);
}

bool operator<(const Element& a, const Element& b) {
  if (a.isNumber() && b.isNumber()) {
    return a.getValue() < b.getValue();
  } else if (!a.isNumber() && !b.isNumber()) {
    return a.getOperation() < b.getOperation();
  } else {
    return a.isNumber(); // this will evaluate numbers to be lower than
                         // operators
  }
}

bool operator>(const Element& a, const Element& b) {
  return b < a;
}

bool operator<=(const Element& a, const Element& b) {
  return !(a > b);
}

bool operator>=(const Element& a, const Element& b) {
  return !(a < b);
}

// get string representation of the given operation
std::string getOperationString(const Operation operation) {
  switch (operation) {
  case PLUS:
    return std::string("+");

  case MINUS:
    return std::string("-");

  case MULTIPLY:
    return std::string("*");

  case DIVIDE:
    return std::string("/");

  default:
    return std::string("");
  }
}

// gets the result of the given operation on the given values
int performOperation(const int a, const Operation operation, const int b) {
  switch (operation) {
  case PLUS:
    return a + b;

  case MINUS:
    return a - b;

  case MULTIPLY:
    return a * b;

  case DIVIDE:

    // only return divide operation if the result is an integer
    if ((a == 0) || (b == 0)) {
      return 0;
    } else if (a % b == 0) {
      return a / b;
    } else {
      return 0;
    }

  default:
    return 0;
  }
}

// convert a vector of integers to Element with those values
std::vector<Element>convertToElement(std::vector<int>input) {
  std::vector<Element> toReturn;

  for (auto item : input) {
    toReturn.push_back(Element(item));
  }

  return toReturn;
}

// convert a 2d vector of integers to Element with those values
std::vector<std::vector<Element> >convertToElement(
  std::vector<std::vector<int> >input) {
  std::vector<std::vector<Element> > toReturn;

  for (auto each : input) {
    std::vector<Element> newEach;

    for (auto item : each) {
      newEach.push_back(Element(item));
    }

    toReturn.push_back(newEach);
  }

  return toReturn;
}
