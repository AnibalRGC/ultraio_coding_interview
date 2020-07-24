#include "bitOperator.hpp"

int add(int a, int b) {
    while (b != 0) {
        //To get the carry, we can use the bit operator &
        // 1 & 1 = 1
        // 1 & 0 = 0
        // 0 & 1 = 0
        // 0 & 0 = 0
        int carry = a & b;

        //To get the sum of two bits, we can use the bit operator XOR
        // 1 ^ 1 = 0 (case where the carry is 1)
        // 1 ^ 0 = 1
        // 0 ^ 1 = 1
        // 0 ^ 0 = 0
        a = a ^ b;

        // To take into account the carry, we set b
        // to the carry shifted by one.
        b = carry << 1;
    }
    return a;
}

