//
// Created by Duc Le on 11/2/16.
//

#include <stdio.h>

long loop1(long x, char n) {
    long result = 0;
    unsigned long mask;
    for (mask = 1; mask != 0; mask = mask<<n) {
        result = result | (x & mask);
    }
    return result;
}

/*
 * Uses a while loop
 */

long loop2(long x, int n) {
    long result;
    while (x > n) {
        x -= 2;
    }
    result = n*x;
    return result;
}

int main() {
    printf("%ld\n", loop1(0x123456ff,'a'));
    printf("%ld", loop2(12345,123));
    return 0;
}