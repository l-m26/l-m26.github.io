/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "dac.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h" 
#include "lcd.h"
#include "gui.h"
#include <stdio.h>
#include "key.h"
#include "motor.h"
#include "bee.h"
#include "AT24C02.h"
#include <string.h>  
#include "delay.h"
#include "imu660ra.h" 
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
char str[80];
int  music1 = 0;
int duoji = 90;
int motor_speed = 0;
int led_time;
uint8_t led_flag = 0;
int ball_x = 64,ball_y = 80;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define EEPROM_WRITE_ADDR 0x00   // 向 EEPROM 写入的起始地址
#define EEPROM_READ_ADDR  0x00   // 从 EEPROM 读取的起始地址
#define EEPROM_DATA_SIZE  16     // 要读写的字节数
uint8_t writeBuffer[EEPROM_DATA_SIZE] = "A";  // 写入的数据
uint8_t readBuffer[EEPROM_DATA_SIZE];  // 用来存放读取的数据
uint16_t adc_value;
// 定义屏幕分辨率
#define SCREEN_WIDTH  128  // LCD 宽度
#define SCREEN_HEIGHT 160  // LCD 高度

// 定义球的半径
#define BALL_RADIUS 5
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
// 功能函数示例
void update_ball_position(float rol1, float pit1, int *ball_x, int *ball_y) {
    // 屏幕中心位置
    int center_x = SCREEN_WIDTH / 2;
    int center_y = SCREEN_HEIGHT / 2;

    // 将 ROL 和 PIT 转换为屏幕上的位移
    // 假设 ROL 和 PIT 范围为 [-90, 90]
    int dx = (int )(rol1 / 90.0 * (SCREEN_WIDTH / 2 - BALL_RADIUS));
    int dy = (int)(-pit1 / 90.0 * (SCREEN_HEIGHT / 2 - BALL_RADIUS));

    // 计算新的小球坐标
    *ball_x = center_x + dx;
    *ball_y = center_y + dy;

    // 边界检查，防止小球超出屏幕
    if (*ball_x < BALL_RADIUS) *ball_x = BALL_RADIUS;
    if (*ball_x > SCREEN_WIDTH - BALL_RADIUS) *ball_x = SCREEN_WIDTH - BALL_RADIUS;
    if (*ball_y < BALL_RADIUS) *ball_y = BALL_RADIUS;
    if (*ball_y > SCREEN_HEIGHT - BALL_RADIUS) *ball_y = SCREEN_HEIGHT - BALL_RADIUS;
}
void Function1(void) {
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE ,BLACK,(uint8_t *)str,16,0);
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"GYROSCOPE");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
	//HAL_GPIO_Pin (GPIOD,GPIO_PIN_1)
		
		
    // 执行功能1
}

void Function2(void) {
    // 执行功能2
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,50,WHITE ,BLACK,(uint8_t *)str,16,0);
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"GYROSCOPE");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
	
}

void Function3(void) {
    // 执行功能3
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,70,WHITE ,BLACK,(uint8_t *)str,16,0);
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"GYROSCOPE");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
}

void Function4(void) {
    // 执行功能4
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,90,WHITE ,BLACK,(uint8_t *)str,16,0);
		sprintf(str,"GYROSCOPE");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
}
void Function5(void) {
    // 执行功能4
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"GYROSCOPE");
		Gui_StrCenter(10,110,WHITE ,BLACK,(uint8_t *)str,16,0);
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
}
void Function6(void) {
    // 执行功能4
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"GYROSCOPE");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,130,WHITE ,BLACK,(uint8_t *)str,16,0);
}
void Function1_1(void) {
		//LCD_Fill(0,0,100,100,WHITE );
		sprintf(str,"   LED   ");
		Gui_StrCenter(10,30,WHITE  ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"            ");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
	if(time_100ms_cnt_1 - led_time > 2 )
		{
			if(led_flag ==0)
			{
				HAL_GPIO_TogglePin (GPIOD,GPIO_PIN_1);
				led_flag = 1;
			}
			else 
			{
				HAL_GPIO_TogglePin (GPIOD,GPIO_PIN_2);
				led_flag = 0;
			}
				led_time=time_100ms_cnt_1 ;
			
		}
    // 执行功能1
	
}

void Function2_1(void) {
    // 执行功能2
		sprintf(str," BUZZER  ");
		Gui_StrCenter(10,30,WHITE  ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"    %d        ",music1);
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"            ");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
	if( music1 == 0)
	{
		play_music(music1,0);
	}
	else 
		play_music(music1,1);
}

void Function3_1(void) {
    // 执行功能3
		sprintf(str,"  MOTOR  ");
		Gui_StrCenter(10,30,WHITE  ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"      %d     ",motor_speed );
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"            ");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
		Set_Pwm(motor_speed ,motor_speed);
}

