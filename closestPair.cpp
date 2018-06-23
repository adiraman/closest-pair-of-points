#include "closestPair.h"

ptDistPair bruteForce(const pointVec& pv)
{
    double minima = DIST, d;
    ptPair CP;
    int pvsz = pv.size();

    // compare all the points:- O(n*n)
    // Actual no of comparisons are nC2 since d(a,b) = d(b,a)
    for (int i = 0; i < pvsz; ++i) {
        for (int j = i + 1; j < pvsz; ++j) {
            d = dist(pv[i], pv[j]);
            if (d < minima) {
                minima = d;
                CP = std::make_pair(pv[i], pv[j]);
            }
        }
    }
    return std::make_pair(CP, minima);
}

// utility function to calculate the closest of two point pairs
ptDistPair closest_2(const ptDistPair& p1, const ptDistPair& p2)
{
    double d1, d2;
    d1 = p1.second;
    d2 = p2.second;

    return d1 < d2 ? p1 : p2;
}

// utility function to calculate the closest of 3 point pairs
ptDistPair closest_3(const ptDistPair& p1, const ptDistPair& p2,
    const ptDistPair& p3)
{
    return closest_2(closest_2(p1, p2), p3);
}

ptDistPair closestPair(const pointVec& pv)
{
    // make copies of input vector and split into two halves
    pointVec pvx = mergeSort(pv, true);
    pointVec pvy = mergeSort(pv, false);

    return rcp(pvx, pvy);
}

ptDistPair rcp(const pointVec& pvx, const pointVec& pvy)
{
    int sz = pvx.size();

    // base case
    // because the brute force method is only called for a max of 3
    // points, the worst case runtime complexity of the following
    // step is constant time.
    if (sz <= 4)
        return bruteForce(pvx);

    // Split the incoming input vectors into halves L, R
    // runtime complexity of the following is linear
    // since the input vectors are already sorted
    pointVec Lx, Ly, Rx, Ry;
    for (int i = 0; i < sz; ++i) {
        if (i < sz / 2) {
            Lx.push_back(pvx[i]);
            Ly.push_back(pvy[i]);
        } else {
            Rx.push_back(pvx[i]);
            Ry.push_back(pvy[i]);
        }
    }

    // recursive calls
    // because with each recursive call, the problem is divided in
    // half, the time complexity of this step is log(n)
    ptDistPair CPL = rcp(Lx, Ly);
    ptDistPair CPR = rcp(Rx, Ry);
    ptDistPair CP = closest_2(CPL, CPR);
    ptDistPair CPM;

    return closestSplitPair(pvx, pvy, &CPM, CP.second) == VALID ? closest_3(CPL, CPR, CPM) : closest_2(CPL, CPR);
}

int closestSplitPair(const pointVec& pvx, const pointVec& pvy,
    ptDistPair* CPM, double delta)
{
    // set the distance arbitrarily large
    CPM->second = DIST;

    // represents the vertical line separating the two halves
    // take the median point of the vector sorted by X coordinate
    double xBar = pvx[pvx.size() / 2].x;

    // make a new vector containing all the points that lie within
    // the strip of width 2*delta centered at xBar
    pointVec Sy;
    int pvySz = pvy.size();
    for (int i = 0; i < pvySz; ++i) {
        if (pvy[i].x >= xBar - delta && pvy[i].x <= xBar + delta) {
            Sy.push_back(pvy[i]);
        }
    }

    // time complexity for this part is linear.
    // Now check for points within this strip ( in Sy ), that are
    // closer than the closest points either both in L or
    // both in R. For each point in Sy, we only need to check
    // the next 7 because we know that each pair of points in the
    // left side of the strip are at least CP.second away from
    // each other, and it follows that only 8 points can reside in
    // the area we are interested in looking at. So we only need
    // to check the next 7 points in Sy
    int sysz = Sy.size();
    double dp;
    int retval = INVALID;
    for (int i = 0; i < sysz; ++i) {
        for (int j = 1; j < 8 && i + j < sysz; ++j) {
            dp = dist(Sy[i], Sy[i + j]);
            if (dp < delta) {
                delta = dp;
                CPM->first = std::make_pair(Sy[i], Sy[i + j]);
                CPM->second = delta;
                retval = VALID;
            }
        }
    }

    return retval;
}
