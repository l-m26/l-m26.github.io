#include "menu.h" 
#include <string.h>

extern int led_time;
extern MenuItem mainmenu;
// 导航到上一个菜单项
void Menu_NavigateUp(void ) {
	if(mainmenu.set<=6 && mainmenu.up!=NULL)
	{
		mainmenu = *mainmenu.up;
	
	}
	switch (mainmenu.set) 
		{
            case 7:
                
                break;
						case 8:
                music1 = (++music1 > 3) ? 3 : music1;
                break;
						case 9:
                motor_speed = (motor_speed + 500 > 5000) ? 5000 : (motor_speed + 500);
                break;
						case 10:
                duoji = (duoji + 15 > 180) ? 180 : (duoji + 15);
                break;
						case 11:
                
                break;
						case 12:
                
                break;
						
						
						
		}
  
}

// 导航到下一个菜单项
void Menu_NavigateDown(void ) {
	
	if(mainmenu.set<=6 &&mainmenu.next!=NULL )
	{
		mainmenu = *mainmenu.next;
		
	
	}
	switch (mainmenu.set) 
		{
            case 7:
                
                break;
						case 8:
                music1 = (--music1<0 ) ? 0 : music1;
						
                break;
						case 9:
               motor_speed = (motor_speed - 500 < -5000) ? 5000 : (motor_speed - 500);
                break;
						case 10:
               duoji = (duoji - 15 < 0) ? 0 : (duoji - 15);
                break;
						case 11:
                
                break;
						case 12:
                
                break;
						
						
						
		}
	
	
   
}

// 选择当前菜单项
void Menu_Select(void) {
	if(mainmenu.set<=6 && mainmenu.children  !=NULL)
	{
	
		switch (mainmenu.set) 
		{
            case 1:
								led_time= time_100ms_cnt_1;
                break;
						case 2:
                __HAL_TIM_SET_AUTORELOAD(&htim12,100-1);
								__HAL_TIM_SET_PRESCALER(&htim12,168-1);
							
                break;
						case 3:
                
                break;
						case 4:
                __HAL_TIM_SET_AUTORELOAD(&htim12,20000- 1);
								__HAL_TIM_SET_PRESCALER(&htim12,168-1);
							
                break;
						case 5:
                LCD_Clear(BLUE);
                break;
						case 6:
                
                break;
						
						
						
		}
		mainmenu = *mainmenu.children;
	}
	
   
}

// 返回上一级菜单
void Menu_Back(void) {
	switch (mainmenu.set) 
		{
            case 7:
                LCD_Clear(BLUE );
						    HAL_GPIO_WritePin (GPIOD ,GPIO_PIN_1 ,GPIO_PIN_RESET );
						    HAL_GPIO_WritePin (GPIOD ,GPIO_PIN_2 ,GPIO_PIN_RESET );
                break;
						case 8:
							   music1 = 0;
								__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,0);
                 LCD_Clear(BLUE );
                break;
						case 9:
								Set_Pwm(0 ,0);
								motor_speed = 0;
                 LCD_Clear(BLUE );
                break;
						case 10:
									duoji = 90;
                 LCD_Clear(BLUE );
                break;
						case 11:
                 LCD_Clear(BLUE );
                break;
						case 12:
                 LCD_Clear(BLUE );
                break;
						
						
						
		}
	if(mainmenu.parent   !=NULL)
	{
	mainmenu = *mainmenu.parent;
	}
	
	
	
  
}






