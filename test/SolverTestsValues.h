#ifndef SOLVERTESTVALUES_H
#define SOLVERTESTVALUES_H

#include "Element.h"
#include <vector>

namespace testValues {
std::vector<int> nums2 { { 5, 4 } };

std::vector<std::vector<Element> > eqs { { Element(4), Element(5),
                                           Element(PLUS) },
                                         { Element(5), Element(4),
                                          Element(PLUS) },
                                         { Element(4), Element(5),
                                          Element(MINUS) },
                                         { Element(5), Element(4),
                                          Element(MINUS) },
                                         { Element(4), Element(5), Element(
                                            MULTIPLY) },
                                         { Element(5), Element(4), Element(MULTIPLY) },
                                         { Element(4), Element(5), Element(DIVIDE) },
                                         { Element(5), Element(4), Element(DIVIDE) } };
}

#endif // ifndef SOLVERTESTVALUES_H
