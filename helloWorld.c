//
// Created by Duc Le on 9/7/16.
//
#include <stdio.h>

void helperFunction();

int main() {
    printf("Hello World!!!");
    helperFunction();
    return 0;
}

void helperFunction() {
    for (int i = 0; i < 10 ; ++i) {
        printf("This is line number %d\n",i);
    }
}