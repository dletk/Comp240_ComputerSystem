//
// Created by Duc Le on 9/14/16.
//

#include <stdio.h>
#include <string.h>

void printSomething(char* input);
void modifyInt(int* input);

int main() {
    char bin_string[2] = {"a"};
    printSomething(bin_string);
    printf("%s",bin_string);
    int a = 9;
    modifyInt(&a);
    printf("%d",a);
    return 0;
}

void printSomething(char* input) {
    strcat(input,"812");
}

void modifyInt(int* input) {
    input = input + 1;
}