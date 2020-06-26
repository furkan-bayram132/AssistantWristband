/*
 * choose_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/choose_mode.h"

void chooseModeScreen() {
	ST7735_WriteString(0, 50, "  Step Mode (L) ", TEXT_FONT_CHS_MODE, TEXT_COLOR_CHS_MODE, TEXT_BACKGROUND_COLOR_CHS_MODE);
	ST7735_WriteString(0, 100, " Calorie Mode (R)", TEXT_FONT_CHS_MODE, TEXT_COLOR_CHS_MODE, TEXT_BACKGROUND_COLOR_CHS_MODE);
}
