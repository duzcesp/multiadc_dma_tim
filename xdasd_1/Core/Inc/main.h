/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define x_axis_0_Pin GPIO_PIN_0
#define x_axis_0_GPIO_Port GPIOA
#define y_axis_0_Pin GPIO_PIN_1
#define y_axis_0_GPIO_Port GPIOA
#define x_axis_1_Pin GPIO_PIN_2
#define x_axis_1_GPIO_Port GPIOA
#define y_axis_1_Pin GPIO_PIN_3
#define y_axis_1_GPIO_Port GPIOA
#define sol_b1_Pin GPIO_PIN_1
#define sol_b1_GPIO_Port GPIOB
#define sol_b10_Pin GPIO_PIN_10
#define sol_b10_GPIO_Port GPIOB
#define sag_b12_Pin GPIO_PIN_12
#define sag_b12_GPIO_Port GPIOB
#define sag_b13_Pin GPIO_PIN_13
#define sag_b13_GPIO_Port GPIOB
#define pwm_0_Pin GPIO_PIN_8
#define pwm_0_GPIO_Port GPIOA
#define pwm_1_Pin GPIO_PIN_9
#define pwm_1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
