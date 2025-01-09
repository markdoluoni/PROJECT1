#include "major1.h"

// Function: clz
// Description: count the number of leading zeros in a 32-bit unsigned integer

unsigned int clz (unsigned int num) {
    unsigned int count = 0;

    //shift left bit and count leading zeroes
    while((num & 0x80000000) == 0) {
        num = num << 1; //left shift by 1
        count++;
    }

    return count;
}