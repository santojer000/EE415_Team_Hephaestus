/* 
 * File:   SPI2CONFIG.h
 * Author: Adoney
 *
 * Created on October 30, 2017, 7:57 PM
 */
#include <plib.h>
#include "SPI.h"
#include "UART.h"
#include "ADXL345.h"
#include <stdio.h>
#include <xc.h>

//Configures the PBCLK to 40Mhz
#pragma config FNOSC = PRIPLL 
#pragma config POSCMOD = EC
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config FPLLODIV = DIV_1
#pragma config FPBDIV = DIV_2
#pragma config FSOSCEN = OFF
void DELAY(int x);
void ADXL345SETUP();
void INTTOASCII(int DATA);

void main (void)
{   
    int DUMMY; 
    int i = 0; //i will be used to index the buffer arrays
    int DATA[6]; //Will copy the pointer address for the read data
    
    
    INTISPI2(); //Initialize the SPI2 on the MX4 board
    INTIUART1();
    
    while(DUMMY != 0xE5)
    {
        DUMMY = READSPI2(ADXL345_DEVID, 0);        
    }
    ADXL345SETUP();//Configure the ADXL345
    while(1)
    {
        LATGbits.LATG9 = 0;
        
        SPI2BUF = (ADXL345_DATAX0 | ADXL345_MB | ADXL345_READ);
        while(!SPI2STATbits.SPIRBF);
        DUMMY = SPI2BUF;
        
        SPI2BUF = 0;
        while(!SPI2STATbits.SPIRBF);
        DATA[0] = SPI2BUF;
        
        SPI2BUF = 0;
        while(!SPI2STATbits.SPIRBF);
        DATA[1] = SPI2BUF;
        
        SPI2BUF = 0;
        while(!SPI2STATbits.SPIRBF);
        DATA[2] = SPI2BUF;
        
        SPI2BUF = 0;
        while(!SPI2STATbits.SPIRBF);
        DATA[3] = SPI2BUF;
        
        SPI2BUF = 0;
        while(!SPI2STATbits.SPIRBF);
        DATA[4] = SPI2BUF;
        
        SPI2BUF = 0;
        while(!SPI2STATbits.SPIRBF);
        DATA[5] = SPI2BUF;
        
        LATGbits.LATG9 = 1;
        DELAY(50000); //Small Delay between reads
        
        SENDUART1(88);
        SENDUART1(58);
        INTTOASCII((DATA[1] << 8 | DATA[0]));
        SENDUART1(89);
        SENDUART1(58);
        INTTOASCII((DATA[3] << 8 | DATA[2]));
        SENDUART1(90);
        SENDUART1(58);
        INTTOASCII((DATA[5] << 8 | DATA[4]));
    }
    return 0;
}

void DELAY(int x)
{
    int i = 0;
    for(i = 0; i < x; i++);
}

void ADXL345SETUP()
{
    WRITESPI2(ADXL345_POWER_CTL, 0);
    WRITESPI2(ADXL345_POWER_CTL, ADXL345_MEASURE);//Addresses the power control register of the sensor and sets bit 3
    WRITESPI2(ADXL345_BW_RATE, ADXL345_RATE_3200);//Addresses the baud rate register of the sensor and sets the bits D3-D0
}

void INTTOASCII(int DATA)
{
    int i = 0;
    int array[3];
    int temp;
    
    temp = DATA / 100; 
    array[0] = temp + 48;
    DATA = DATA % 100;
    
    temp = DATA / 10;
    array[1] = temp + 48;
    DATA = DATA % 10;
    
    temp = DATA / 1;
    array[2] = temp + 48;
        
    for(i = 0; i < 3; i++)
    {
        SENDUART1(array[i]);
    }

}