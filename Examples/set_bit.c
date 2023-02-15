#include <stdio.h>
#include <stdint.h>

/*
    Write a program to set the 4th and 7th bit positions
    of a given number.
    For set operation, the bit-wise OR should be used.
*/

int main()
{
    int32_t num = 56;

    printf("The number is 0x%x.\n", num);

    num |= 0x90;

    printf("The number is 0x%x.\n", num);

    return 0;
}