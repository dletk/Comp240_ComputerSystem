//
// Created by Duc Le on 10/8/16.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* createSubstring(char stringIn[], int index) {
    char* substring = malloc(sizeof(stringIn));
    char* stringTemp = malloc(sizeof(stringIn));
    char* address = stringIn + index;
    int i;
    for (i = 0; *address != NULL; address++) {
        strncpy(stringTemp, address,1);
        strncat(substring,stringTemp,1);
        stringIn = stringIn + 1;
    }
    return substring;
}

int main() {
    char* stringIn = "Le Mai Thanh Duc";
    char* stringIn2 = "United World College";
//    char* string3 = (char*) malloc(1 + sizeof(stringIn) + sizeof(stringIn2));
//    strcpy(string3,stringIn);
//    strcat(string3,stringIn2);
    printf("%s\n",createSubstring(stringIn2,7));

    return 0;
}
