/* 
 * File:   SPI.h
 * Author: Adoney
 *
 * Created on November 10, 2017, 6:10 PM
 */

#ifndef SPI_H
#define	SPI_H
#include <xc.h>
#include "ADXL345.h"

void INTISPI2(void)
{
    TRISGbits.TRISG9 = 0;
    LATGbits.LATG9 = 1;         // Set CS high (idle state)
     
    IEC1bits.SPI2EIE = 0;       // SPI interrupts disabled
    IEC1bits.SPI2RXIE = 0;
    IEC1bits.SPI2TXIE = 0;
     
    SPI2CONbits.ON = 0;         // Turn off SPI module
     
    SPI2BUF = 0;                // Clear the receive buffer
     
    SPI2BRG = 4;                // FSCK = 1MHz
     
    SPI2STATbits.SPIROV = 0;    // Clear overflow flag
     
     
    /* SPI1CON settings */
    SPI2CONbits.FRMEN = 0;      // Framed SPI support is disabled
    SPI2CONbits.SIDL = 0;       // Continue operation in IDLE mode
    SPI2CONbits.DISSDO = 0;     // SDO1 pin is controlled by the module
    SPI2CONbits.MODE16 = 0;     // 16 bit mode
    SPI2CONbits.MODE32 = 0;
    SPI2CONbits.CKP = 1;        // Idle state for clock is high, active state is low
    SPI2CONbits.CKE = 0;        // Output data changes on transition from idle to active
    SPI2CONbits.SSEN = 0;       // Not in slave mode
    SPI2CONbits.MSTEN = 1;      // Master mode
    SPI2CONbits.SMP = 1;        // Input data sampled at the end of data output time
     
    SPI2CONbits.ON = 1;         // Turn module on
}

void WRITESPI2(int address, int data)
{
    int DUMMY;
    LATGbits.LATG9 = 0;// Set the chip select low
    SPI2BUF = address;                    // Write to buffer for transmission
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DUMMY = SPI2BUF;
    
    SPI2BUF = data;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DUMMY = SPI2BUF;
    LATGbits.LATG9 = 1;// Set the chip select back high
}
int READSPI2(int address, int data)
{
    int DUMMY;
    LATGbits.LATG9 = 0;// Set the chip select low
    //If the address is zero just want the device id no need to assert the read bit
    if(address == 0) 
    {
        SPI2BUF = address;   
    }
    else
    {
        SPI2BUF = (address | ADXL345_READ); 
    }
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DUMMY = SPI2BUF;
    //If the address is zero no data is written simply reading device id
    if(address == 0)
    {
        SPI2BUF = 0;   
    }
    else
    {
        SPI2BUF = data; 
    }
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DUMMY = SPI2BUF;
    LATGbits.LATG9 = 1;// Set the chip select back high
    return DUMMY;
}
#endif	/* SPI_H */

