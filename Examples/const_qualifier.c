
/*
    Although we can't change the value of a const variable using its name,
    its value can still be changed using the variable's address.

    'const' doesn't mean that the value never changes, it is only a programming
    safety feature to ensure that the programmer wouldn't try to modify the value
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t const data = 10;

    printf("Value = %u.\n", data);

    uint8_t *ptr = (uint8_t*) &data;
    *ptr = 50;

    printf("Value = %u.\n", data);

    return 0;
}