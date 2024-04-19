/*
 * FanController.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Zyad Montaser
 */

#include "adc.h"
#include "lcd.h"
#include "DC_motor.h"

uint8 LM35_getTemperature(void);/* function prototype*/

int main()
{
	uint8 temperature;

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Configurations = {internal_VREF,F_CPU_8};

	/*passing the configuration structure to the function by address*/
	ADC_init(&ADC_Configurations);

	/*Function responsible for setup direction of the two pins of motor and initially stop it */
	DcMotor_Init();

	 /*Function responsible for initialize the LCD:
	 * 1. Setup the LCD pins directions by use the GPIO driver.
	 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
	 */
	LCD_init();

	/*display the temperature value and the fan state continuously*/
	LCD_displayStringRowColumn(0,3,"FAN is ");
	LCD_displayStringRowColumn(1,3,"Temp = ");

	while(1)
	{
		/*store the temperature in variable*/
		temperature=LM35_getTemperature();

		/*force the cursor to go to place 10*/
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		LCD_displayString("  "); /*Display double space to avoid char overwrite*/

		/*check the temperature to decide whether to turn on or off the fan and speed*/
		if(temperature <30)
		{
			DcMotor_Rotate(DcMotor_OFF,0);

			LCD_displayStringRowColumn(0,10,"OFF");
		}
		else if(temperature >=30 && temperature <60)
		{
			DcMotor_Rotate(DcMotor_CW,25);

			LCD_displayStringRowColumn(0,10,"ON ");/*display space after "ON" to avoid overwrite*/
		}
		else if(temperature >=60 && temperature <90)
		{
			DcMotor_Rotate(DcMotor_CW,50);

			LCD_displayStringRowColumn(0,10,"ON ");/*display space after "ON" to avoid overwrite*/
		}
		else if(temperature >=90 && temperature <120)
		{
			DcMotor_Rotate(DcMotor_CW,75);

			LCD_displayStringRowColumn(0,10,"ON ");/*display space after "ON" to avoid overwrite*/
		}
		else if(temperature >=120)
		{
			DcMotor_Rotate(DcMotor_CW,100);

			LCD_displayStringRowColumn(0,10,"ON ");/*display space after "ON" to avoid overwrite*/
		}

	}
}
