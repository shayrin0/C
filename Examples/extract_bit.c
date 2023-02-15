
/*
    Extract bit positions from 9th to 14th in a given data
    and save it in to another variable.

    Procedure:
    1. Shift the identified portion to right hand side until 
    it touches the lsb (0th bit)
    2. Mask the value to extract only 6 bits [5:0] and then
    save it in to another variable
*/

#include <stdint.h>

int main()
{
    uint16_t Data = 0xB410;
    uint8_t output;

    output = (uint8_t) ((Data >> 9) & 0x003F);
    printf("The output value is 0x%x.\n", output);

    return 0;
}