//
// Created by Duc Le on 9/28/16.
//
// Author: Duc Le

#include<stdio.h>
#include<assert.h>

/* Function to multiply a constant with 17 using only bitwise operation and addition/substraction.
 */
int multiply17(int x) {
    int result = (x<<4) + x; // As we know that 17 = 2^4 + 1
    return result;
}
/* Function to multiply a constant with -7 using only bitwise operation and addition/substraction.
 */
int multiplyNeg7(int x) {
    int result = x - (x<<3); // As we know that -7 = 1 - 2^3
    return result;
}
/* Function to multiply a constant with 60 using only bitwise operation and addition/substraction.
 */
int multiply60(int x) {
    int result = (x<<6) - (x<<2); // As we know that 60 = 2^6 - 2^2
    return result;
}
/* Function to multiply a constant with -112 using only bitwise operation and addition/substraction.
 */
int multiplyNeg112(int x) {
    int result = (x<<4) - (x<<7); // As we know that -112 = 2^4 - 2^7
    return result;
}

/* Main function to tests all the multiply functions.
 *
 * Print out All tests passed! and return 0 if done sucessfully.
 */
int main() {
    // For each function, test to multiply with 0, 1, positive, negative numbers.
    // Test for multiply with 17
    assert(multiply17(0) == 0);
    assert(multiply17(1) == 17);
    assert(multiply17(10) == 170);
    assert(multiply17(-5) == -85);
    // Test for multiply with -7
    assert(multiplyNeg7(0) == 0);
    assert(multiplyNeg7(1) == -7);
    assert(multiplyNeg7(5) == -35);
    assert(multiplyNeg7(-7) == 49);
    // Test for multiply with 60
    assert(multiply60(0) == 0);
    assert(multiply60(1) == 60);
    assert(multiply60(5) == 300);
    assert(multiply60(-7) == -420);
    // Test for multiply with -112
    assert(multiplyNeg112(0) == 0);
    assert(multiplyNeg112(1) == -112);
    assert(multiplyNeg112(-11) == 1232);
    assert(multiplyNeg112(11) == -1232);

    printf("All tests passed!\n");
    return 0;
}