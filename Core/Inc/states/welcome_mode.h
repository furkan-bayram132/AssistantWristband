/*
 * welcome_mode.h
 *
 *  Created on: 26 Haz 2020
 *      Author: DELL
 */

#ifndef INC_WELCOME_MODE_H_
#define INC_WELCOME_MODE_H_

#include "custom_peripherals/st7735.h"
#include "main.h"

#include <string.h>

#define TEXT_FONT Font_11x18
#define TEXT_COLOR ST7735_BLUE
#define BACKGROUND_COLOR ST7735_BLACK
#define TEXT_BACKGROUND_COLOR ST7735_BLACK

void welcomeScreen(state* current_state);

#endif /* INC_WELCOME_MODE_H_ */
