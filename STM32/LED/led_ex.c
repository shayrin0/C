

/*
    Turn on the LED:
    1. Identify the GPIO port used to connect the LED
    2. Identify the GPIO pin where the LED is connected
    3. Activate the GPIO peripheral (Enable the clock) -> use RCC (Reset and Clock Control)
    4. Configure the GPIO pin mode as output
    5. Write to the GPIO pin

    MCU: STM32f407

    Base address of RCC: 0x40023800
    In order to access GPIOD_en register: 0x40023800 + 0x30 = 0x40023830

    Address of GPIOD mode register: 0x40020C00 + 0x00 = 0x40020C00

    Address of GPIOD output data register: 0x40020C00 + 0x14 = 0x40020C14
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

    // set 12th bit of the GPIOD as HIGH
    *pPortDOutReg |= (1 << 12); // instead of 0x1000

    while (1);
}