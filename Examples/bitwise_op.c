#include <stdio.h>
#include <stdint.h>

/*
    Test the bitwise operators
*/

int main()
{
    int32_t num1, num2;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Bitwise AND(&) : %d\n", (num1 & num2)); // testing bits
    printf("Bitwise OR(|) : %d\n", (num1 | num2)); // setting bits
    printf("Bitwise XOR(^) : %d\n", (num1 ^ num2)); // clearing bits
    printf("Bitwise NOT(~) : ~num1=%d, ~num2=%d\n", num1, num2); // toggling bits

    return 0;
}