/* 
 * File:   SPI2CONFIG.h
 * Author: Adoney
 *
 * Created on October 30, 2017, 7:57 PM
 */
#include "SPI.h"
#include "UART.h"
#include "ADXL345.h"
#include "DATATYPES.h"
#include <stdio.h>
#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
void INTTOASCII(int DATA, int SIZE);
struct DATA_PACKET READDATA();
void DISPLAYDATA(struct DATA_PACKET DATA);

void main (void)
{   
    int DUMMY; 
    int i = 0; //i will be used to index the buffer arrays
    struct DATA_PACKET DATA;

    INTISPI2(); //Initialize SPI2 on the MX4 board
    INTIUART1();//Initialize UART1 on the MX4 board
    
    //To ensure that the SPI module is configured correctly the DEVICE ID is read
    //If it matches the know ID 0xE5 the program continues
    while(DUMMY != 0xE5)
    {
        DUMMY = READSPI2(ADXL345_DEVID, 0);        
    }
    //Sets up the ADXL345 to sensitivity 2g, measure mode, no interrupts, and 3200Hz
    ADXL345SETUP();//Configure the ADXL345
    while(1)
    {
        DATA = READDATA();//Reads the x, y, z data registers 
        DELAY(100000); //Small Delay between reads
        SENDUART1(DATA.X0);
        SENDUART1(DATA.X1);
        SENDUART1(DATA.Y0);
        SENDUART1(DATA.Y1);
        SENDUART1(DATA.Z0);
        SENDUART1(DATA.Z1);
        //DISPLAYDATA(DATA);        
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
    WRITESPI2(ADXL345_POWER_CTL, 0);//Clears the power control register
    WRITESPI2(ADXL345_POWER_CTL, ADXL345_MEASURE);//Addresses the power control register of the sensor and sets bit 3
    WRITESPI2(ADXL345_BW_RATE, ADXL345_RATE_3200);//Addresses the baud rate register of the sensor and sets the bits D3-D0
}

//Converts the numeric values into the ascii value
void INTTOASCII(int DATA, int SIZE)
{
    int i = 0;
    BYTE array[10];
    int temp;
    int temp2;
    
    if(SIZE == 0)
    {
        SIZE = 1;
        temp2 = 1;
    }
    else
    {
        temp2 = pow(10, (SIZE-1));
    }
    
    for(i = 0; i < SIZE; i++)
    {
        temp = DATA / temp2;
        array[i] = temp + 48;
        DATA = DATA % temp2;
        temp2 = temp2 / 10;
    }
    
    for(i = 0; i < SIZE; i++)
    {
        SENDUART1(array[i]);
    }

}

struct DATA_PACKET READDATA()
{
    BYTE DUMMY;
    struct DATA_PACKET DATA;
    
    LATGbits.LATG9 = 0;

    SPI2BUF = (ADXL345_DATAX0 | ADXL345_MB | ADXL345_READ);
    while(!SPI2STATbits.SPIRBF);
    DUMMY = SPI2BUF;

    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    DATA.X0 = SPI2BUF;

    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    DATA.X1 = SPI2BUF;

    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    DATA.Y0 = SPI2BUF;

    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    DATA.Y1 = SPI2BUF;

    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    DATA.Z0 = SPI2BUF;

    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    DATA.Z1 = SPI2BUF;

    LATGbits.LATG9 = 1;
    return DATA;
}

void DISPLAYDATA(struct DATA_PACKET DATA)
{
    int x_data;
    int y_data;
    int z_data;
    char buffer [4];
    
    x_data = (int)((short)(DATA.X1 << 8) | DATA.X0);
    y_data = (int)((short)(DATA.Y1 << 8) | DATA.Y0);
    z_data = (int)((short)(DATA.Z1 << 8) | DATA.Z0);
    
    SENDUART1(CHAR_X);//X
    SENDUART1(COLON);//:
    itoa(buffer, x_data, 10);//Convert the number to ascii code 
    SENDUART1ARRAY(buffer, 4);//Send to terminal 
    SENDUART1(32);//Space 
    
    SENDUART1(CHAR_Y);
    SENDUART1(COLON);
    itoa(buffer, y_data, 10);
    SENDUART1ARRAY(buffer, 4);
    SENDUART1(32);
    
    SENDUART1(CHAR_Z);
    SENDUART1(COLON);
    itoa(buffer, z_data, 10);
    SENDUART1ARRAY(buffer, 4);
    
    SENDUART1(10);//Newline
    SENDUART1(13);//Return
}