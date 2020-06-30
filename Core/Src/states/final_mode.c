/*
 * final_mode.c
 *
 *  Created on: 30 Haz 2020
 *      Author: hizirov
 */

#include "states/final_mode.h"

extern uint32_t eta_time;
extern uint32_t step_num;
extern uint32_t elapsed_time;
extern uint32_t current_step;
extern state current_state;
extern state mode_state;

void finalModeScreen(const CalorieInfo *person_cal_info) {
	char t1[50] = { 0 };
	ST7735_WriteString(0, 10, "==================", TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
	ST7735_WriteString(0, 40, "     CONGRATS", TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
	if (mode_state == step_mode) { // step mode
		sprintf(t1, " %ld step taken", step_num);
		ST7735_WriteString(0, 70, t1, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
		//sprintf(t1, "eta:%ld, step:%ld, elapsed:%ld, current:%ld", eta_time, step_num, elapsed_time, current_step);
		//ST7735_WriteString(0, 70, t1, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);

	}
	else { // calorie mode
		char t3[20] = { 0 };
		sprintf(t3, "%d calorie burned", person_cal_info->calorie_amount);
		ST7735_WriteString(0, 70, t3, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
	}
	char t4[20] = { 0 };
	sprintf(t4, "Elapsed Time: %ld", elapsed_time);
	ST7735_WriteString(0, 100, t4, TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
	ST7735_WriteString(0, 130, "==================", TEXT_FONT_FNL_MODE, TEXT_COLOR_FNL_MODE, BACKGROUND_COLOR_FNL_MODE);
}
