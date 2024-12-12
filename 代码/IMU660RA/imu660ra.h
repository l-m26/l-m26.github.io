#ifndef __IMU660RA_H
#define __IMU660RA_H

#include "stm32f4xx_hal.h"
#include "main.h"
// 定义外部全局变量
extern int16_t imu660ra_gyro_x, imu660ra_gyro_y, imu660ra_gyro_z;
extern int16_t imu660ra_acc_x, imu660ra_acc_y, imu660ra_acc_z;
extern float imu660ra_transition_factor[2];

// CS 引脚控制
#define IMU660RA_CS_LOW()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET)
#define IMU660RA_CS_HIGH() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET)

// 超时定义
#define IMU660RA_TIMEOUT 1000

// 寄存器地址定义
#define IMU660RA_CHIP_ID            (0x00)
#define IMU660RA_PWR_CONF           (0x7C)
#define IMU660RA_PWR_CTRL           (0x7D)
#define IMU660RA_INIT_CTRL          (0x59)
#define IMU660RA_INIT_DATA          (0x5E)
#define IMU660RA_INT_STA            (0x21)
#define IMU660RA_ACC_ADDRESS        (0x0C)
#define IMU660RA_GYRO_ADDRESS       (0x12)
#define IMU660RA_ACC_CONF           (0x40)
#define IMU660RA_ACC_RANGE          (0x41)
#define IMU660RA_GYR_CONF           (0x42)
#define IMU660RA_GYR_RANGE          (0x43)
extern float rol, pit, yaw;
// 默认配置定义
#define IMU660RA_ACC_SAMPLE_SGN_8G      (2)
#define IMU660RA_GYRO_SAMPLE_SGN_2000DPS (0)

// 函数声明
void imu660ra_write_register(uint8_t reg, uint8_t data);
void imu660ra_write_registers(uint8_t reg, const uint8_t *data, uint16_t length);
uint8_t imu660ra_read_register(uint8_t reg);
void imu660ra_read_registers(uint8_t reg, uint8_t *data, uint16_t length);

void imu660ra_get_acc(void);
void imu660ra_get_gyro(void);
uint8_t imu660ra_init(void);
void Get_Angle(void);
#endif // __IMU660RA_H
