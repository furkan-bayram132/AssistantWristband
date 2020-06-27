/*
 * main_mode.c
 *
 *  Created on: 28 Haz 2020
 *      Author: DELL
 */


#include "states/main_mode.h"

extern I2C_HandleTypeDef hi2c1;
extern SPI_HandleTypeDef hspi3;
extern UART_HandleTypeDef huart6;

void mainScreen() {
	AccData acc_3d;
	while (1)
	{
		HAL_StatusTypeDef is_mma8452q_read_ok = mma8452qRead(&hi2c1, 0x00, 7, acc_3d.acc_info);
		if (is_mma8452q_read_ok == HAL_OK) {
			getAccXYZ(&acc_3d);
			char message[50] = { 0 };
			//sprintf(message, "acc_x: %d, acc_y: %d, acc_z: %d\r\n", acc_3d.x_acc, acc_3d.y_acc, acc_3d.z_acc);
			double x_acc = acc_3d.x_acc / 1024.;
			double y_acc = acc_3d.y_acc / 1024.;
			double z_acc = acc_3d.z_acc / 1024.;
			//double magnitude = sqrt((x_acc * x_acc) + (y_acc * y_acc) + (z_acc * z_acc));
			sprintf(message, " %.2f %.2f %.2f", x_acc, y_acc, z_acc);
			ST7735_WriteString(0, 50, message, TEXT_FONT_MAIN_MODE, TEXT_COLOR_MAIN_MODE, TEXT_BACKGROUND_COLOR_MAIN_MODE);
			/*HAL_StatusTypeDef blue_ok = HAL_UART_Transmit(&huart6, (uint8_t *)message, sizeof(message), 100);
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
	}
}
