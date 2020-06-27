/*
 * calorie_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/calorie_mode.h"

extern state current_state;



void calorieScreen(CalorieState* calorie_mode, CalorieInfo* person_cal_info) {
	switch (*calorie_mode) {
		case calorie_height_mode:
			calorieHeightMode(calorie_mode, person_cal_info);
			break;
		case calorie_weight_mode:
			calorieWeightMode(calorie_mode, person_cal_info);
			break;
		case calorie_amount_mode:
			calorieAmountMode(calorie_mode, person_cal_info);
			break;
	}
}


void initCalorieMode(CalorieInfo* person_cal_info) {
	person_cal_info->height = 160;
	person_cal_info->weight = 60;
	person_cal_info->calorie_amount = 1000;
}


void calorieHeightMode(CalorieState* calorie_mode, CalorieInfo* person_cal_info) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) && (person_cal_info->height < 250)) {
		// C0 connected to the right button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0))
			;
		HAL_Delay(300);
		person_cal_info->height += 1;
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)) {
		// C1 connected to the middle button
			while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
				;
			HAL_Delay(300);
			*calorie_mode = calorie_weight_mode;
			return; // so that the WriteString functions below are not both, executed and displayed on the screen.
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) && (person_cal_info->height > 100)) {
		// C2 connected to the left button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
			;
		HAL_Delay(300);
		person_cal_info->height -= 1;
	}

	ST7735_WriteString(0, 20, "(L) : - \\/ + : (R)", TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text1[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text1, "   Height: %d   ", person_cal_info->height);
	ST7735_WriteString(0, 50, calorie_text1, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, TEXT_BACKGROUND_COLOR_CLR_MODE);

	char calorie_text2[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text2, "    Weight: %d     ", person_cal_info->weight);
	ST7735_WriteString(0, 80, calorie_text2, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text3[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text3, "  Calorie: %d   ", person_cal_info->calorie_amount);
	ST7735_WriteString(0, 110, calorie_text3, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

}


void calorieWeightMode(CalorieState* calorie_mode, CalorieInfo* person_cal_info) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) && (person_cal_info->weight < 200)) {
		// C0 connected to the right button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0))
			;
		HAL_Delay(300);
		person_cal_info->weight += 1;
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)) {
		// C1 connected to the middle button
			while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
				;
			HAL_Delay(300);
			*calorie_mode = calorie_amount_mode;
			return; // so that the WriteString functions below are not both, executed and displayed on the screen.
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) && (person_cal_info->weight > 30)) {
		// C2 connected to the left button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
			;
		HAL_Delay(300);
		person_cal_info->weight -= 1;
	}

	ST7735_WriteString(0, 20, "(L) : - \\/ + : (R)", TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text1[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text1, "   Height: %d   ", person_cal_info->height);
	ST7735_WriteString(0, 50, calorie_text1, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text2[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text2, "    Weight: %d     ", person_cal_info->weight);
	ST7735_WriteString(0, 80, calorie_text2, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, TEXT_BACKGROUND_COLOR_CLR_MODE);

	char calorie_text3[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text3, "  Calorie: %d   ", person_cal_info->calorie_amount);
	ST7735_WriteString(0, 110, calorie_text3, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

}


void calorieAmountMode(CalorieState* calorie_mode, CalorieInfo* person_cal_info) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)) {
		// C0 connected to the right button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0))
			;
		HAL_Delay(300);
		person_cal_info->calorie_amount += 1000;
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)) {
		// C1 connected to the middle button
			while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
				;
			HAL_Delay(300);
			current_state = main_mode;
			ST7735_FillScreen(BACKGROUND_COLOR_STP_MODE);
			return; // so that the WriteString functions below are not both, executed and displayed on the screen.
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) && (person_cal_info->calorie_amount > 1000)) {
		// C2 connected to the left button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
			;
		HAL_Delay(300);
		person_cal_info->calorie_amount -= 1000;
	}

	ST7735_WriteString(0, 20, "(L) : - \\/ + : (R)", TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text1[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text1, "   Height: %d   ", person_cal_info->height);
	ST7735_WriteString(0, 50, calorie_text1, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text2[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text2, "    Weight: %d     ", person_cal_info->weight);
	ST7735_WriteString(0, 80, calorie_text2, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, BACKGROUND_COLOR_CLR_MODE);

	char calorie_text3[25] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(calorie_text3, "  Calorie: %d   ", person_cal_info->calorie_amount);
	ST7735_WriteString(0, 110, calorie_text3, TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, TEXT_BACKGROUND_COLOR_CLR_MODE);

}


