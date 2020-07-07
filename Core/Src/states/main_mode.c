/*
 * main_mode.c
 *
 *  Created on: 28 Haz 2020
 *      Author: hizirov
 */


#include "states/main_mode.h"


extern I2C_HandleTypeDef hi2c1;
extern SPI_HandleTypeDef hspi3;
extern UART_HandleTypeDef huart6;

extern uint32_t current_step;
extern uint32_t step_num;
extern uint32_t elapsed_time;
extern state current_state;
extern state mode_state;


void mainScreen(const CalorieInfo *person_cal_info) {
	char text1[25] = { 0 };
	sprintf(text1, "  %ld / %ld step", current_step, step_num);
	ST7735_WriteString(0, 50, text1, TEXT_FONT_MAIN_MODE, TEXT_COLOR_MAIN_MODE, TEXT_BACKGROUND_COLOR_MAIN_MODE);
	uint32_t eta_time = ((step_num - current_step) * elapsed_time) / current_step;
	if (current_step >= step_num) {
		ST7735_FillScreen(BACKGROUND_COLOR_MAIN_MODE);
		current_state = final_mode;
		return;
	}
	uint32_t hour = 0, min = 0, sec = 0;
	convertSecToTimeStamp(eta_time, &hour, &min, &sec);
	char text2[25] = { 0 };
	sprintf(text2, "   ETA:  %ld:%ld:%ld ", hour, min, sec); // black character at the end of the string here
	// is important. for example 59 sec is displayed as 0:0:59 at the format above. as the seconds decrease,
	// assume it will be 49, 39, .... even going further, it will be 9 seconds. in this situation
	// what we expect would be 0:0:9. however, since before 9 seconds, there was 19 seconds, the lsb digit
	// of 19, which is 9, stays on the screen. thus we see 0:0:99 instead of 0:0:9. to avoid that we use
	// extra black so that it covers the extra digit coming from early calculations.
	ST7735_WriteString(0, 100, text2, TEXT_FONT_MAIN_MODE, TEXT_COLOR_MAIN_MODE, TEXT_BACKGROUND_COLOR_MAIN_MODE);
	getAccData();
}


void convertSecToTimeStamp(uint32_t elapsed_time, uint32_t* hour_ptr, uint32_t* min_ptr, uint32_t* sec_ptr) {
	*hour_ptr = elapsed_time / 3600;
	*min_ptr = (elapsed_time - (3600 * *hour_ptr)) / 60;
	*sec_ptr = elapsed_time - (3600 * *hour_ptr) - (*min_ptr * 60);
}


void getAccData() {
	AccData acc_3d;
	//while (1)
	//{
		HAL_StatusTypeDef is_mma8452q_read_ok = mma8452qRead(&hi2c1, 0x00, 7, acc_3d.acc_info);
		if (is_mma8452q_read_ok == HAL_OK) {
			getAccXYZ(&acc_3d);
			char message[50] = { 0 };
			//sprintf(message, "acc_x: %d, acc_y: %d, acc_z: %d\r\n", acc_3d.x_acc, acc_3d.y_acc, acc_3d.z_acc);
			int x_acc = acc_3d.x_acc ;
			int y_acc = acc_3d.y_acc ;
			int z_acc = acc_3d.z_acc ;
			int magnitude = sqrt((x_acc * x_acc) + (y_acc * y_acc) + (z_acc * z_acc));
			sprintf(message, " %d %d %d\r\n", x_acc, y_acc, magnitude);
			//ST7735_WriteString(0, 50, message, TEXT_FONT_MAIN_MODE, TEXT_COLOR_MAIN_MODE, TEXT_BACKGROUND_COLOR_MAIN_MODE);
			/*HAL_StatusTypeDef blue_ok = */HAL_UART_Transmit(&huart6, (uint8_t *)message, sizeof(message), 100);
			/*
			if (blue_ok == HAL_OK) {
				ST7735_WriteString(0, 100, "ok...", Font_7x10, ST7735_BLACK, ST7735_WHITE);
			}
			else {
				ST7735_WriteString(0, 100, "not ok...", Font_7x10, ST7735_BLACK, ST7735_WHITE);
			}*/
			HAL_Delay(100);
		}
		else {
			// uart ile buraya mesaj bas
		}
	//}
}
