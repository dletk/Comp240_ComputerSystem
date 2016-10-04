//
// Created by Duc Le on 10/4/16.
//
long mult2(long, long);

void multstore(long x, long y, long *dest) {
    long t = mult2(x, y);
    *dest = t;
}