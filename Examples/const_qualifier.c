
/*
    Although we can't change the value of a const variable using its name,
    its value can still be changed using the variable's address.

    'const' doesn't mean that the value never changes, it is only a programming
    safety feature to ensure that the programmer wouldn't try to modify the value

    - All local const variables are placed in RAM.
    - All global const variables are placed in ROM or FLASH.
    - In STM32, all global const variables live in FLASH memory. So, when you
      try to modify const variable using its address, operation has no effect.
      Because flash memory of the MCU is write-protected.
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