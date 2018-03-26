#include <stdint.h>
#include "LcdD.h"
#include "DIO.h"
#include "utilites.h"
#include "stm32f10x.h"


void delay(uint32_t Time_us){
	uint32_t x;
	for(x=0;x<Time_us;x++){
		__ASM("nop");
		__ASM("nop");
		__ASM("nop");
		__ASM("nop");
		__ASM("nop");
		__ASM("nop");
		__ASM("nop");
		__ASM("nop");
	}

}
///////////////////////////////////////////////////////////////
void LCD_COMMAND(uint8_t command){
        
	DIO_Pin_Write(LCD_RSPin,LOW);                                         // to select command
	DIO_Pin_Write(LCD_RWPin,LOW);                                         // to select write
	//take the first 4 bits
	DIO_Pin_Write(LCD_d7Pin,get_bit(command,7));
	DIO_Pin_Write(LCD_d6Pin,get_bit(command,6));
	DIO_Pin_Write(LCD_d5Pin,get_bit(command,5));
	DIO_Pin_Write(LCD_d4Pin,get_bit(command,4));
	// done take the first 4 bits
	DIO_Pin_Write(LCD_ENPin,HIGH);
	delay(1000);
	DIO_Pin_Write(LCD_ENPin,LOW);
	delay(1000);
	DIO_Pin_Write(LCD_d7Pin,get_bit(command,3));
	DIO_Pin_Write(LCD_d6Pin,get_bit(command,2));
	DIO_Pin_Write(LCD_d5Pin,get_bit(command,1));
	DIO_Pin_Write(LCD_d4Pin,get_bit(command,0));

	//DIO_WritePort(0,(command<<4));

	DIO_Pin_Write(LCD_ENPin,HIGH);
	delay(1000);
	DIO_Pin_Write(LCD_ENPin,LOW);
	delay(1000); // wait until the command run
}
///////////////////////////////////////////////////////////////
void LCD_DATA(uint8_t data){
	DIO_Pin_Write(LCD_RSPin,HIGH);
	DIO_Pin_Write(LCD_RWPin,LOW);

	DIO_Pin_Write(LCD_d7Pin,get_bit(data,7));
	DIO_Pin_Write(LCD_d6Pin,get_bit(data,6));
	DIO_Pin_Write(LCD_d5Pin,get_bit(data,5));
	DIO_Pin_Write(LCD_d4Pin,get_bit(data,4));
	
	DIO_Pin_Write(LCD_ENPin,HIGH);
	delay(1000);
	DIO_Pin_Write(LCD_ENPin,LOW);

	delay(1000);
	
	DIO_Pin_Write(LCD_d7Pin,get_bit(data,3));
	DIO_Pin_Write(LCD_d6Pin,get_bit(data,2));
	DIO_Pin_Write(LCD_d5Pin,get_bit(data,1)); 
	DIO_Pin_Write(LCD_d4Pin,get_bit(data,0));
	
	DIO_Pin_Write(LCD_ENPin,HIGH);
	delay(1000);
	DIO_Pin_Write(LCD_ENPin,LOW);
	delay(1000);

}
///////////////////////////////////////////////////////////////
void LCD_INIT(){
		
		s_PinConfig LcdRSPin ={LCD_RSPin,OutS10,GeneralPpull};
		s_PinConfig LcdRWPin ={LCD_RWPin,OutS10,GeneralPpull};
		s_PinConfig LcdENPin ={LCD_ENPin,OutS10,GeneralPpull};	
		s_PinConfig LcdD7Pin ={LCD_ENPin,OutS10,GeneralPpull};
		s_PinConfig LcdD6Pin ={LCD_d6Pin,OutS10,GeneralPpull};
		s_PinConfig LcdD5Pin ={LCD_d5Pin,OutS10,GeneralPpull};
		s_PinConfig LcdD4Pin ={LCD_d4Pin,OutS10,GeneralPpull};
			
		
		DIO_Pin_Init(&LcdRSPin);
		DIO_Pin_Init(&LcdRWPin);
		DIO_Pin_Init(&LcdENPin);
		DIO_Pin_Init(&LcdD7Pin);
		DIO_Pin_Init(&LcdD6Pin);
		DIO_Pin_Init(&LcdD5Pin);
		DIO_Pin_Init(&LcdD4Pin);
        
	
	
	delay(1000);
	LCD_COMMAND(0x33); // go to 4 bit mode
	LCD_COMMAND(0x32); // go to 4 bit mode
	LCD_COMMAND(0x28); //if 4 bit 2 line init
	LCD_COMMAND(0x0e); // display on cursor on
	LCD_COMMAND(0x01); // clear lcd
	delay(20000);
	LCD_COMMAND(0x06); // increament el cursor m3 el ktaba
	delay(10000);
	
	
}
///////////////////////////////////////////////////////////////
void LCD_GoToXY(uint8_t x,uint8_t y){
	uint8_t firstCharAdr[]={0x80,0xc0,0x94,0xd4};
	LCD_COMMAND(firstCharAdr[y-1]+x-1);
	delay(100000);
}
///////////////////////////////////////////////////////////////
void LCD_Print(uint8_t *str){
	uint8_t i=0;
	while(str[i]!=0){
		LCD_DATA(str[i]);
		i++;
	}
}