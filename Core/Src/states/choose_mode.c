/*
 * choose_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/choose_mode.h"

extern state current_state;
extern state mode_state;

void chooseModeScreen() {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)) {
		// C0 connected to the right button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0))
			;
		HAL_Delay(300);
		current_state = calorie_mode;
		mode_state = calorie_mode;
		ST7735_FillScreen(BACKGROUND_COLOR_CHS_MODE);
		return;
	}
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)) {
		// C2 connected to the left button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
			;
		current_state = step_mode;
		mode_state = step_mode;
		ST7735_FillScreen(BACKGROUND_COLOR_CHS_MODE);
		return;
	}
	ST7735_WriteString(0, 50, "  Step Mode (L) ", TEXT_FONT_CHS_MODE, TEXT_COLOR_CHS_MODE, TEXT_BACKGROUND_COLOR_CHS_MODE);
	ST7735_WriteString(0, 100, " Calorie Mode (R)", TEXT_FONT_CHS_MODE, TEXT_COLOR_CHS_MODE, TEXT_BACKGROUND_COLOR_CHS_MODE);
}
