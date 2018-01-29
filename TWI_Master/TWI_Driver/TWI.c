/*
 * TWI.c
 *
 *  Created on: Jan 20, 2018
 *      Author: Khalid
 */

#include "TWI.h"
#include <avr/io.h>

void TWI_EN(void)
{
	TWCR =(1<<TWINT)|(1<<TWEN);
}
void TWI_Init(void)
{
	// TWI Speed
#if Bit_Rate == 100
	TWBR=32;
#elif Bit_Rate == 400
	TWBR = 2;
#endif
	TWSR = 0;
	TWI_EN();
	TWCR|=(1<<TWEA);
}

#if Device == 1
void TWI_Start_Bit(void)
{
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while((!(TWCR&(1<<TWINT)))&&(((TWSR&0xF8)!=START_Bit_Code)||((TWSR&0xF8)!=REPEATED_Bit_Code)));
}
#endif

#if Device == 1
void TWI_Stop_Bit(void)
{
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
#endif

#if Device == 0
void TWI_Device_Address(unsigned char Device_Address)
{
	TWAR=(Device_Address<<1);
}
#endif

#if Device == 1
void TWI_SLA_Write(unsigned char SLA_W)
{
	TWDR = ((SLA_W<<1)& 0xFE);
	TWI_EN();
	while((!(TWCR&(1<<TWINT)))&&(((TWSR&0xF8)!=SLA_W_Transmitted_ACK_Code)));
}
#endif

#if Device == 1
void TWI_SLA_Read(unsigned char SLA_R)
{
	TWDR = ((SLA_R<<1)|0x01);
	TWI_EN();
	TWCR|=(1<<TWEA);
	while((!(TWCR&(1<<TWINT)))&&(((TWSR&0xF8)!=SLA_R_ACK_Code)));
}
#endif


void TWI_Byte_Send(unsigned char byte)
{
	TWDR = byte;
	TWI_EN();
	while((!(TWCR&(1<<TWINT)))&&(((TWSR&0xF8)!=Data_M_Transmitted_ACK_Code)||((TWSR&0xF8)!=Data_S_Transmitted_ACK_Code)));
}

unsigned char TWI_Byte_Receive(void)
{
#if Device == 1
	while((!(TWCR&(1<<TWINT)))&&(((TWSR&0xF8)!=Data_M_Receive_ACK_Code)));

#elif Device == 0
	while((!(TWCR&(1<<TWINT)))&&(((TWSR&0xF8)!=Stop_Or_Repeated_Bit)||(TWSR&0xF8)!=Data_S_Received_ACK_Code));
#endif
	TWI_EN();
	TWCR|=(1<<TWEA);
	return TWDR;
}
