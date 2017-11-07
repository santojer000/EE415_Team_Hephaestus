/* 
 * File:   SPI_1_CONFIG.h
 * Author: Adoney
 *
 * Created on October 13, 2017, 1:30 PM
 */

#ifndef SPI_1_CONFIG_H
#define	SPI_1_CONFIG_H
#include <plib.h>

void SPI1CONFIG()
{
    //Configuring SP1 pins, setting board as Master, and sensor as Slave
    //PORT PIN DIRECTION USE
    // D    0    OUT    Data Out
    // D    9    OUT    Slave
    // D    10   OUT    CLOCK
    // C    4    IN     Data In
    //Set the clock as output
    TRISDCLR = 1 << 10;
    //Set SDI as input
	TRISCSET = 1 << 4;
    //Set SDO as output
    TRISDCLR = 1;
    //Set slave select line as output
    TRISDCLR = 1 << 9;
    //Slave Select High        
    LATDSET =  1 << 9;
            
   //Configure SPI module 
	SPI1CON = 0;
	
	//Disable SPI peripheral 
    SPI1CONCLR = 1 << 15;
	//Clear buffer 
	SPI1BUF = 0;
	
	// Set the PIC32 as master mode
	// SPI1CON<5> = 1
	SPI1CONSET = 1 << 5;

    //Clock polarity to high
	SPI1CONSET = 1 << 8;
	
	//Set the baud rate generator to 1MHz 
	//Load 19 into baud rate register to get 1Mhz at a 40Mhz PBCLK
    SPI1BRG = 19;
	
	//Enable SPI peripheral
    SPI1CONSET =  1 << 15;
}
    

    

//void SPI1CONFIG()
//{
     
//    TRISDCLR = 0x601;//Configure port pin D directions to output 
//    TRISCSET = 1 << 4;//Configure port pin C directions to input 
//    LATDSET = 1 << 9;//Start the Slave select high 
//    
//    //Configure SPI module 
//    SPI1CON = 0;//Clear the SPI control register
//    //SPI1CON<15> = 0: Disable SPI module, 1: Enable SPI module 
//    SPI1CONCLR = 0x8000;//Disable SPI module while configuring
//    SPI1BUF = 0;//Clear the SPI buffer register 
//    //Master: SPI1CON<5> = 1 
//    //Clock Polarity: SPI1CON<6> = 0
//    //Clock Phase: SPI1CON<8> = 0
//    //16 Bit mode: SPI1CON<11:10> = 01;
//    //Slave driven by user not module: SPI1CON<7> = 0 
//    SPI1CON = 0x420;
//    //Note no need for changing anything in the SPI2CON register        
//    //Load 19 into baud rate register to get 1Mhz at a 40Mhz PBCLK
//    SPI1BRG = 19;
//    //SPI1CON<15> = 1: Disable SPI module, 1: Enable SPI module 
//    SPI1CONSET = 0x8000;//Enable SPI module while configuring
//}
#endif	/* SPI_1_CONFIG_H */

