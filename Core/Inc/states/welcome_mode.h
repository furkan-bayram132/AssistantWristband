/*
 * welcome_mode.h
 *
 *  Created on: 26 Haz 2020
 *      Author: hizirov
 */

#ifndef INC_WELCOME_MODE_H_
#define INC_WELCOME_MODE_H_

#include "custom_peripherals/st7735.h"
#include "main.h"

#include <string.h>

#define TEXT_FONT_WLC_MODE Font_11x18
#define TEXT_COLOR_WLC_MODE ST7735_BLUE
#define BACKGROUND_COLOR_WLC_MODE ST7735_BLACK
#define TEXT_BACKGROUND_COLOR_WLC_MODE ST7735_BLACK // defines the background of letters of the text



void welcomeScreen();

#endif /* INC_WELCOME_MODE_H_ */
