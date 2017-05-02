#ifndef STATSUTILSTESTSVALUES_H
#define STATSUTILSTESTSVALUES_H

#include <vector>

namespace testValues {
std::vector<int> nums4 { { 1, 2, 3, 4 } };

std::vector<std::vector<int> > combs4to1 { { 1 },
                                           { 2 },
                                           { 3 },
                                           { 4 } };
std::vector<std::vector<int> > combs4to2 { { 1, 2 },
                                           { 1, 3 },
                                           { 1, 4 },
                                           { 2, 3 },
                                           { 2, 4 },
                                           { 3, 4 } };
std::vector<std::vector<int> > combs4to3 { { 1, 2, 3 },
                                           { 1, 2, 4 },
                                           { 1, 3, 4 },
                                           { 2, 3, 4 } };
std::vector<std::vector<int> > combs4to4 { { 1, 2, 3, 4 } };

std::vector<std::vector<int> > perms { { 1, 2, 3, 4 },
                                       { 1, 2, 4, 3 },
                                       { 1, 3, 2, 4 },
                                       { 1, 3, 4, 2 },
                                       { 1, 4, 2, 3 },
                                       { 1, 4, 3, 2 },
                                       { 2, 1, 3, 4 },
                                       { 2, 1, 4, 3 },
                                       { 2, 3, 1, 4 },
                                       { 2, 3, 4, 1 },
                                       { 2, 4, 1, 3 },
                                       { 2, 4, 3, 1 },
                                       { 3, 1, 2, 4 },
                                       { 3, 1, 4, 2 },
                                       { 3, 2, 1, 4 },
                                       { 3, 2, 4, 1 },
                                       { 3, 4, 1, 2 },
                                       { 3, 4, 2, 1 },
                                       { 4, 1, 2, 3 },
                                       { 4, 1, 3, 2 },
                                       { 4, 2, 1, 3 },
                                       { 4, 2, 3, 1 },
                                       { 4, 3, 1, 2 },
                                       { 4, 3, 2, 1 } };

std::vector<std::vector<int> > combsReps4to1 { { 1 },
                                               { 2 },
                                               { 3 },
                                               { 4 } };
std::vector<std::vector<int> > combsReps4to2; // TODO finish these
std::vector<std::vector<int> > combsReps4to3;
std::vector<std::vector<int> > combsReps4to4;
}

#endif // ifndef STATSUTILSTESTSRESOURCES_H
