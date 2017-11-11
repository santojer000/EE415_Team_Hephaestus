/* 
 * File:   UART.h
 * Author: Adoney
 *
 * Created on November 10, 2017, 6:22 PM
 */

#ifndef UART_H
#define	UART_H
#include <xc.h>
#include "ADXL345.h"
#include "DATATYPES.h"

void INTIUART1(void)
{
    U1MODEbits.BRGH = 0;                // Baud Rate = 9600
    U1BRG = 259;
     
    U1MODEbits.SIDL = 0;                // Continue operation in SLEEP mode
     
    U1MODEbits.IREN = 0;                // IrDA is disabled
     
    U1MODEbits.RTSMD = 0;               // U1RTS pin is in Flow Control mode
     
    U1MODEbits.UEN = 0b00;              // U1TX, U1RX are enabled
     
    U1MODEbits.WAKE = 1;                // Wake-up enabled
     
    U1MODEbits.LPBACK = 0;              // Loopback mode is disabled
     
    U1MODEbits.RXINV = 0;               // U1RX IDLE state is '1'
     
    U1MODEbits.PDSEL = 0b00;            // 8-bit data, no parity
     
    U1MODEbits.STSEL = 0;               // 1 stop bit
     
    U1STAbits.UTXINV = 0;               // U1TX IDLE state is '1'
     
    U1MODEbits.ON = 1;                  // UART1 is enabled
     
    U1STAbits.URXEN = 1;                // UART1 receiver is enabled
     
    U1STAbits.UTXEN = 1;                // UART1 transmitter is enabled
}

void SENDUART1(BYTE data)
{
    U1STAbits.UTXEN = 1;                // Make sure transmitter is enabled
    while(U1STAbits.UTXBF);             // Wait while buffer is full
    U1TXREG = data;                        // Transmit character
}

BYTE READUART1(void)
{
    //RTS = 0                           // Optional RTS use
    while(!U1STAbits.URXDA)             // Wait for information to be received
    //RTS = 1
    return U1RXREG;                     // Return received character
}

#endif	/* UART_H */

