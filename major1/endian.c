#include "major1.h"
int endian(int n) {
    // Swap bytes using bitwise operations
    int byte0 = (n & 0x000000FF) << 24; // Move B0 to B3
    int byte1 = (n & 0x0000FF00) << 8;  // Move B1 to B2
    int byte2 = (n & 0x00FF0000) >> 8;  // Move B2 to B1
    int byte3 = (n & 0xFF000000) >> 24; // Move B3 to B0

    // Combine the swapped bytes into a 32-bit result
    return (byte0 | byte1 | byte2 | byte3);
}
