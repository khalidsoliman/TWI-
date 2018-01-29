/*
 * main.c
 *
 *  Created on: Jan 21, 2018
 *      Author: A7med
 */

#include "TWI_Driver/TWI.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	TWI_Init();
	TWI_Device_Address(0x02);
	DDRA|=(1<<PA3);
	PORTA &=~(1<<PA3);
	DDRD|=(1<<PD5);
	PORTD &=~(1<<PD5);
	char Data =0;
	while (1)
	{
		Data=TWI_Byte_Receive();
		if(Data=='a') PORTA^=0xff;
		else if (Data=='b') PORTD^=0xff;
	}
	return 0;
}
