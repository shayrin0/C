
/*
    Write a program which counts the number of times that
    a button is pressed (use interrupt).

    MCU: STM32f407
*/

#include <stdio.h>
#include <stdint.h>

uint8_t g_button_pressed = 0;

uint32_t g_button_press_count = 0;

void button_init(void);

uint32_t volatile *pEXTTIPendReg = (uint32_t*)0x40013C14;
uint32_t volatile *pClkCtrlReg = (uint32_t*)0x40023830;
uint32_t volatile *pClkCtrlRegApb2 = (uint32_t*)0x40023844;
uint32_t volatile *pGPIOAModeReg = (uint32_t*)0x40020000;
uint32_t volatile *pEXTTIMaskReg = (uint32_t*)0x40013C00;
uint32_t volatile *pEXTTIEdgeCtrlReg = (uint32_t*)0x40013C08;
uint32_t volatile *pNVICIRQEnReg = (uint32_t*)0xE000E100;

int main()
{
    button_init();

    while (1)
    {
        // disable interrupt
        *pEXTTIMaskReg &= ~(1 << 0);

        if(g_button_pressed)
        {
            // add delay for button debouncing
            for (uint32_t volatile i=0; i<500000/2; i++);
            g_button_press_count++;
            printf("Button is pressed : %u\n", g_button_press_count);
            g_button_pressed = 0;
        }

        // enable interrupt
        *pEXTTIMaskReg |= (1 << 0);
    }
    

}

void button_init(void)
{
    *pClkCtrlReg |= (1 << 0);
    *pClkCtrlRegApb2 |= (1 << 14);
    *pEXTTIEdgeCtrlReg |= (1 << 0);
    *pEXTTIMaskReg |= (1 << 0);
    *pNVICIRQEnReg |= (1 << 6);
}

void EXTI0_IRQHandler(void)
{
    // make this flag SET if button pressed
    g_button_pressed = 1;
    *pEXTTIPendReg |= (1 << 0);
}