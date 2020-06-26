/*
 * calorie_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/calorie_mode.h"
extern state current_state;

void calorieScreen() {
	ST7735_WriteString(0, 60, "CALORIE SCREEN", TEXT_FONT_CLR_MODE, TEXT_COLOR_CLR_MODE, TEXT_BACKGROUND_COLOR_CLR_MODE);

}
