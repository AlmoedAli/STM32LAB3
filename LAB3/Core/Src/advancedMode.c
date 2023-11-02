/*
 * advancedMode.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */


#include "advancedMode.h"
#include "main.h"

void resetAllSingleLed()
{
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);

}

void advancedModeFunction(int mode)
{
	switch (mode)
	{
		case 2:
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
			break;
		case 3:
			HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
			HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
			break;
		case 4:
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
			break;
		default:
			break;
	}
}
