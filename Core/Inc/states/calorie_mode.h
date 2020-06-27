/*
 * calorie_mode.h
 *
 *  Created on: 26 Haz 2020
 *      Author: DELL
 */

#ifndef INC_STATES_CALORIE_MODE_H_
#define INC_STATES_CALORIE_MODE_H_

#include "main.h"

#define TEXT_FONT_CLR_MODE Font_7x10
#define TEXT_COLOR_CLR_MODE ST7735_BLUE
#define BACKGROUND_COLOR_CLR_MODE ST7735_BLACK
#define TEXT_BACKGROUND_COLOR_CLR_MODE ST7735_WHITE // defines the background of letters of the text

typedef enum CalorieState {calorie_height_mode, calorie_weight_mode, calorie_amount_mode} CalorieState;

typedef struct CalorieInfo {
	uint8_t height;
	uint8_t weight;
	uint16_t calorie_amount;
} CalorieInfo;

void initCalorieMode(CalorieInfo* person_cal_info);
void calorieScreen(CalorieState* calorie_mode, CalorieInfo* person_cal_info);

void calorieHeightMode(CalorieState* calorie_mode, CalorieInfo* person_cal_info);
void calorieWeightMode(CalorieState* calorie_mode, CalorieInfo* person_cal_info);
void calorieAmountMode(CalorieState* calorie_mode, CalorieInfo* person_cal_info);


#endif /* INC_STATES_CALORIE_MODE_H_ */
