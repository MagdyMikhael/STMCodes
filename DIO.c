

/***********************************************************
********************* # Includes ***************************
***********************************************************/
#include <stdint.h>
#include "stm32f10x.h"
#include "DIO.h"
#include "utilites.h"


/***********************************************************
********************* Global Variables *********************
***********************************************************/



/***********************************************************
***************** Function Definitions *********************
***********************************************************/


/* DIO_Pin_Init Functions is a function to initial the clk
and the features to each pin in the MC */

void DIO_Pin_Init(s_PinConfig * PIN){
	
	// two variables to define port num and pin index according to pin name
	uint8_t Pin_Location = PIN->PinNum / PortPins ;
	uint8_t Pin_Index = PIN->PinNum % PortPins;

	switch(Pin_Location){
		case 0:set_bit(RCC->APB2ENR,IOPAEN);
					 Port_Config_Reg(PIN);
					
			break;
		case 1:set_bit(RCC->APB2ENR,IOPBEN);
					 Port_Config_Reg(PIN);
			break;
		case 3:set_bit(RCC->APB2ENR,IOPCEN);
					 Port_Config_Reg(PIN);
			break;
		default:
			break;
		
	}
	
	
	
}

/*----------------------------------------------------------
----------------------------------------------------------*/
void DIO_Pin_Write(uint8_t PinNum ,uint8_t PinValue){
	// two variables to define port num and pin index according to pin name
	uint8_t Pin_Location = PinNum / PortPins ;
	uint8_t Pin_Index = PinNum % PortPins;
	if(PinValue ==1){
		switch (Pin_Location){
			case 0:set_bit(GPIOA->ODR,PinNum);
						
				break;
			case 1:set_bit(GPIOB->ODR,PinNum);
				break;
			case 3:set_bit(GPIOC->ODR,PinNum);
				break;
			default:
				break;
		}
	}else if (PinValue ==0 ){
		switch (Pin_Location){
			case 0:clr_bit(GPIOA->ODR,PinNum);
						
				break;
			case 1:clr_bit(GPIOB->ODR,PinNum);
				break;
			case 3:clr_bit(GPIOC->ODR,PinNum);
				break;
			default:
				break;
		}
	}
	
}
/*----------------------------------------------------------
----------------------------------------------------------*/
void DIO_Pin_Read(uint8_t PinNum ,uint8_t * PinValue){
	// two variables to define port num and pin index according to pin name
	uint8_t Pin_Location = PinNum / PortPins ;
	uint8_t Pin_Index = PinNum % PortPins;
	
	switch (Pin_Location){
			case 0:*PinValue = get_bit(GPIOA->IDR,PinNum);
						
				break;
			case 1:*PinValue = get_bit(GPIOB->IDR,PinNum);
				break;
			case 3:*PinValue = get_bit(GPIOC->IDR,PinNum);
				break;
			default:
				break;
		}
}

