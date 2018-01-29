/*
 * main.c
 *
 *  Created on: Jan 20, 2018
 *      Author: Khalid
 */

#include "TWI_Driver/TWI.h"
#include <avr/io.h>
#include <util/delay.h>
int main()
{
	int x=0;
	TWI_Init();
	while(1)
	{
		TWI_Start_Bit();
		TWI_SLA_Write(0x02);
		for(x=0;x<10;x++)
		{
			TWI_Byte_Send('a');
			_delay_ms(300);
			TWI_Byte_Send('b');
		}
		TWI_Stop_Bit();
	}
	return 0;
}
