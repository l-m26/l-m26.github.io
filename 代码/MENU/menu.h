#ifndef __MENU_H
#define __MENU_H




#include <stdint.h>
#include "main.h" 
#include "lcd.h"
#include "tim.h"
#include "motor.h"
// 定义菜单项的函数类型
typedef void (*MenuFunction)(void);

// 菜单项结构体
typedef struct MenuItem {
    const char* name;               // 菜单项名称
    MenuFunction function;          // 菜单项对应的功能函数
    struct MenuItem* parent;        // 指向父菜单的指针
    struct MenuItem* next;          // 指向下一个菜单项的指针
		struct MenuItem* up;
    struct MenuItem* children;      // 指向子菜单的指针（如果有）
		uint8_t set;
} MenuItem;



// 导航菜单
void Menu_NavigateUp(void );
void Menu_NavigateDown(void );
void Menu_Select(void );
void Menu_Back(void );




























#endif



