//
// Created by Duc Le on 9/8/16.
//
#include <stdio.h>

int a[5] = {1,2,3,4,5};

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last  = cnt - 1; first <= last; first++, last--) {
        inplace_swap(&a[first],&a[last]);
    }
}

int main() {
    reverse_array(a,5);
    for (int i = 0; i < 5; ++i) {
        printf("%d",a[i]);
    }
}
