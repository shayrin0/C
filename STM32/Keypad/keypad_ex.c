

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

    // make all rows HIGH
    *pOutPutDataReg |= 0x0F;

    // make R1 Low (PD0)
    *pOutPutDataReg &= ~(1 << 0);

    // scan the columns
    // check C1(PD8) low or high
    if (!(*pInPutDataReg & (1 << 8)))
    {
        delay();
        printf("1\n");
    }
    if (!(*pInPutDataReg & (1 << 9)))
    {
         delay();
        printf("2\n");
    }
    if (!(*pInPutDataReg & (1 << 10)))
    {
        delay();
        printf("3\n");
    }
    if (!(*pInPutDataReg & (1 << 11)))
    {
        delay();
        printf("4\n");
    }

    // make all rows HIGH
    *pOutPutDataReg |= 0x0F;

    // make R2 Low (PD1)
    *pOutPutDataReg &= ~(1 << 1);

    // scan the columns
    // check C1(PD8) low or high
    if (!(*pInPutDataReg & (1 << 8)))
    {
        delay();
        printf("4\n");
    }
    if (!(*pInPutDataReg & (1 << 9)))
    {
         delay();
        printf("5\n");
    }
    if (!(*pInPutDataReg & (1 << 10)))
    {
        delay();
        printf("6\n");
    }
    if (!(*pInPutDataReg & (1 << 11)))
    {
        delay();
        printf("B\n");
    }

    // make all rows HIGH
    *pOutPutDataReg |= 0x0F;

    // make R3 Low (PD2)
    *pOutPutDataReg &= ~(1 << 2);

    // scan the columns
    // check C1(PD8) low or high
    if (!(*pInPutDataReg & (1 << 8)))
    {
        delay();
        printf("7\n");
    }
    if (!(*pInPutDataReg & (1 << 9)))
    {
         delay();
        printf("8\n");
    }
    if (!(*pInPutDataReg & (1 << 10)))
    {
        delay();
        printf("9\n");
    }
    if (!(*pInPutDataReg & (1 << 11)))
    {
        delay();
        printf("C\n");
    }
}