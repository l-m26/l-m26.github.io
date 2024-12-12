#include "key.h"

uint8_t key_flag[4] = {0,0,0,0};
uint8_t moshi[4] = {0,0,0,0};

void key_1(void)
{

	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8) == 1 && key_flag[0] ==0)
	{
	
			key_flag[0] = 1;
	
	}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8) == 0 && key_flag[0] ==1)//上
	{
				key_flag[0] = 0;
		    moshi[0]++; 
				Menu_NavigateUp();
	}
	


}

void key_2(void)
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_9) == 1 && key_flag[1] ==0)
	{
	
			key_flag[1] = 1;
	
	}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_9) == 0 && key_flag[1] ==1)//下
	{
				key_flag[1] = 0;
		    moshi[1]++; 
		Menu_NavigateDown();
				
	}
	


}

void key_3(void)
{
	
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0) == 1 && key_flag[2] ==0)
	{
	
			key_flag[2] = 1;
	
	}
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0) == 0 && key_flag[2] ==1)//确定
	{
				key_flag[2] = 0;
		    moshi[2]++; 
			Menu_Select();
	}

	


}


void key_4(void)
{

	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_1) == 1 && key_flag[3] ==0)
	{
	
			key_flag[3] = 1;
	
	}
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_1) == 0 && key_flag[3] ==1)//返回
	{
				key_flag[3] = 0;
		    moshi[3]++; 
			Menu_Back();
	}
	


}


