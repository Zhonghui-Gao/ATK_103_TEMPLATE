/**
 ******************************************************************************
 * @file     main.c
 * @author   Gao-Zh
 * @version  V1.0
 * @date     2024-11-8
 * @brief    HAL库
 * @license  Copyright (c) 
 ******************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/usart/usart.h"
#include "./BSP/LED/led.h"
#include "./BSP/KEY/key.h"

int main(void)
{
    HAL_Init();                                 /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9);         /* 设置时钟,72M */
    delay_init(72);                             /* 初始化延时函数 */
    led_init();                                 /* 初始化LED */
	Key_Init();
    while(1)
    {
		if(KEY2 == 0){
			while(KEY2 == 0);
			LED_BLUE_TOGGLE();
		}
    }
}

