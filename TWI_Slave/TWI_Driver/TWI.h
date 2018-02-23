/*
 * TWI.h
 *
 *  Created on: Jan 20, 2018
 *      Author: Khalid
 */

#ifndef TWI_H_
#define TWI_H_

// Definitions

// Device 1 == Master || Device 0 == Slave
#define Device 0

#define Bit_Rate 100

// TWSR (Status Register) Codes to Check

// Master Transmitter

#define START_Bit_Code 0x08
#define REPEATED_Bit_Code 0x10
#define SLA_W_Transmitted_ACK_Code 0x18
#define Data_M_Transmitted_ACK_Code 0x28

// Master Receiver

#define SLA_R_ACK_Code 0x40
#define Data_M_Receive_ACK_Code 0x50

// Slave Receiver

#define SLA_W_Received_ACK_Code 0x60
#define Data_S_Received_ACK_Code 0x80
#define Stop_Or_Repeated_Bit 0xA0

// Slave Transmitter

#define SLA_R_Received_ACK_Code 0xA8
#define Data_S_Transmitted_ACK_Code 0xB8


// Functions Prototype

void TWI_EN(void);
void TWI_Init(void);
void TWI_Start_Bit(void);
void TWI_Stop_Bit(void);
void TWI_Device_Address(unsigned char Device_Address);
void TWI_SLA_Write(unsigned char SLA_W);
void TWI_SLA_Read(unsigned char SLA_R);
void TWI_Byte_Send(unsigned char byte);
unsigned char TWI_Byte_Receive(void);
void TWI_check_slave_Tx(void);

#endif /* TWI_H_ */
