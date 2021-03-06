/*
 * welcome_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/welcome_mode.h"
extern state current_state;
/*
 * Fills opening screen in a fancy way:)
 * current_state : its value is changed here so that the next state can be executed.
 * */
void welcomeScreen() {
	char text1[] = " Wrist Band ";
	char text2[] = "  Welcome ";
	ST7735_FillScreen(BACKGROUND_COLOR_WLC_MODE);

	for (int i = 0; i < strlen(text1); ++i) {
		text1[i] = '\0';
		ST7735_WriteString(0, 50, text1, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
		HAL_Delay(15);
		strcpy(text1, " Wrist Band ");
	}

	HAL_Delay(100);

	for (int i = 0; i < strlen(text2); ++i) {
		text2[i] = '\0';
		ST7735_WriteString(0, 80, text2, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
		HAL_Delay(15);
		strcpy(text2, "  Welcome ");
	}

	HAL_Delay(1000);

	ST7735_FillScreen(BACKGROUND_COLOR_WLC_MODE);
	ST7735_WriteString(0, 60, text1, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
	ST7735_WriteString(0, 80, text2, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
	HAL_Delay(100);

	ST7735_FillScreen(BACKGROUND_COLOR_WLC_MODE);
	ST7735_WriteString(0, 60, text1, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
	ST7735_WriteString(0, 80, text2, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
	HAL_Delay(100);

	ST7735_FillScreen(BACKGROUND_COLOR_WLC_MODE);
	ST7735_WriteString(0, 60, text1, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
	ST7735_WriteString(0, 80, text2, TEXT_FONT_WLC_MODE, TEXT_COLOR_WLC_MODE, TEXT_BACKGROUND_COLOR_WLC_MODE);
	HAL_Delay(100);

	current_state = choose_mode;
	HAL_Delay(500);
	ST7735_FillScreen(BACKGROUND_COLOR_WLC_MODE);

}
