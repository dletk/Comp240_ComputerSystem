//
// Created by Duc Le on 10/8/16.
//
#include <stdio.h>

swap(int* px, int* py);

int main() {
    int a = 100;
    int b = 200;
    swap(&a,&b);
    printf("%d and %d",a,b);
    return 0;
}

swap(int* px, int* py) {
    int valueX = *px;
    *px = *py;
    *py = valueX;
}
