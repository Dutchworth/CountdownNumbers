#include <iostream>

#include "Element.h"
#include "ElementHelpers.h"

int main(int argc, char **argv) {
  Element element1(PLUS);
  Element element2(3);

  std::cout << "Element1 = " << element1 << '\n';
  std::cout << "Element2 = " << element2 << std::endl;

  return 0;
}
