/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "menu.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
extern int music1;
extern int duoji;
extern int motor_speed;
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR1_Pin GPIO_PIN_5
#define MOTOR1_GPIO_Port GPIOE
#define MOTOR2_Pin GPIO_PIN_6
#define MOTOR2_GPIO_Port GPIOE
#define SPI2_CS_Pin GPIO_PIN_1
#define SPI2_CS_GPIO_Port GPIOC
#define Encoder2A_Pin GPIO_PIN_0
#define Encoder2A_GPIO_Port GPIOA
#define Encoder2B_Pin GPIO_PIN_1
#define Encoder2B_GPIO_Port GPIOA
#define Encoder2AD12_Pin GPIO_PIN_12
#define Encoder2AD12_GPIO_Port GPIOD
#define Encoder2BD13_Pin GPIO_PIN_13
#define Encoder2BD13_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOD
#define LCD_LED_Pin GPIO_PIN_5
#define LCD_LED_GPIO_Port GPIOD
#define LCD_CS_Pin GPIO_PIN_6
#define LCD_CS_GPIO_Port GPIOD
#define LCD_DC_Pin GPIO_PIN_7
#define LCD_DC_GPIO_Port GPIOD
#define LCD_RS_Pin GPIO_PIN_4
#define LCD_RS_GPIO_Port GPIOB
#define KEY1_Pin GPIO_PIN_8
#define KEY1_GPIO_Port GPIOB
#define KEY2_Pin GPIO_PIN_9
#define KEY2_GPIO_Port GPIOB
#define KEY3_Pin GPIO_PIN_0
#define KEY3_GPIO_Port GPIOE
#define KEY4_Pin GPIO_PIN_1
#define KEY4_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
