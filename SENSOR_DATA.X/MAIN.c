/* 
 * File:   SPI2CONFIG.h
 * Author: Adoney
 *
 * Created on October 30, 2017, 7:57 PM
 */
#include <plib.h>
#include "SPI2CONFIG.h"
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
void delay(int x)
{
    int i = 0;
    for(i = 0; i < x; i++);
}
void ADXL345SETUP()
{
    WriteSPI(ADXL345_POWER_CTL, 0);
    WriteSPI(ADXL345_POWER_CTL, ADXL345_MEASURE);//Addresses the power control register of the sensor and sets bit 3
    WriteSPI(ADXL345_BW_RATE, ADXL345_RATE_3200);//Addresses the baud rate register of the sensor and sets the bits D3-D0
}

int * ReadData(int address)
{
    int DATA[6]; //Will hold the six bytes of axis data two bytes for each axis
    int DUMMY;
    LATGbits.LATG9 = 0;// Set the chip select low
    
    SPI2BUF = address;                    // Write to buffer for transmission
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DUMMY = SPI2BUF;
    
    SPI2BUF = 0;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DATA[0] = SPI2BUF;              // First byte X0
    
    SPI2BUF = 0;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DATA[1] = SPI2BUF;              //Second byte X1
    
    SPI2BUF = 0;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DATA[2] = SPI2BUF;              // Third byte Y0
    
    SPI2BUF = 0;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DATA[3] = SPI2BUF;              //Fourth byte Y1
    
    SPI2BUF = 0;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DATA[4] = SPI2BUF;              //Fifth byte Z0
    
    SPI2BUF = 0;
    while (!SPI2STATbits.SPIRBF);   // Wait for transfer to be completed
    DATA[5] = SPI2BUF;              //Sixth byte Z1
    LATGbits.LATG9 = 1;             // Chip select high
    
    return DATA;//Return pointer to array 
}

void main (void)
{    
    int X_DATA[1024]; //1024 samples will be buffered for each axis
    int Y_DATA[1024];
    int Z_DATA[1024];
    
    int DUMMY; 
    int i = 0; //i will be used to index the buffer arrays
    int *DATA; //Will copy the pointer address for the read data
    
    initSPI(); //Initialize the SPI2 on the MX4 board
    
    while(DUMMY != 0xE5)
    {
        DUMMY = READSPI(ADXL345_DEVID, 0);
    }
    ADXL345SETUP();//Configure the ADXL345
    while(1)
    {
        //To ensure proper communication the device id is read
        for(i =0; i < 1025; i++)
        {
            DATA = ReadData(ADXL345_DATAX0 | ADXL345_READ | ADXL345_MB);
            X_DATA[i] = (*(DATA + 1) << 8) | *(DATA);
            Y_DATA[i] = (*(DATA + 3) << 8) | *(DATA + 2);
            Z_DATA[i] = (*(DATA + 5) << 8) | *(DATA + 4);
            delay(100000); //Small Delay between reads
        }
    }

    return 0;
}

