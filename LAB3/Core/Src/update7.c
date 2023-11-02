///*
// * update7.c
// *
// *  Created on: Oct 31, 2023
// *      Author: TVB09
// */
//
//
//
//#include "update7SEG.h"
//#include "7SegLed.h"
//#include <main.h>
//
//#define INIT  0
//#define SEG7_1ON 1
//#define SEG7_2ON 2
//#define SEG7_3ON 3
//#define SEG7_4ON 4
//#define SEG7_5ON 5
//
//int status7SEG= INIT;
//int led_buffer[5]= {1, 2, 3, 4, 5};
//
//void update7SEGBuffer(int time, int index_traffic)
//{
//	switch (index_traffic)
//	{
//		case 1:
//			led_buffer[0]= time/10;
//			led_buffer[1]= time%10;
//			break;
//		case 2:
//			led_buffer[2]= time/10;
//			led_buffer[3]= time %10;
//			break;
//		case 3:
//			led_buffer[4]= time;
//			break;
//		default:
//			break;
//	}
//}
//
//void update7SEG()
//{
//	switch (status7SEG)
//	{
//		case INIT:
//			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 1);
//			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 0);
//			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 0);
//			HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 0);
//			HAL_GPIO_WritePin(en4_GPIO_Port, en4_Pin, 0);
//			display(led_buffer[0]);
//			status7SEG= SEG7_1ON;
//			break;
//		case SEG7_1ON:
//			HAL_GPIO_TogglePin(en0_GPIO_Port, en0_Pin);
//			HAL_GPIO_TogglePin(en1_GPIO_Port, en1_Pin);
//			display(led_buffer[1]);
//			status7SEG= SEG7_2ON;
//			break;
//		case SEG7_2ON:
//			HAL_GPIO_TogglePin(en1_GPIO_Port, en1_Pin);
//			HAL_GPIO_TogglePin(en2_GPIO_Port, en2_Pin);
//			status7SEG= SEG7_3ON;
//			display(led_buffer[2]);
//			break;
//		case SEG7_3ON:
//			HAL_GPIO_TogglePin(en2_GPIO_Port, en2_Pin);
//			HAL_GPIO_TogglePin(en3_GPIO_Port, en3_Pin);
//			status7SEG= SEG7_4ON;
//			display(led_buffer[3]);
//			break;
//		case SEG7_4ON:
//			HAL_GPIO_TogglePin(en3_GPIO_Port, en3_Pin);
//			HAL_GPIO_TogglePin(en4_GPIO_Port, en4_Pin);
//			status7SEG= SEG7_5ON;
//			display(led_buffer[4]);
//			break;
//		case SEG7_5ON:
//			HAL_GPIO_TogglePin(en4_GPIO_Port, en4_Pin);
//			HAL_GPIO_TogglePin(en0_GPIO_Port, en0_Pin);
//			status7SEG= SEG7_1ON;
//			display(led_buffer[0]);
//			break;
//		default:
//			break;
//	}
//
//}
