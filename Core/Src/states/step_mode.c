/*
 * step_mode.c
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#include "states/step_mode.h"
extern state current_state;

void stepScreen() {
	ST7735_WriteString(0, 60, "STEP SCREEN", TEXT_FONT_STP_MODE, TEXT_COLOR_STP_MODE, TEXT_BACKGROUND_COLOR_STP_MODE);
}
