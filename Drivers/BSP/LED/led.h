/**
 ******************************************************************************
 * @file     led.h
 * @author   Gao-Zh
 * @version  V1.0
 * @date     2024-11-8
 * @brief    HAL¿â
 * @license  Copyright (c) 
 ******************************************************************************
 */
 
#ifndef __LED_H
#define __LED_H

#include "./SYSTEM/sys/sys.h"

/****************************************************************/
/* LED PORT & PIN*/
#define LED_RED_PORT 										GPIOC
#define LED_RED_PIN											GPIO_PIN_5
#define LED_RED_GPIO_CLK_ENABLE()				do{ __HAL_RCC_GPIOC_CLK_ENABLE();}while(0)

#define LED_BLUE_PORT 										GPIOB
#define LED_BLUE_PIN										GPIO_PIN_2
#define LED_BLUE_GPIO_CLK_ENABLE()				do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)

/****************************************************************/

/****************************************************************/
/* LED */
#define LED_RED(x)			do{ x ? \
								HAL_GPIO_WritePin(LED_RED_PORT, LED_RED_PIN, GPIO_PIN_SET) :  \
								HAL_GPIO_WritePin(LED_RED_PORT, LED_RED_PIN, GPIO_PIN_RESET); \
							  }while(0)

#define LED_BLUE(x)			do{ x ? \
								HAL_GPIO_WritePin(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_PIN_SET) :  \
								HAL_GPIO_WritePin(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_PIN_RESET); \
							  }while(0)

#define LED_RED_TOGGLE()      	do{ HAL_GPIO_TogglePin(LED_RED_PORT,  LED_RED_PIN);  }while(0)
#define LED_BLUE_TOGGLE()		do{ HAL_GPIO_TogglePin(LED_BLUE_PORT, LED_BLUE_PIN); }while(0)											
																
/****************************************************************/

void led_init(void);

#endif

