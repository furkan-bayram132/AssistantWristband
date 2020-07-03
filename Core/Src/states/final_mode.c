/*
 * final_mode.c
 *
 *  Created on: 30 Haz 2020
 *      Author: hizirov
 */

#include "states/final_mode.h"
#include "states/main_mode.h"

extern uint32_t step_num;
extern uint32_t elapsed_time;
extern uint32_t current_step;
extern state current_state;
extern state mode_state;
extern TIM_HandleTypeDef htim2;

void finalModeScreen(const CalorieInfo *person_cal_info) {
	while (1) {
		char t1[50] = { 0 };
		ST7735_WriteString(0, 10, "==================", TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		ST7735_WriteString(0, 40, "     CONGRATS", TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		if (mode_state == step_mode) { // step mode
			sprintf(t1, " %ld step taken", step_num);
			ST7735_WriteString(0, 70, t1, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		}
		else { // calorie mode
			char t3[20] = { 0 };
			sprintf(t3, "%d calorie burned", person_cal_info->calorie_amount);
			ST7735_WriteString(0, 70, t3, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		}
		char t4[20] = { 0 };
		uint32_t hour = 0, min = 0, sec = elapsed_time;
		convertSecToTimeStamp(elapsed_time, &hour, &min, &sec);
		sprintf(t4, " Elapsed : %ld:%ld:%ld", hour, min, sec);
		ST7735_WriteString(0, 100, t4, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		ST7735_WriteString(0, 130, "==================", TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		htim2.Instance->CCR1 = 125;
		if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)) {
			current_state = choose_mode;
			current_step = 1;
			step_num = 1000;
			elapsed_time = 1;
			htim2.Instance->CCR1 = 0;
			ST7735_FillScreen(BACKGROUND_COLOR_FNL_MODE);
			break;
		}
	}
}

