/*
 * normalMode.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */


#include "normalMode.h"
#include "7SegLed.h"
#include "update7SEG.h"
#include <main.h>

int statusTraffic1 = INIT1;
int statusTraffic2= INIT2;

int durationLedRed= 0;
int durationLedGreen= 0;
int durationLedYellow= 0;

int tempDurationLedRed= 5;
int tempDurationLedGreen= 3;
int tempDurationLedYellow= 2;

int counterLedRed1;
int counterLedRed2;
int counterLedGreen1;
int counterLedGreen2;
int counterLedYellow1;
int counterLedYellow2;

void mode1Function()
{
	switch (statusTraffic1)
	{
		case INIT1:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);   // red
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			counterLedRed1= durationLedRed;
			update7SEGBuffer(counterLedRed1, 1);
			statusTraffic1= STATUS1_1;
			break;
		case STATUS1_1:
			if (counterLedRed1 > 0)
			{
				counterLedRed1--;
				if (counterLedRed1 <= 0)
				{
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);   // green
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
					statusTraffic1= STATUS1_2;
					counterLedGreen1= durationLedGreen;
					update7SEGBuffer(counterLedGreen1, 1);
				}
				else
				{
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);   // red
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
					update7SEGBuffer(counterLedRed1, 1);
				}
			}
			break;
		case STATUS1_2:
			if (counterLedGreen1 > 0)
			{
				counterLedGreen1--;
				if (counterLedGreen1 <= 0)
				{
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);  // yellow
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
					statusTraffic1= STATUS1_3;
					counterLedYellow1= durationLedYellow;
					update7SEGBuffer(counterLedYellow1, 1);
				}
				else
				{
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);   // green
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
					update7SEGBuffer(counterLedGreen1, 1);
				}
			}
			break;
		case STATUS1_3:
			if (counterLedYellow1 > 0)
			{
				counterLedYellow1--;
				if (counterLedYellow1 <= 0)
				{
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);   // green
					statusTraffic1= STATUS1_1;
					counterLedRed1= durationLedRed;
					update7SEGBuffer(counterLedRed1, 1);
				}
				else
				{
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);  // yellow
					HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
					update7SEGBuffer(counterLedYellow1, 1);
				}
			}
			break;
		default:
			break;
	}
	switch (statusTraffic2)
	{
		case INIT2:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);   // green
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			counterLedGreen2= durationLedGreen;
			update7SEGBuffer(counterLedGreen2, 2);
			statusTraffic2= STATUS2_1;
			break;
		case STATUS2_1:
			if (counterLedGreen2 > 0)
			{
				counterLedGreen2--;
				if (counterLedGreen2 <= 0)
				{
					HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);   // yellow
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
					counterLedYellow2= durationLedYellow;
					statusTraffic2= STATUS2_2;
					update7SEGBuffer(counterLedYellow2, 2);
				}
				else
				{
					HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);   // green
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
					update7SEGBuffer(counterLedGreen2, 2);
				}
			}
			break;
		case STATUS2_2:
			if (counterLedYellow2 > 0)
			{
				counterLedYellow2--;
				if (counterLedYellow2 <= 0)
				{
					HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
					HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);   // red
					counterLedRed2= durationLedRed;
					statusTraffic2= STATUS2_3;
					update7SEGBuffer(counterLedRed2, 2);
				}
				else
				{
					HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);   // yellow
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
					update7SEGBuffer(counterLedYellow2, 2);
				}
			}
			break;
		case STATUS2_3:
			if (counterLedRed2 > 0)
			{
				counterLedRed2--;
				if (counterLedRed2 <= 0)
				{
					HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
					HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);   // green
					counterLedGreen2= durationLedGreen;
					statusTraffic2= STATUS2_1;
					update7SEGBuffer(counterLedGreen2, 2);
				}
				else
				{
					HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
					HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);   //
					update7SEGBuffer(counterLedRed2, 2);
				}
			}
			break;
		default:
			break;
	}
}
