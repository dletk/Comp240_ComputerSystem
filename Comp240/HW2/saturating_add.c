// Author: Duc Le
// Created on Sept 28, 2016
#include<stdio.h>
#include<limits.h>
#include<assert.h>

/*
 * Returns the maximum long integer possible if the addition of the two positive numbers x and y causes positive overflow.
 *
 * Return the minimum long integer possible if the addition of 2 negatives numbers x and y causes negative overflows.
 *
 * Returns the addition of the 2 numbers otherwise.
 */
long saturating_add_long(long x, long y) {
    long rawResult = x + y;	// The variable to hold the actual addition value
    if (x>0 && y>0 && rawResult<0) {
        return LONG_MAX;
    } else if (x<0 && y<0 && rawResult>0) {
        return LONG_MIN;
    } else {
        return rawResult; // Return the actual addition value if there is no overflow
    }
}

/* The main function for testing the saturating_add_long function
 *
 * Print out All tests passed! and return 0 if done sucessfully
 */
int main() {
    long x, y;
    // Case 1: x and y are both positive with the sum < MAX
    x = 72036854775807;
    y = 92233720368547;
    assert(saturating_add_long(x,y) == 164270575144354);
    // Case 2: x and y are both negative with the sum > MIN
    x = -1234567890123;
    y = -9887656765662;
    assert(saturating_add_long(x,y) == -11122224655785);
    // Case 3: x and y are a negtive and a positive long
    x = 3372036854775807;
    y = -9223036854775808;
    assert(saturating_add_long(x,y) == -5851000000000001);
    // Case 3: x and y are the maximum and minimom long
    x = LONG_MAX;
    y = LONG_MIN;
    assert(saturating_add_long(x,y) == -1);
    // Case 4: x and y are 0 and 1 respectively
    x = 0;
    y = 1;
    assert(saturating_add_long(x,y) == 1);
    // Case 5: x is 0 and y is LONG_MAX
    x = 0;
    y = LONG_MAX;
    assert(saturating_add_long(x,y) == LONG_MAX);
    // Case 5: x is 0 and y is LONG_MIN
    x = 0;
    y = LONG_MIN;
    assert(saturating_add_long(x,y) == LONG_MIN);

    // All cases below are the special cases
    // Case 6: x and y are both positive with sum > LONG_MAX
    x = 9223372036854712345;
    y = 854775807;
    assert(saturating_add_long(x,y) == LONG_MAX);
    // Case 7: x and y are LONG_MAX and some positive number
    x = LONG_MAX;
    y = 1234556456;
    assert(saturating_add_long(x,y) == LONG_MAX);
    // Case 8: x and y are LONG_MAX and 1
    x = LONG_MAX;
    y = 1;
    assert(saturating_add_long(x,y) == LONG_MAX);
    // Case 9: x and y are some negative numbers with sum<LONG_MIN
    x = -9223372036854770000;
    y = -1231242342342;
    assert(saturating_add_long(x,y) == LONG_MIN);
    // Case 10: x and y are LONG_MIN and some negative number
    x = LONG_MIN;
    y = -12345;
    assert(saturating_add_long(x,y) == LONG_MIN);
    // Case 11: x and y are LONG_MIN and -1
    x = LONG_MIN;
    y = -1;
    assert(saturating_add_long(x,y) == LONG_MIN);
    // Print out when all tests passed
    printf("All tests passed!\n");

    return 0;
}