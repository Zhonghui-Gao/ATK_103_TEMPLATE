/**
 ******************************************************************************
 * @file     key.c
 * @author   Gao-Zh
 * @version  V1.0
 * @date     2024-11-8
 * @brief    HAL¿â
 * @license  Copyright (c)
 ******************************************************************************
 */

#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

void Key_Init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    KEY1_GPIO_CLK_ENABLE();
	KEY2_GPIO_CLK_ENABLE();
	KEY3_GPIO_CLK_ENABLE();

    gpio_init_struct.Pin = KEY1_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(KEY1_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = KEY2_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pin = GPIO_PULLUP;
    HAL_GPIO_Init(KEY2_GPIO_PORT, &gpio_init_struct);
	
	gpio_init_struct.Pin = KEY3_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pin = GPIO_PULLUP;
    HAL_GPIO_Init(KEY3_GPIO_PORT, &gpio_init_struct);

}

uint8_t Key_Scan(uint8_t mode)
{
    static uint8_t key_up = 1; /* key up flag*/
    uint8_t keyval = 0;

    if (mode) key_up = 1;   /* pres */

    if (key_up && (KEY1 == 1 || KEY2 == 0 || KEY3 == 0)) 
	{
		delay_ms(10); 
		key_up = 0;
		
		if(KEY1 == 1)  keyval = KEY1_PRES;
		
		if(KEY2 == 0)  keyval = KEY2_PRES;
		
		if(KEY3 == 0)  keyval = KEY3_PRES;
		
    }else if( KEY1 == 0 && KEY2 == 1 && KEY3 == 1){
		key_up = 1;
	}
    return keyval;
}