void Function4_1(void) {
    // 执行功能4
		sprintf(str,"  SERVO  ");
		Gui_StrCenter(10,30,WHITE  ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"    %d        ",duoji );
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"            ");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
	__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,duoji/180.0*2000+500);
}
void Function5_1(void) {
    // 执行功能4 
//		sprintf(str,"GYROSCOPE");
//		Gui_StrCenter(10,30,WHITE  ,BLUE,(uint8_t *)str,16,0);
//		sprintf(str,"             ");
//		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
//		sprintf(str,"             ");
//		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
//		sprintf(str,"             ");
//		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
//		sprintf(str,"            ");
//		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
//		sprintf(str,"             ");
//		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
	LCD_Clear(BLUE );
			update_ball_position(-rol,  -pit, &ball_x, &ball_y);
	    gui_circle(ball_x,ball_y,BLACK ,5, 1);
}//rol, pit, yaw
void Get_adc(void )
{
			HAL_ADC_Start(&hadc1);
	if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK)  
        {  
            adc_value =  HAL_ADC_GetValue(&hadc1); // 获取转换后的数字值  
  
            
        }  
			
}
void Function6_1(void) {
    // 执行功能4 
		sprintf(str," ADC DAC ");
		Gui_StrCenter(10,30,WHITE  ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"   %.2f        ",(adc_value / 4096.0) * 3.3);
		Gui_StrCenter(10,50,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,70,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,90,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"            ");
		Gui_StrCenter(10,110,WHITE ,BLUE,(uint8_t *)str,16,0);
		sprintf(str,"             ");
		Gui_StrCenter(10,130,WHITE ,BLUE,(uint8_t *)str,16,0);
		Get_adc();
}
MenuItem mainmenu;
		

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

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN1_Init();
  MX_I2C3_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();
  MX_TIM9_Init();
  MX_UART4_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM1_Init();
  MX_TIM12_Init();
  MX_ADC1_Init();
  MX_DAC_Init();
  /* USER CODE BEGIN 2 */
	LCD_Init();
	motor_int();
  //main_test();
	HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_2);	//???启PWM
	HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&htim1);		  	//???启定时器???
	tone_init(); //初始化音量频???
	list_max = music_init();//更新乐谱
	EN=1;
//
 // 创建菜单项
		MenuItem submenu1 = {"Function 1", Function1, NULL, NULL, NULL, NULL,1};
    MenuItem submenu2 = {"Function 2", Function2, NULL, NULL, NULL, NULL,2};
    MenuItem submenu3 = {"Function 3", Function3, NULL, NULL, NULL, NULL,3};
    MenuItem submenu4 = {"Function 4", Function4, NULL, NULL, NULL, NULL,4};
		MenuItem submenu5 = {"Function 5", Function5, NULL, NULL, NULL, NULL,5};
		MenuItem submenu6 = {"Function 6", Function6, NULL, NULL, NULL, NULL,6};
		MenuItem submenu1_1 = {"Function 1_1", Function1_1, NULL, NULL, NULL, NULL,7};
    MenuItem submenu2_1= {"Function 2_1", Function2_1, NULL, NULL, NULL, NULL,8};
    MenuItem submenu3_1 = {"Function 3_1", Function3_1, NULL, NULL, NULL, NULL,9};
    MenuItem submenu4_1= {"Function 4_1", Function4_1, NULL, NULL, NULL, NULL,10};
		MenuItem submenu5_1 = {"Function 5_1", Function5_1, NULL, NULL, NULL, NULL,11};
		MenuItem submenu6_1 = {"Function 6_1", Function6_1, NULL, NULL, NULL, NULL,12};
		 
    // 连接菜单项为链表
    submenu1.next = &submenu2;
    submenu2.next = &submenu3;
    submenu3.next = &submenu4;
    submenu4.next = &submenu5;
		submenu5.next = &submenu6;
		submenu6.next = &submenu1;
		
		submenu1.up = &submenu1;
		submenu2.up = &submenu1;
		submenu3.up = &submenu2;
		submenu4.up = &submenu3;
		submenu5.up = &submenu4;
		submenu6.up = &submenu5;
		
		submenu1.parent = &submenu1;
    submenu2.parent = &submenu1;
    submenu3.parent = &submenu1;
    submenu4.parent = &submenu1;
		submenu5.parent = &submenu1;
		submenu6.parent = &submenu1;
		
		submenu1.children = &submenu1_1;
		submenu2.children = &submenu2_1;
		submenu3.children = &submenu3_1;
		submenu4.children = &submenu4_1;
		submenu5.children = &submenu5_1;
		submenu6.children = &submenu6_1;
		
		submenu1_1.parent = &submenu1;
    submenu2_1.parent = &submenu2;
    submenu3_1.parent = &submenu3;
    submenu4_1.parent = &submenu4;
		submenu5_1.parent = &submenu5;
		submenu6_1.parent = &submenu6;
		
		 
		mainmenu = submenu1;
		

	LCD_Clear(BLUE );
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//	   if (memcmp(writeBuffer, readBuffer, EEPROM_DATA_SIZE) == 0)
//    {
//        // 数据一致，表示写入和读取成功
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);  // 通过 GPIO 引脚指示成功（例如点亮 LED）
//			printf("cg");
//    }
//   else
//    {
//        // 数据不一致，表示失败
//        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);  // 通过另一个 GPIO 引脚指示失败（例如点亮另一盏 LED）
//    }
//	
		Set_Pwm(motor_speed ,motor_speed);
		__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,0);
		__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,0);
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 2048);  //设置发生的电压
		HAL_DAC_Start(&hdac,DAC_CHANNEL_1);  //开启DAC1
		HAL_ADC_Start(&hadc1);
		delay_init(168);
		imu660ra_init();

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		Get_Angle();
		mainmenu.function();
		key_1 ();
		key_2 ();
		key_3 ();
		key_4 ();
	
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
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

#ifdef  USE_FULL_ASSERT
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
