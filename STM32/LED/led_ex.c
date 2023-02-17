

/*
    Toggle the LED, use structures

    MCU: STM32f407

    Base address of RCC: 0x40023800
    In order to access GPIOD_en register: 0x40023800 + 0x30 = 0x40023830
    Address of GPIOD mode register: 0x40020C00 + 0x00 = 0x40020C00
    Address of GPIOD output data register: 0x40020C00 + 0x14 = 0x40020C14
*/
#include <stdint.h>
#include "led_ex.h"

int main()
{
    RCC_AHB1ENR_t volatile *const pClkCtrlReg = (RCC_AHB1ENR_t*)0x40023830;
    GPIOx_MODE_t volatile *const pPortDModeReg = (GPIOx_MODE_t*)0x40020C00;
    GPIOx_ODR_t volatile *const pPortDOutReg = (GPIOx_ODR_t*)0x40020C14;

    // enable the clock for GPIOD peripheral in the AHB1ENR (SET the 3rd bit position)
    pClkCtrlReg->gpiod_en = 1;

    // configure the mode of the IO pin as output
    pPortDModeReg->pin_12 = 1;

    // set 12th bit of the GPIOD as HIGH
    while(1)
    {
        pPortDOutReg->pin_12 = 1;
        for (uint32_t i=0; i < 300000; i++);

        pPortDOutReg->pin_12 = 0;
        for (uint32_t i=0; i < 300000; i++);
    }
}