/*----------------------------------------------------------
----------------------------------------------------------*/
uint32_t Port_Config_Reg(s_PinConfig * PIN){
	uint8_t Pin_Index = PIN->PinNum % PortPins;
	
	uint32_t mode;
	uint32_t cnf;
	if((PIN->PinMode)==OutS50){
				mode = GPIO_CRL_MODE0;
				if((PIN->PinCNF)==GeneralPpull){
					cnf |= CNF;
				}else if((PIN->PinCNF)==GeneralOdrain){
					cnf |= GPIO_CRL_CNF0_0;
				}else if((PIN->PinCNF)==AlterPpull){
					cnf |= GPIO_CRL_CNF0_1;
				}else if((PIN->PinCNF)==AlterOdrain){
					cnf |= GPIO_CRL_CNF0;
				}
		
		
	}else if((PIN->PinMode)==OutS10){
				mode = GPIO_CRL_MODE0_0;
				if((PIN->PinCNF)==GeneralPpull){
					cnf |= CNF;
				}else if((PIN->PinCNF)==GeneralOdrain){
					cnf |= GPIO_CRL_CNF0_0;
				}else if((PIN->PinCNF)==AlterPpull){
					cnf |= GPIO_CRL_CNF0_1;
				}else if((PIN->PinCNF)==AlterOdrain){
					cnf |= GPIO_CRL_CNF0;
				}
		
		
		
	}else if((PIN->PinMode)==OutS2){
				mode = GPIO_CRL_MODE0_1;
				if((PIN->PinCNF)==GeneralPpull){
					cnf |= CNF;
				}else if((PIN->PinCNF)==GeneralOdrain){
					cnf |= GPIO_CRL_CNF0_0;
				}else if((PIN->PinCNF)==AlterPpull){
					cnf |= GPIO_CRL_CNF0_1;
				}else if((PIN->PinCNF)==AlterOdrain){
					cnf |= GPIO_CRL_CNF0;
				}
		
		
		
	}else if((PIN->PinMode)==InMode) {
				mode |=MODE;
				if((PIN->PinCNF)==AnalogMode){
					cnf &=~ GPIO_CRL_CNF0;
				}else if((PIN->PinCNF)==FloatIn){
					cnf |= GPIO_CRL_CNF0_0;
				}else if((PIN->PinCNF)==InWPull){
					cnf |= GPIO_CRL_CNF0_1;
				}else {
				}
	}
	
	
	if (Pin_Index < 8){
		switch(Pin_Index){
			case 0: GPIOA->CRL |=(mode<<shift0) ;
							GPIOA->CRL &=~(cnf<<shift0);
				break;
			case 1: GPIOA->CRL |=(mode<<shift4) ;
							GPIOA->CRL &=~(cnf<<shift4);
				break;
			case 2: GPIOA->CRL |=(mode<<shift8) ;
							GPIOA->CRL &=~(cnf<<shift8);
				break;
			case 3: GPIOA->CRL |=(mode<<shift12) ;
							GPIOA->CRL &=~(cnf<<shift12);
				break;
			case 4: GPIOA->CRL |=(mode<<shift16) ;
							GPIOA->CRL &=~(cnf<<shift16);
				break;
			case 5: GPIOA->CRL |=(mode<<shift20) ;
							GPIOA->CRL &=~(cnf<<shift20);
				break;
			case 6: GPIOA->CRL |=(mode<<shift24) ;
							GPIOA->CRL &=~(cnf<<shift24);
				break;
			case 7: GPIOA->CRL |=(mode<<shift28) ;
							GPIOA->CRL &=~(cnf<<shift28);
				break;
			default:
				break;
		}
	}
	if (Pin_Index >7){
		Pin_Index =Pin_Index -8;
		switch(Pin_Index){
			case 0: GPIOA->CRH |=(mode<<shift0) ;
							GPIOA->CRH &=~(cnf<<shift0);
				break;
			case 1: GPIOA->CRH |=(mode<<shift4) ;
							GPIOA->CRH &=~(cnf<<shift4);
				break;
			case 2: GPIOA->CRH |=(mode<<shift8) ;
							GPIOA->CRH &=~(cnf<<shift8);
				break;
			case 3: GPIOA->CRH |=(mode<<shift12) ;
							GPIOA->CRH &=~(cnf<<shift12);
				break;
			case 4: GPIOA->CRH |=(mode<<shift16) ;
							GPIOA->CRH &=~(cnf<<shift16);
				break;
			case 5: GPIOA->CRH |=(mode<<shift20) ;
							GPIOA->CRH &=~(cnf<<shift20);
				break;
			case 6: GPIOA->CRH |=(mode<<shift24) ;
							GPIOA->CRH &=~(cnf<<shift24);
				break;
			case 7: GPIOA->CRH |=(mode<<shift28) ;
							GPIOA->CRH &=~(cnf<<shift28);
				break;
			default:
				break;
		}
	}
}