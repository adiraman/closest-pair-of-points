#ifndef MERGESORT_H
#define MERGESORT_H

#include <cmath>
#include <iostream>
#include <vector>

struct point {
    double x;
    double y;
};

typedef std::vector<point> pointVec;

inline double dist(point p1, point p2)
{
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

pointVec merge(const pointVec& l, const pointVec& r, bool X);

// if X is true then sort by X coordinate
// else sort by Y coordinate
pointVec mergeSort(const pointVec& a, bool X);

void printPoints(const pointVec& a);

#endif /* ifndef MERGESORT_H */
