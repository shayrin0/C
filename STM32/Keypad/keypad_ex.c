

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

    // 1. Enable the peripheral clock of GPIOD peripheral
    *pClockCtrlReg |= (1 << 3);
}