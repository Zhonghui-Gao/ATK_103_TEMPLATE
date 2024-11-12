/**
 ******************************************************************************
 * @file     main.c
 * @author   Gao-Zh
 * @version  V1.0
 * @date     2024-11-8
 * @brief    HAL��
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
    HAL_Init();                                 /* ��ʼ��HAL�� */
    sys_stm32_clock_init(RCC_PLL_MUL9);         /* ����ʱ��,72M */
    delay_init(72);                             /* ��ʼ����ʱ���� */
    led_init();                                 /* ��ʼ��LED */
	Key_Init();
    while(1)
    {
		if(KEY2 == 0){
			while(KEY2 == 0);
			LED_BLUE_TOGGLE();
		}
    }
}

