#include "motor.h"
#include "stdio.h" 
int time_100ms_cnt = 0; //0.1s计数???
int Beat_speed = 5;		//节拍速度，代表半个节拍需要多少个0.1s
int Beat_speed_n = 0;	//实际执行的节???
int Beat_num = 2;		//这个??? ???要多少就 半拍
int flag = 0; 			//当其等于 1 时，表示???个音结束
int EN = 0;				//使能信号，用于开启整个音???
int list = 0;			//音乐列表
int list_max = 0;		//音乐总数
int Low_volume = 5;		//音量大小
int adcread_L,adcread_R;
int adc_L,adc_R;
int time_100ms_cnt_1 = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*htim)
{
	if(htim->Instance==TIM1)
	{
		adcread();
		printf("%d,%d\n",adc_L, adc_R);
		time_100ms_cnt_1++;
	if(EN == 1)
		time_100ms_cnt++;
	else
		time_100ms_cnt = time_100ms_cnt;	//其余状???不计数
 
	if(time_100ms_cnt >= Beat_speed_n * Beat_num){	//这个音节结束
		time_100ms_cnt = 0;
		flag = 1;	//发???音节结束信???
	}
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}






void adcread(void)
{
 if(__HAL_TIM_GET_COUNTER(&htim2)>30000 )
 {
   adcread_R=(__HAL_TIM_GET_COUNTER(&htim2)-65535);
 }
 else if (__HAL_TIM_GET_COUNTER(&htim2)<30000 )
 {
   adcread_R=__HAL_TIM_GET_COUNTER(&htim2); 
 }
	TIM2 -> CNT=0;
 if(__HAL_TIM_GET_COUNTER(&htim4)>30000 )
 {
   adcread_L=(65535-__HAL_TIM_GET_COUNTER(&htim4));
 }
 else if (__HAL_TIM_GET_COUNTER(&htim4)<30000 )
 {
   adcread_L=-__HAL_TIM_GET_COUNTER(&htim4); 
 }
	TIM4 -> CNT=0; 
 adc_L=(int)adcread_L;
 adc_R=(int)adcread_R;
}
int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}
void Set_Pwm(int moto1,int moto2)
{
			if(moto1<0)		
			{
				AIN2(0);			
				AIN1(1);
			}
	
			else 	
			{				
				AIN2(	1);		
				AIN1(0);
				
			}
			PWMA=myabs(moto1);
		  if(moto2<0)	
			{
				BIN1(1);
				BIN2(0);
				
			}
			else        
				{
				BIN1(0);
				BIN2(1);
				}
			PWMB=myabs(moto2);	
}

void motor_int(void)
{

 	
	HAL_TIM_PWM_Start_IT(&htim9,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start_IT(&htim9,TIM_CHANNEL_2);	

	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_2);

}







