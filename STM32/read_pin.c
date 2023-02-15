
/*
    Write a program which reads the status of the pin PA0.
    If it was LOW, turn off the on-board LED (PD12).
    If it was HIGH, turn on the LED.

    MCU: STM32f407
*/

#include <stdint.h>

int main()
{
    uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
    uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
    uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;

    uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
    uint32_t *pPortAInReg = (uint32_t*)0x40020010;

    // enable the clock for GPIOA & GPIOD peripheral in the AHB1ENR
    *pClkCtrlReg |= (1 << 3);
    *pClkCtrlReg |= (1 << 0);

    // configure the mode of the IO pin as output
    // first clear the 24th and 25th bit positions
    *pPortDModeReg &= ~(3 << 24); // instead of 0xFCFFFFFF
    // then make the 24th bit position as 1
    *pPortDModeReg |= (1 << 24); // instead of 0x01000000

    // configure PA0 as input mode (GPIOA Mode register)
    *pPortAModeReg &= ~(3 << 0);

    while(1)
    {
        // read the pin status of the pin PA0 (GPIOA Input Data Register)
        uint8_t pinStatus = (uint8_t) *pPortAInReg & 0x1;
        
        if(pinStatus)
        {
            // turn on the LED
            *pPortDOutReg |= (1 << 12);
        }
        else
        {
            // turn off the LED
            *pPortDOutReg |= ~(1 << 12);
        }
    }
}