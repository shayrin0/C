#include <stdio.h>
#include <stdint.h>

/*
    Check if a number is even or odd using Bit-Masking
    even number: the lsb is zero
    odd number: the lsb is one
    for checking the lsb, the mask should have 1 in its lsb
*/

int main()
{
    int32_t num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num & 1)
        printf("%d is an odd number!\n", num);
    else
        printf("%d is an even number!\n", num);

    return 0;
}