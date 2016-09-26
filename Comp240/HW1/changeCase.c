// Author: Duc Le
// Created on Sept 17, 2016
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>  //useful character operations

// The mask used to convert strings with suitable bitwise operation.
unsigned char mask = 0x20;
/*
 * Purely for an example of looping through a string.
 * Use as a guide- you will need to do more.
 */
void printStr(char *s) {
    /* loop over a string using subscript*/
    int i;
    for(i = 0; i < strlen(s); i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}

/*
 * Useful helper function to build up a string by adding a char
 * to the end. Found on: https://ubuntuforums.org/showthread.php?t=1016188
 */
void append(char* s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

/*
 * Toggles the case of every alphabetic character in the string,
 * keeping non-alpha charaters intact.
 */
void toggleCase(char *s, char *newstr){
    strcpy(newstr, ""); // initialize
    int i;
    for (i = 0; i<strlen(s); i++) {
        if (isalpha(s[i])) { // Check if the character is alphabetic.
            char change = mask ^ s[i]; // Change the third bit of the character to make it become its counterpart.
            append(newstr,change); // Add the character to result string.
        } else {
            append(newstr,s[i]);
        }
    }

}

/*
 * Lowers the case of every alphabetic character in the string,
 * keeping non-alpha charaters intact.
 */
void lowerCase(char *s, char *newstr){
    strcpy(newstr, ""); // initialize
    int i;
    for (i=0; i<strlen(s); i++) {
        if ((isalpha(s[i])) && (isupper(s[i]))) { // Check if the character is alphabetic and upper case.
            char change = mask ^ s[i]; // If the character is alphabetic and upper case, change the third bit to 0.
            append(newstr,change); // Add the new character to the result string.
        }
        else {
            append(newstr,s[i]);
        }
    }
}

/*
 * Raises the case of every alphabetic character in the string,
 * keeping non-alpha charaters intact.
 */
void upperCase(char *s, char *newstr){
    strcpy(newstr, ""); // initialize
    int i;
    for (i=0; i<strlen(s); i++) {
        if ((isalpha(s[i])) && (islower(s[i]))) { // Check if the character is alphabetic and lower case.
            char change = mask ^ s[i]; // If the character is alphabetic and lower case, change the third bit to 1.
            append(newstr,change);
        }
        else {
            append(newstr,s[i]);
        }
    }
}

int main()
{
    char input_string[54] = "My name is Duc, born in 1996, and from Vietnam, DONE!";
    char result_string[54] = "";
    char empty_string[1] = "";
    char single_string[2] = "a";
    // Check with normal cases
    lowerCase(input_string,result_string);
    assert(strcmp(result_string,"my name is duc, born in 1996, and from vietnam, done!")==0);
    upperCase(input_string,result_string);
    assert(strcmp(result_string,"MY NAME IS DUC, BORN IN 1996, AND FROM VIETNAM, DONE!")==0);
    toggleCase(input_string,result_string);
    assert(strcmp(result_string,"mY NAME IS dUC, BORN IN 1996, AND FROM vIETNAM, done!")==0);
    // Check with empty string
    lowerCase(empty_string, result_string);
    assert(strcmp(result_string,"")==0);
    upperCase(empty_string,result_string);
    assert(strcmp(result_string,"")==0);
    toggleCase(empty_string,result_string);
    assert(strcmp(result_string,"")==0);
    // Check with single character string
    lowerCase(single_string, result_string);
    assert(strcmp(result_string,"a")==0);
    upperCase(single_string,result_string);
    assert(strcmp(result_string,"A")==0);
    toggleCase(single_string,result_string);
    assert(strcmp(result_string,"A")==0);
    printf("All test passed!!!\n");


    return 0;
}