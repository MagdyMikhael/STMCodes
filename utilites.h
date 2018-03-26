/*
 * utilites.h
 *
 * Created: 2/20/2018 10:15:13 PM
 *  Author: magdy
 */ 


#ifndef UTILITES_H_
#define UTILITES_H_

#define assign_bit(reg,bit_no,value) reg=((~(1<<bit_no))&reg)|(value<<bit_no)
#define get_bit(reg,bits_no)  (reg &(1<<bits_no))>>bits_no
#define clr_bit(reg,bits_no)   reg &= ~(1<<bits_no)
#define set_bit(reg,bits_no)  reg|=(1<<bits_no)
#define set_two_bits(Reg,bitNum1,bitNum2) Reg=Reg|(1<<bitNum1)|(1<<bitNum2)
#define set_three_bits(Reg,bitNum1,bitNum2,bitNum3) Reg=Reg|(1<<bitNum1)|(1<<bitNum2)|(1<<bitNum3)
#define set_four_bits(Reg,bitNum1,bitNum2,bitNum3,bitNum4) Reg=Reg|(1<<bitNum1)|(1<<bitNum2)|(1<<bitNum3)|(1<<bitNum4)
#define toggele_bit(reg,bits_no)  reg^=(1<<bits_no)
#define set_reg(reg) reg= 0xff
#define clr_reg(reg)  reg = 0x00
#define toogle_reg(reg) reg^=0xff
#define assign_reg(reg,value)   reg=value
#define get_low_nible(reg) reg& 0x0f
#define clr_low_nible(reg ) reg&= 0xf0
#define set_low_nible(reg )  reg|=0x0f
#define toggle_low_nible(reg) reg^=0x0f
#define assign_low_nible(reg,value) reg=(reg&0xf0)|(value&0x0f)
#define get_high_nible(reg) (reg& 0x0f )>> 4
#define clr_high_nible(reg) reg&=0x0f
#define set_high_nible(reg) reg|=0xf0
#define toggle_high_nible(reg) reg^=0xf0
#define assign_high_nible(reg,value) reg=(reg&0x0f)|(value<<4)





#endif /* UTILITES_H_ */