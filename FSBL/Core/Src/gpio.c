/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOP_CLK_ENABLE();
  __HAL_RCC_GPIOO_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPION_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pins : LCD_B4_Pin LCD_B5_Pin LCD_R4_Pin */
  GPIO_InitStruct.Pin = LCD_B4_Pin|LCD_B5_Pin|LCD_R4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF14_LCD;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_R2_Pin LCD_R7_Pin LCD_R1_Pin */
  GPIO_InitStruct.Pin = LCD_R2_Pin|LCD_R7_Pin|LCD_R1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF14_LCD;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_HSYNC_Pin LCD_B2_Pin LCD_G4_Pin LCD_G6_Pin
                           LCD_G5_Pin LCD_R3_Pin */
  GPIO_InitStruct.Pin = LCD_HSYNC_Pin|LCD_B2_Pin|LCD_G4_Pin|LCD_G6_Pin
                          |LCD_G5_Pin|LCD_R3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF14_LCD;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : LCD_VSYNC_Pin */
  GPIO_InitStruct.Pin = LCD_VSYNC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF14_LCD;
  HAL_GPIO_Init(LCD_VSYNC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : User_Pin */
  GPIO_InitStruct.Pin = User_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(User_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_B3_Pin LCD_B0_Pin LCD_G1_Pin LCD_R0_Pin
                           LCD_G0_Pin LCd_G7_Pin LCD_DE_Pin LCD_R6_Pin */
  GPIO_InitStruct.Pin = LCD_B3_Pin|LCD_B0_Pin|LCD_G1_Pin|LCD_R0_Pin
                          |LCD_G0_Pin|LCd_G7_Pin|LCD_DE_Pin|LCD_R6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF14_LCD;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_G2_Pin LCD_R5_Pin LCD_B1_Pin LCD_B7_Pin
                           LCD_B6_Pin LCD_G3_Pin */
  GPIO_InitStruct.Pin = LCD_G2_Pin|LCD_R5_Pin|LCD_B1_Pin|LCD_B7_Pin
                          |LCD_B6_Pin|LCD_G3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF14_LCD;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure the EXTI line attribute */
  HAL_EXTI_ConfigLineAttributes(EXTI_LINE_13, EXTI_LINE_SEC);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
