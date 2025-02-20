/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "gpio.h"

#if 0
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE3 PE4 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}
#endif

#if 0
void GPIO_Init(void)
{
	/* GPIO Ports Clock Enable on APB2 bus */
    RCC->APB2ENR |= (1 << 6);    // GPIOE clock enable
    RCC->APB2ENR |= (1 << 2);    // GPIOA clock enable
    
    /* Configure GPIO pins PE2, PE3, PE4 as output */
    // Reset the pins to ensure clean configuration
    GPIOE->CRL &= ~(0xFFF << 8); // Clear bits for PE2, PE3, PE4 (4 bits per pin)
    
    // Configure PE2 (CNF=0b00: Push-pull output, MODE=0b11: Output mode, max speed 50MHz)
    GPIOE->CRL |= (0x03 << 8);   // MODE2[1:0] = 11
    
    // Configure PE3
    GPIOE->CRL |= (0x03 << 12);  // MODE3[1:0] = 11
    
    // Configure PE4
    GPIOE->CRL |= (0x03 << 16);  // MODE4[1:0] = 11
    
    /* Set initial pin states to LOW */
    GPIOE->ODR &= ~((1 << 2) | (1 << 3) | (1 << 4));
}
#endif

#if 1
void GPIO_Memory_Init(void)
{
	(*(volatile unsigned *)0x40021018) |= 0x01 << 6;
	(*(volatile unsigned *)0x40021018) |= 0x01 << 2;

	(*(volatile unsigned *)0x40011800) &= ~(0xf << 8);
	(*(volatile unsigned *)0x40011800) &= ~(0xf << 12);
	(*(volatile unsigned *)0x40011800) &= ~(0xf << 16);

	(*(volatile unsigned *)0x40011800) |= (0x3 << 8);   
	(*(volatile unsigned *)0x40011800) |= (0x3 << 12);  
	(*(volatile unsigned *)0x40011800) |= (0x3 << 16);  

	(*(volatile unsigned *)0x40011810) = (0x1 << 2); 
	(*(volatile unsigned *)0x40011810) = (0x1 << 4); 
	(*(volatile unsigned *)0x40011810) = (0x1 << 3); 
}
#endif
/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
