/*
 * App.h
 *
 * Created: 9/5/2023 10:54:59 AM
 *  Author: Azza Saeed
 */ 


#ifndef APP_PRIVATE_H_
#define APP_PRIVATE_H_

//#include "EHAL/Button/button_Private.h"

typedef enum{
	State_FAIL=0,
	State_SUCCESS=1
	}State_Error;

/**********************************************************
*              Functions Prototype
***********************************************************/

State_Error App_Init(void);
State_Error App_main(void);
State_Error LCD_Page(void);
State_Error Main_Task(void);

#define A_PIN 3
#define B_PIN 5
#define C_PIN 6
#define D_PIN 7


#endif /* APP_PRIVATE_H_ */