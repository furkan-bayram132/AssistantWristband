/*
 * calorie_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/calorie_mode.h"

extern state current_state;

// limit values for those whose height is lower lower than 5'5''
uint8_t limit_vals_5_5[10][2] = {{45,23}, {55,28}, {64,32}, {73,36}, {82,41},
							 {91,45}, {100,50}, {114,57}, {125,63}, {136,68}};

// limit values for those whose height is higher than 5'6'' and lower than 5'11''
uint8_t limit_vals_5_6_5_11[10][2] = {{45,25}, {55,30}, {64,35}, {73,40}, {82,45},
							 {91,50}, {100,55}, {114,62}, {125,68}, {136,75}};

// limit values for those whose height is higher than 6'
uint8_t limit_vals_6[10][2] = {{45,28}, {55,33}, {64,38}, {73,44}, {82,49},
							 {91,55}, {100,60}, {114,69}, {125,75}, {136,82}};



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
		case calorie_step_mode:
			calorieStepMode(person_cal_info);
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
			*calorie_mode = calorie_step_mode;
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


void calorieStepMode(CalorieInfo* person_cal_info) {
	if (person_cal_info->height <= 165) {
		// https://www.verywellfit.com/pedometer-steps-to-calories-converter-3882595
		//Ainsworth BE, Haskell WL, Herrmann SD, et al. 2011 Compendium of Physical Activities:
		//a second update of codes and MET values. Med Sci Sports Exerc.
		//2011;43(8):1575-81. doi:10.1249/mss.0b013e31821ece12
		// simplified version of the article above(for three different height ranges, the amount of
		// calorie burned calculated only based on 1000 steps).
		//limit_vals[x][0] : weight, limit_vals[x][1] : amount of calories / 1000 steps
		calculateStepNum(person_cal_info, limit_vals_5_5);
	}
	else if ((person_cal_info->height > 165) && (person_cal_info->height < 180)) {
		calculateStepNum(person_cal_info, limit_vals_5_6_5_11);
	}
	else { // person_cal_info->height >= 180
		calculateStepNum(person_cal_info, limit_vals_6);
	}
	current_state = main_mode;
	ST7735_FillScreen(BACKGROUND_COLOR_STP_MODE);
}


void calculateStepNum(CalorieInfo* person_cal_info, uint8_t limit_vals[10][2]) {
	if (person_cal_info->weight <= 45) {
		person_cal_info->step_num = person_cal_info->calorie_amount / 23;
	}
	else if (person_cal_info->weight <= limit_vals[0][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[0][1];
	}
	else if (person_cal_info->weight <= limit_vals[1][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[1][1];
	}
	else if (person_cal_info->weight <= limit_vals[2][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[2][1];
	}
	else if (person_cal_info->weight <= limit_vals[3][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[3][1];
	}
	else if (person_cal_info->weight <= limit_vals[4][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[4][1];
	}
	else if (person_cal_info->weight <= limit_vals[5][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[5][1];
	}
	else if (person_cal_info->weight <= limit_vals[6][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[6][1];
	}
	else if (person_cal_info->weight <= limit_vals[7][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[7][1];
	}
	else if (person_cal_info->weight <= limit_vals[8][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[8][1];
	}
	else if (person_cal_info->weight <= limit_vals[9][0]) {
		person_cal_info->step_num = person_cal_info->calorie_amount / limit_vals[9][1];
	}
}

