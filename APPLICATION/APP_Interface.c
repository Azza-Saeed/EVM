/*
 * App.c
 *
 * Created: 9/5/2023 10:54:48 AM
 *  Author: Azza Saeed
 */ 

#include "APP_Private.h"

#include "STD_Types.h"
#include "LCD_Private.h"
#include "button_Private.h"

UINT8_t A_Counter=0;
UINT8_t B_Counter=0;
UINT8_t C_Counter=0;
UINT8_t D_Counter=0;
bool PINA_State;
bool PINB_State;
bool PINC_State;
bool PIND_State;

State_Error App_Init(void){
	LCD_Initialize();
	BTN_Initialization(DIO_PORTD,A_PIN); // for A
	BTN_Initialization(DIO_PORTD,B_PIN); // for B
	BTN_Initialization(DIO_PORTD,C_PIN); // for C
	BTN_Initialization(DIO_PORTD,D_PIN); // for D
	LCD_Initialize();
	return State_SUCCESS;
}
State_Error App_main(void){
	State_Error Local_Error=State_SUCCESS;
    LCD_Page();
	Main_Task();
	return Local_Error;
}

State_Error LCD_Page(void){
	LCD_LINE_position(LCD_LINE1,1);
	LCD_Write_String("Electronic Voting");
	LCD_LINE_position(LCD_LINE2,6);
	LCD_Write_String("Machine");
	LCD_LINE_position(LCD_LINE3,1);
	LCD_Write_String("A=");
	LCD_LINE_position(LCD_LINE3,3);
	LCD_Write_Number(A_Counter);
	LCD_LINE_position(LCD_LINE3,10);
	LCD_Write_String("B=");	
	LCD_LINE_position(LCD_LINE3,12);
	LCD_Write_Number(B_Counter);
	LCD_LINE_position(LCD_LINE4,1);
	LCD_Write_String("C=");
	LCD_LINE_position(LCD_LINE4,3);
	LCD_Write_Number(C_Counter);
	LCD_LINE_position(LCD_LINE4,10);
	LCD_Write_String("D=");
	LCD_LINE_position(LCD_LINE4,12);
	LCD_Write_Number(D_Counter);
	return State_SUCCESS;
}
State_Error Main_Task(void){
	State_Error Local_Error=State_SUCCESS;
		BTN_pressed(DIO_PORTD,A_PIN,&PINA_State);
		BTN_pressed(DIO_PORTD,B_PIN,&PINB_State);
		BTN_pressed(DIO_PORTD,C_PIN,&PINC_State);
		BTN_pressed(DIO_PORTD,D_PIN,&PIND_State);
    if(PINA_State==HIGH){
		A_Counter++;
		LCD_LINE_position(LCD_LINE3,3);
		LCD_Write_Number(A_Counter);
		_delay_ms(1000);
	}
	else if(PINB_State==HIGH){
		B_Counter++;
		LCD_LINE_position(LCD_LINE3,12);
		LCD_Write_Number(B_Counter);	
		_delay_ms(1000);
	}
	else if(PINC_State==HIGH){
		C_Counter++;
		LCD_LINE_position(LCD_LINE4,3);
		LCD_Write_Number(C_Counter);
			_delay_ms(1000);
	}
	else if(PIND_State==HIGH){
		D_Counter++;
		LCD_LINE_position(LCD_LINE4,12);
		LCD_Write_Number(D_Counter);		
		_delay_ms(1000);
	}else{
		Local_Error=State_FAIL;
	}
	return Local_Error;
}