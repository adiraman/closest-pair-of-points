#include "mergeSort.h"

pointVec merge(const pointVec& l, const pointVec& r, bool X)
{
    pointVec m;
    // declare indices to the left and right sub arrays
    int i{ 0 }, j{ 0 };
    int lsz = l.size();
    int rsz = r.size();

    while (i < lsz && j < rsz) {
        if (X) // sort by X
        {
            if (l[i].x > r[j].x) {
                m.push_back(r[j]);
                ++j;
            } else {
                m.push_back(l[i]);
                ++i;
            }
        } else // sort by Y
        {
            if (l[i].y > r[j].y) {
                m.push_back(r[j]);
                ++j;
            } else {
                m.push_back(l[i]);
                ++i;
            }
        }
    }

    while (i < lsz && j == rsz) {
        m.push_back(l[i]);
        ++i;
    }

    while (i == lsz && j < rsz) {
        m.push_back(r[j]);
        ++j;
    }

    return m;
}

pointVec mergeSort(const pointVec& a, bool X)
{
    // Check for base case to stop the recursion
    int n = a.size();
    if (n == 1)
        return a;

    // Partition to Left and Right halves
    pointVec l, r;
    for (int i = 0; i < n; ++i) {
        if (i < n / 2)
            l.push_back(a[i]);
        else
            r.push_back(a[i]);
    }

    // Make recursive calls to  further sub divide the input arrays
    pointVec l1 = mergeSort(l, X);
    pointVec r1 = mergeSort(r, X);

    // Merge the left and right halves procedurally and return
    return merge(l1, r1, X);
}

void printPoints(const pointVec& a)
{
    for (auto i : a) {
        std::cout << "{" << i.x << ", " << i.y << "}"
                  << "; ";
    }
    std::cout << std::endl;
}
