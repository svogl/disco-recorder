/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    venc.c
  * @brief   This file provides code for the configuration
  *          of the VENC instances.
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
#include "venc.h"
#include <stdio.h>

/* USER CODE BEGIN 0 */
// #include "ewl.h"
// #include "h264encapi.h"
#include "stm32n6xx_hal.h"

#include "app_config.h"


// __attribute__ ((section (".psram_bss")))
__attribute__ ((aligned (32)))
uint32_t vin_buffer[800*480*2];

/* USER CODE END 0 */

/* VENC init function */
void MX_VENC_Init(void)
{

  /* USER CODE BEGIN VENC_Init 0 */

	__HAL_RCC_VENCRAM_MEM_CLK_ENABLE(); //p570; ok
	__HAL_RCC_VENC_CLK_ENABLE();


  /* enable APB5 bus clock*/
  /* cf. errata : SHOULD ADD REFERENCE TO THE ERRATA */
  /* using CMSIS access because ll_bus does not contain APB5 enable macros*/
  WRITE_REG(RCC->BUSENSR, RCC_BUSENSR_APB5ENS);

  /* enable VENCRAM */
  LL_MEM_EnableClock(LL_MEM_VENCRAM);

  /* enable VENC clock */
  LL_APB5_GRP1_EnableClock(LL_APB5_GRP1_PERIPH_VENC);

  printf("-------- ENC INIT\r\n");

  /* USER CODE END VENC_Init 0 */

  /* USER CODE BEGIN VENC_Init 1 */

  /* USER CODE END VENC_Init 1 */
  /* USER CODE BEGIN VENC_Init 2 */

  /* USER CODE END VENC_Init 2 */

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
