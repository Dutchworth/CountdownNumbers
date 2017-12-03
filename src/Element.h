#ifndef ELEMENT_H
#define ELEMENT_H

#include <ostream>
#include <string>

enum Operation { PLUS, MINUS, MULTIPLY, DIVIDE, NUMBER };

class Element {
 private:
  int m_value;
  Operation m_operation;

 public:
  // Constructors
  Element();
  Element(const int value);
  Element(const Operation operation);

  // Destructor
  ~Element();

  // Copy Constructor and assignment operator
  Element(const Element& other);
  Element& operator=(const Element& other);

  // gets the element's value
  int getValue() const;

  // gets the element's held operation
  Operation getOperation() const;

  // returns whether this is a number type element;
  bool isNumber() const;

  // gets string representation of element
  std::string getString() const;
};

#endif  // ifndef ELEMENT_H
