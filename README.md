# Closest Pair of Points

Input :- Set of Points {P1, P2, ...., Pn} in a 2-D plane with euclidean distance d defined between them.

Output :- A pair P*, Q* belongs to above P of distinct points that minimize the euclidean distance between P* and Q*

Algorithm :-

1.  Make copies of pts sorted by x & y using merge sort.
2.  Let L = Left half of P; R = Right half of P. Best case => 4 pts. solve by brute force.
3.  (P1, P2) = closetPair(Lx, Ly).
4.  (P3, P4) = closestPair(Rx, Ry).
5.  let del = min{d(P1, P2), d(P3, P4)}.
6.  (P5, P6) = closestSplitPair(Px, Py, del).
7.  return best of {(P1, P2); (P3, P4); (P5, P6)}.

closestSplitPair(Px, Py, del)

1.  Let X_bar = biggest X co-ordinate in left half of P
2.  S_y = pts. of P with X co-ordinate in [X_bar-del, X_bar + del] sorted by Y.
3.  initialize best = del, best pair = null
4.  for i = 1 to |S_y| - 1
5.    for j = 1 to min{7, |S_y| - i}
6.      P5, P6 = ith, (j+i)th points of S_y
7.      if d(P5,P6) < best
8.        best = d, best pair = (P5, P6)