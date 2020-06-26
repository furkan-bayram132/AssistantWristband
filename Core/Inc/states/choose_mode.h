/*
 * choose_mode.h
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#ifndef INC_STATES_CHOOSE_MODE_H_
#define INC_STATES_CHOOSE_MODE_H_

#include "custom_peripherals/st7735.h"
#include "main.h"

#include <string.h>

#define TEXT_FONT_CHS_MODE Font_7x10
#define TEXT_COLOR_CHS_MODE ST7735_BLUE
#define BACKGROUND_COLOR_CHS_MODE ST7735_BLACK
#define TEXT_BACKGROUND_COLOR_CHS_MODE ST7735_BLACK // defines the background of letters of the text

extern state current_state;

void chooseModeScreen();

#endif /* INC_STATES_CHOOSE_MODE_H_ */
