/*
 * step_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/step_mode.h"
extern state current_state;
extern uint32_t step_num;


void stepScreen(uint32_t step_no) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)) {
		// C0 connected to the right button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0))
			;
		HAL_Delay(300);
		step_num += 5; // #####
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
	else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) && step_num > 1000) {
		// C2 connected to the left button
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2))
			;
		HAL_Delay(300);
		step_num -= 5; // #####
	}

	char step_text[22] = { 0 }; // "Step Number:" : 12 byte, 32bit number : 10 byte = 22 byte
	sprintf(step_text, "Step Number: %ld", step_no);
	ST7735_WriteString(0, 40, step_text, TEXT_FONT_STP_MODE, TEXT_COLOR_STP_MODE, TEXT_BACKGROUND_COLOR_STP_MODE);
	ST7735_WriteString(0, 100, "(L) : - \\/ + : (R)", TEXT_FONT_STP_MODE, TEXT_COLOR_STP_MODE, TEXT_BACKGROUND_COLOR_STP_MODE);

}
