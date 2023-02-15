

/*
    Toggle the LED using a software delay
*/
#include <stdint.h>

int main()
{
    uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
    uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
    uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;

    // enable the clock for GPIOD peripheral in the AHB1ENR (SET the 3rd bit position)
    *pClkCtrlReg |= (1 << 3); // instead of 0x08

    // configure the mode of the IO pin as output
    // first clear the 24th and 25th bit positions
    *pPortDModeReg &= ~(3 << 24); // instead of 0xFCFFFFFF
    // then make the 24th bit position as 1
    *pPortDModeReg |= (1 << 24); // instead of 0x01000000

    while(1)
    {
        // set 12th bit of the GPIOD as HIGH
        *pPortDOutReg |= (1 << 12); // instead of 0x1000

        // this loop executes for 10k times
        for (uint32_t i=0; i < 10000; i++);

        // turn off the LED
        *pPortDOutReg &= ~(1 << 12); 

        for (uint32_t i=0; i < 10000; i++);
    }
    
}