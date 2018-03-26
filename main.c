#include "stm32f10x.h"

#include "DIO.h"
#include "LcdD.h"

int main(){
	
	s_PinConfig pin0={PA0,InMode,InWPull};
	s_PinConfig pin1={PA1,OutS2,GeneralOdrain};
	DIO_Pin_Init(&pin0);
	DIO_Pin_Init(&pin1);
	uint8_t value;
	while(1){
		
		DIO_Pin_Read(PA0,&value);
		delay(500);
		if(value==1){
			DIO_Pin_Write(PA1,1);} // pull up resistor
		
		if(value ==0){
			
			DIO_Pin_Write(PA1,0);
			
		}
	}
	
	
	return 0;
}