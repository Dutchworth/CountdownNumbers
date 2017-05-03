#include "ElementHelpers.h"
#include <string>
#include <ostream>

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
    return a / b;

  default:
    return 0;
  }
}
