/*
 * final_mode.h
 *
 *  Created on: 30 Haz 2020
 *      Author: hizirov
 */

#ifndef INC_STATES_FINAL_MODE_H_
#define INC_STATES_FINAL_MODE_H_

#include "custom_peripherals/st7735.h"
#include "main.h"
#include "states/calorie_mode.h"

#define TEXT_FONT_FNL_MODE Font_7x10
#define TEXT_COLOR_FNL_MODE ST7735_BLUE
#define BACKGROUND_COLOR_FNL_MODE ST7735_BLACK
#define TEXT_BACKGROUND_COLOR_FNL_MODE ST7735_BLACK // defines the background of letters of the text


void finalModeScreen(const CalorieInfo *person_cal_info);

#endif /* INC_STATES_FINAL_MODE_H_ */
