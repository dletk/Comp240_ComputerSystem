#include <stdio.h>
//
// Created by Duc Le on 9/7/16.
//
typedef unsigned char *byte_pointer;

void show_byte(byte_pointer start, size_t len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x",start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_byte((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_byte((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_byte((byte_pointer) &x, sizeof(void *));
}

void test_show_byte(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main() {
    test_show_byte(0x12345);
}