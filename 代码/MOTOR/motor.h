#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"
#include "tim.h"
extern int time_100ms_cnt; //0.1s计数???
extern int Beat_speed ;		//节拍速度，代表半个节拍需要多少个0.1s
extern int Beat_speed_n ;	//实际执行的节???
extern int Beat_num ;		//这个??? ???要多少就 半拍
extern int flag ; 			//当其等于 1 时，表示???个音结束
extern int EN ;				//使能信号，用于开启整个音???
extern int list ;			//音乐列表
extern int list_max;		//音乐总数
extern int Low_volume ;	//音量大小
extern int time_100ms_cnt_1;


void motor_int(void);
void adcread(void);
void Set_Pwm(int moto1,int moto2);
#define Low_volume_cnt  3	//音量大小???10增加

#define PWMA   TIM9->CCR1  
#define AIN2(x)  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,x)//PCout(0)
#define AIN1(x)   HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,x)//PEout(4)
#define BIN1(x)   HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,x) //PEout(3)
#define BIN2(x)   HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,x)//PEout(2)
#define PWMB   TIM9->CCR2  






























#endif

