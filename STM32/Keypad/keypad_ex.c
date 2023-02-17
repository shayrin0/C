

/*
    Interfacing keypad and MCU

    MCU: STM32f407
*/
#include <stdint.h>

int main()
{
    // peripheral register addresses
    uint32_t volatile *const pGPIODModeReg   =   (uint32_t*) (0x40020C00);
    uint32_t volatile *const pInPutDataReg   =   (uint32_t*) (0x40020C00+0x10);
    uint32_t volatile *const pOutPutDataReg  =   (uint32_t*) (0x40020C00+0x14);
    uint32_t volatile *const pClockCtrlReg   =   (uint32_t*) (0x40023800+0x30);
    uint32_t volatile *const pPullupDownReg  =   (uint32_t*) (0x40020C00+0x0C);

    // 1. enable the peripheral clock of GPIOD peripheral
    *pClockCtrlReg |= (1 << 3);

    // 2. configure PD0, PD1, PD2, PD3 as output (rows of the keypad)
    *pGPIODModeReg &= ~(0xFF); // clear the bits first
    *pGPIODModeReg |= 0x55; // configure them

    // 3. configure PD8, PD9, PD10, PD11 as input (columns of the keypad)
    *pGPIODModeReg &= ~(0xFF << 16); // clear the bits to make the pins as input

    // 4. enable internal pull-up registors for PD8, PD9, PD10, PD11
    *pGPIODModeReg &= ~(0xFF << 16); // clear
    *pGPIODModeReg |= (0x55 << 16);
}