# TWI-
TWI - Two-wire Serial Interface -  / -Atmega 32 -

# Summarized Description
#### TWI - I2C The two sides of the same coin . Invented in 1982 by Philips Semiconductor 

## Only Two Bus Lines Needed
## Multiple Master / Multiple Slave 
## Can operates Receiver and transmitter
## 128 Different Slave Addresses
## 400kHz Data Transfer Speed

## APIs
### void TWI_EN(void);
### void TWI_Init(void);
### void TWI_Start_Bit(void);
### void TWI_Stop_Bit(void);
### void TWI_Device_Address(unsigned char Device_Address);
### void TWI_SLA_Write(unsigned char SLA_W);
### void TWI_SLA_Read(unsigned char SLA_R);
### void TWI_Byte_Send(unsigned char byte);
### unsigned char TWI_Byte_Receive(void);
