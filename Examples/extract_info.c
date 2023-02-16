
/*
    Write a program to decode a given 32bit packet information and
    print the values of different fields. Create a structure with
    member elements as packet fields.
*/

#include <stdio.h>
#include <stdint.h>

struct Packet
{
    uint8_t crc;
    uint8_t status;
    uint16_t payload;
    uint8_t bat;
    uint8_t sensor;
    uint8_t longAddr;
    uint8_t shortAddr;
    uint8_t addrMode;
};


int main()
{

    return 0;
}