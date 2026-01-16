/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "cacheaxi.h"
#include "csi.h"
#include "dcmipp.h"
#include "dma2d.h"
#include "i2c.h"
#include "ltdc.h"
#include "sdmmc.h"
#include "stm32n6xx_hal.h"
#include "usart.h"
#include "venc.h"
#include "xspi.h"
#include "xspim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_config.h"
#include "stm32n6570_discovery.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* Check expected frequency */
  /* UART log */
#if USE_COM_LOG
  COM_InitTypeDef COM_Init;

  /* Initialize COM init structure */
  COM_Init.BaudRate   = 115200;
  COM_Init.WordLength = COM_WORDLENGTH_8B;
  COM_Init.StopBits   = COM_STOPBITS_1;
  COM_Init.Parity     = COM_PARITY_NONE;
  COM_Init.HwFlowCtl  = COM_HWCONTROL_NONE;

  BSP_COM_Init(COM1, &COM_Init);

  if (BSP_COM_SelectLogPort(COM1) != BSP_ERROR_NONE)
  {
    printf("failed to set up log port\n");
    Error_Handler();
  }
#endif

  /* USER CODE END Init */

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DCMIPP_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_VENC_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_XSPI1_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_XSPI2_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_CACHEAXI_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
 MX_SDMMC2_SD_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_UART4_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_I2C1_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_I2C2_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_LTDC_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  MX_DMA2D_Init();
    printf("%s:%d beep\r\n", __func__, __LINE__);
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    printf("%s:%d beep\r\n", __func__, __LINE__);
  unsigned fc = 0;
  while (1)
  {
    BSP_LED_Toggle(LED1);
    HAL_Delay(1000);
    printf("beep %d\r\n", fc++);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
