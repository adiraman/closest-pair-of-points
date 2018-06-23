#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H

#include "mergeSort.h"
#include <cmath>
#include <limits>
#include <functional>

typedef std::pair<point, point> ptPair;
typedef std::pair<std::pair<point, point>, double> ptDistPair;

#define DIST std::numeric_limits<double>::max()
#define VALID 1
#define INVALID 0

ptDistPair bruteForce(const pointVec& pv);

ptDistPair closest_2(const ptDistPair& p1, const ptDistPair& p2);

ptDistPair closest_3(const ptDistPair& p1, const ptDistPair& p2,
    const ptDistPair& p3);

ptDistPair closestPair(const pointVec& pv);

ptDistPair rcp(const pointVec& pvx, const pointVec& pvy);

int closestSplitPair(const pointVec& pvx, const pointVec& pvy,
    ptDistPair* CPM, double delta);

#endif /* ifndef CLOSEST_PAIR_H */
