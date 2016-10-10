//
// Created by Duc Le on 10/8/16.
//

#include <stdio.h>
#include <assert.h>

/*
 * Return the length of string s
 */
int stringlen(char* s) {
    int i;
    for (i = 0; *s != NULL; s++) {
        i++;
    }
    return i;
}

int main() {
//    The reason that both declarations will work is because a string can be an array of character (string2) or can be declared with a pointer
//    of char (string1). In string1, the string address will also be first character address, so the pointer string1 is actually point to
//    the string itself. For string2, an array has the value is the address of the first element. So both are pointer eventually.
//    printf("Hello\n");
    testStringlen();
    char* string1 = "this is a string";
    char string2[] = "this is also a string";

    int result1 = stringlen(string1);
    int result2 = stringlen(string2);

    printf("Length of string1: %d \n", result1);
    printf("Length of string2: %d \n", result2);
}

int testStringlen() {
    assert(stringlen("HelloWorld") == 10);
    assert(stringlen("abc def 1234") == 12);
    assert(stringlen("  aat d12 !@#$%^") == 16);
}