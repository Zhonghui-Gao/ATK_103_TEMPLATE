/**
 ******************************************************************************
 * @file     led.c
 * @author   Gao-Zh
 * @version  V1.0
 * @date     2024-11-8
 * @brief    HAL¿â
 * @license  Copyright (c) 
 ******************************************************************************
 */

#include "./BSP/LED/led.h"


void led_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;

    LED_RED_GPIO_CLK_ENABLE();
    LED_BLUE_GPIO_CLK_ENABLE();

    //blue
    gpio_init_struct.Pin = LED_BLUE_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_init_struct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(LED_BLUE_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = LED_RED_PIN;
	gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_init_struct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(LED_RED_PORT, &gpio_init_struct);	
	
	LED_BLUE(0);
	LED_RED(0);
	
}


