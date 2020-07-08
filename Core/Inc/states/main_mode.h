/*
 * main_mode.h
 *
 *  Created on: 28 Haz 2020
 *      Author: hizirov
 */

#ifndef INC_STATES_MAIN_MODE_H_
#define INC_STATES_MAIN_MODE_H_

#include "main.h"
#include "states/calorie_mode.h"

#define TEXT_FONT_MAIN_MODE Font_7x10
#define TEXT_COLOR_MAIN_MODE ST7735_BLUE
#define BACKGROUND_COLOR_MAIN_MODE ST7735_BLACK
#define TEXT_BACKGROUND_COLOR_MAIN_MODE ST7735_BLACK // defines the background of letters of the text


void mainScreen(const CalorieInfo *person_cal_info);
// takes sec as a parameter and converts it into hour/min/sec form
void convertSecToTimeStamp(uint32_t elapsed_time, uint32_t* hour_ptr, uint32_t* min_ptr, uint32_t* sec_ptr);
void getAccData(uint32_t elapsed_time, uint32_t current_step, uint32_t step_num);

#endif /* INC_STATES_MAIN_MODE_H_ */
