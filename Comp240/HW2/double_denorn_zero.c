// Author: Duc Le
// Created on Sept 28, 2016
#include <stdio.h>
#include <assert.h>

/* use typedef so that an unsigned value becomes the bits for a
 hypothetical floting point representation
*/
typedef unsigned float_bits;
typedef unsigned long double_bits;

/*
 * This fnction takes an unsigned value an checks to see if its
 * binary form represents a normalized or denormalized floating
 * point number.
 * paramter: f   is a 32-bit representation of some IEEE single precision number
 *
 * returns: an unsigned value that is  +/-0  if f is a denormalized number
 * OR returns f itself if it is a normalized number
 */
float_bits float_denorn_zero(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f>>31; // To get the bit of sign only
    unsigned exp =  f>>23 & 0xFF; // Shift to left 23 bits, so only the sign bit and the exp left, then use bitwise to takeout 8 last bits by mask 0xff
    unsigned frac = f     & 0x7FFFFF; // Take 23 last bits of f by using mask 0x7fffff to have 23 last bits are all 1.

    if (exp == 0) {  // denormalized
        frac = 0;
    }
    return (sign << 31) | (exp << 23) | frac ;
}

double_bits double_denorn_zero(double_bits f) {
    // Decompose bit repesentation into parts
    unsigned long sign = f>>63;
    unsigned long exp = f>>52 & 0x7ff; // Shift to the left 52 bits, so only the sign bit and the exp left, then use the bitwise to take out 11 bits by mask 0x7ff
    unsigned long frac = f & 0xFFFFFFFFFFFFF; // Take 52 last bits of f using mask 0xFFFFFFFFFFFFF

    if (exp == 0) {
        frac  = 0;
    }

    return (sign << 63) | (exp << 52) | frac;
}


int main() {
    // Case 1: Normalized number
    float_bits value = 0x12345678;
    assert(float_denorn_zero(value) == 0x12345678);
    // Case 2: Denormalized number with sign +
    value = 0x345678;
    assert(float_denorn_zero(value) == 0);
    // Case 3: Denormalized number with sign -
    value = 0x80345678;
    assert(float_denorn_zero(value) == 0x80000000);// Negative 0
    // Case 4: Normalized negative number
    value = 0x8A74F5C6;
    assert(float_denorn_zero(value) == 0x8A74F5C6);
    // Case 5: Denormalized 0, +
    value = 0x00000000;
    assert(float_denorn_zero(value) == 0);
    // Case 6: Dernormilzed 0, -
    value = 0x80000000;
    assert(float_denorn_zero(value) == 0x80000000);
    // Case 7: Normalized 1, +
    value = 0x3F800000;
    assert(float_denorn_zero(value) == 0x3F800000);
    // Case 8: Normalized 1, -
    value = 0xbF800000;
    assert(float_denorn_zero(value) == 0xbF800000);

    // Check case for double_denorn_zero()
    // Case 1: Normalized number, +
    double_bits value2 = 0x123456789abcdeff;
    assert(double_denorn_zero(value2) == 0x123456789abcdeff);
    // Case 2: Normalized number, -
    value2 = 0x823456789ABCDEFF;
    assert(double_denorn_zero(value2) == 0x823456789ABCDEFF);
    // Case 3: Denormalized number, +
    value2 = 0x456789ABCDEFF;
    assert(double_denorn_zero(value2) == 0);
    // Case 4: Denormalized number, -
    value2 = 0x800456789ABCDEFF;
    assert(double_denorn_zero(value2) == 0x8000000000000000); // Negative zero
    // Case 5: Denormalized number 0, +
    value2 = 0x0;
    assert(double_denorn_zero(value2) == 0);
    // Case 6: Dernomalized number 0, -
    value2 = 0x8000000000000000;
    assert(double_denorn_zero(value2) == 0x8000000000000000);
    // Case 7: Normalized number 1, +
    value2 = 0x3FF0000000000000;
    assert(double_denorn_zero(value2) == 0x3FF0000000000000);
    // Case 8: Normalized number 1, -
    value2 = 0xbFF0000000000000;
    assert(double_denorn_zero(value2) == 0xbFF0000000000000);

    printf("All tests passed!\n");
    return 0;
}
