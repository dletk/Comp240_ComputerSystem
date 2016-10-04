//
// Created by Duc Le on 10/4/16.
//
#include <stdio.h>

long mult2(long, long);

void mulstore(long x, long y, long *dest) {
    long t = mult2(x,y);
    *dest = t;
}

long mult2(long a, long b) {
    long s = a*b;
    return s;
}

int main() {
    long d;
    mulstore(2, 3, &d);
    printf("2*3 --> %ld\n",d);
    return 0;
}