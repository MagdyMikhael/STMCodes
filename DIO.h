#ifndef DIO_H_
#define DIO_H_




/***********************************************************
********************* # Includes ***************************
***********************************************************/

/***********************************************************
**************** Definitions and Configrations *************
***********************************************************/
#define PortPins 16
#define IOPAEN 2
#define IOPBEN 3
#define IOPCEN 4



// MODEy 
#define MODE 0x00
#define InMode 00
#define OutS10 01
#define OutS2  10
#define OutS50 11

// CNFy
#define CNF 0x00
// input
#define AnalogMode 00
#define FloatIn    01
#define InWPull    10

//output
#define GeneralPpull 00
#define GeneralOdrain 01
#define AlterPpull 10
#define AlterOdrain 11


// OutPut Values
#define HIGH 1
#define LOW 0
/***********************************************************
************ Extern Moudle shared global variables *********
***********************************************************/

/***********************************************************
********************* Enums ********************************
***********************************************************/
enum{
	PA0=0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PA8,
	PA9,
	PA10,
	PA11,
	PA12,
	PA13,
	PA14,
	PA15,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PB8,
	PB9,
	PB10,
	PB11,
	PB12,
	PB13,
	PB14,
	PB15,
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PC8,
	PC9,
	PC10,
	PC11,
	PC12,
	PC13,
	PC14,
	PC15
	};

enum{
	shift0=0,
	shift2=2,
	shift4=4,
	shift6=6,
	shift8=8,
	shift10=10,
	shift12=12,
	shift14=14,
	shift16=16,
	shift18=18,
	shift20=20,
	shift22=22,
	shift24=24,
	shift26=26,
	shift28=28,
	shift30=30,
	
};
/***********************************************************
********************* Structures and Unions ****************
***********************************************************/
typedef struct PinConfig{
	uint8_t PinNum;
	uint8_t PinMode;
	uint8_t PinCNF;
}s_PinConfig;
/***********************************************************
********************* Functions Like Macros ****************
***********************************************************/


/***********************************************************
********************* Functions Prototypes *****************
***********************************************************/
void DIO_Pin_Init(s_PinConfig * PIN);
void DIO_Pin_Write(uint8_t PinNum ,uint8_t PinValue);
void DIO_Pin_Read(uint8_t PinNum ,uint8_t * PinValue); 	
	
uint32_t Port_Config_Reg(s_PinConfig * PIN);




#endif //DIO_H_