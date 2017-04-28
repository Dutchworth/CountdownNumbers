#include "Element.h"
#include "ElementHelpers.h"

Element::Element() : m_value(0), m_operation(NUMBER) {
  // do nothing, using member initialisation list
}

Element::Element(const int value) : m_value(value), m_operation(NUMBER) {
  // do nothing, using member initialisation list
}

Element::Element(const Operation operation) : m_value(0), m_operation(operation) {
  // do nothing, using member initialisation list
}

Element::~Element() {
  // do nothing, not responsible for any allocated resources
}

Element::Element(const Element& other) : m_value(other.m_value), m_operation(
    other.m_operation) {
  // do nothing, using member initialisation list
}

Element& Element::operator=(const Element& other) {
  m_value     = other.m_value;
  m_operation = other.m_operation;

  return *this;
}

int Element::getValue() const {
  return m_value;
}

Operation Element::getOperation() const {
  return m_operation;
}

bool Element::isNumber() const {
  return m_operation == NUMBER;
}

std::string Element::getString() const {
  if (isNumber()) {
    return std::to_string(m_value);
  } else {
    return getOperationString(m_operation);
  }
}
