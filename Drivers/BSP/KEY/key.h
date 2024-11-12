/**
 ******************************************************************************
 * @file     key.h
 * @author   Gao-Zh
 * @version  V1.0
 * @date     2024-11-8
 * @brief    HAL库
 * @license  Copyright (c) 
 ******************************************************************************
 */ 
 
#ifndef __KEY_H
#define __KEY_H

#include "./SYSTEM/sys/sys.h"

/****************************************************************/
/* KEY PORT & PIN*/
#define KEY1_GPIO_PORT 						GPIOA
/*KEY1_WKUP, 闲时下拉，按下时被置高电平*/
#define KEY1_GPIO_PIN						GPIO_PIN_0
#define KEY1_GPIO_CLK_ENABLE()				do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define KEY2_GPIO_PORT 						GPIOA
/*KEY2, 闲时上拉，按下时被置低电平*/
#define KEY2_GPIO_PIN						GPIO_PIN_1
#define KEY2_GPIO_CLK_ENABLE()				do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define KEY3_GPIO_PORT 						GPIOA
/*KEY3, 闲时上拉，按下时被置低电平*/
#define KEY3_GPIO_PIN						GPIO_PIN_4	
#define KEY3_GPIO_CLK_ENABLE()				do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

/****************************************************************/

/****************************************************************/
/* KEY STATE */
#define KEY1								HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)
#define KEY2								HAL_GPIO_ReadPin(KEY2_GPIO_PORT, KEY2_GPIO_PIN)
#define KEY3								HAL_GPIO_ReadPin(KEY3_GPIO_PORT, KEY3_GPIO_PIN)

/* PRES VALUE*/
#define KEY1_PRES	1
#define KEY2_PRES	2
#define KEY3_PRES	3
/****************************************************************/

void Key_Init(void);
uint8_t Key_Scan(uint8_t mode);

#endif

