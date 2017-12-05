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
#include "FFT_float_type.h"

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
void SENDDATA(int size, float *data);


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

	//Initialize index arrays
	int indeces[1024] = { 0 };
	int bit_reversed_indeces[1024] = { 0 };
	create_indeces(indeces);
	bit_reversal_indeces(indeces, bit_reversed_indeces);
	frequency_scaling(indeces);

//	//Initialize data arrays
	float x_samples[1024] = { 0 };
//	float y_samples[1024] = { 0 };
//	float z_samples[1024] = { 0 };
	
	float samples_reversed[1024] = { 0 };	
	float imaginary[1024] = { 0 };

	while (1)
	{
		//Read and merge data
		int i = 0;
		for (i = 0; i < 1024; i++)
		{
			DATA = READDATA();//Reads the x, y, z data registers
			DELAY(5000); //Small Delay between reads
			x_samples[i] = (int)((short)(DATA.X1 << 8) | DATA.X0);
			//			y_samples[i] = (float)(int)((short)(DATA.Y1 << 8) | DATA.Y0);
			//			z_samples[i] = (float)(int)((short)(DATA.Z1 << 8) | DATA.Z0);

		}

		//Process X Data
		//moving average filter added
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		moving_average_filter(samples_reversed, samples_reversed, 1024, 4);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Assign samples to new indeces
		bit_reversal(x_samples, samples_reversed, bit_reversed_indeces, 1024);
        FFT(10, samples_reversed, imaginary); //perform FFT
        magnitude(1024, samples_reversed, samples_reversed, imaginary); //Normalize data set
		amplitude_scaling(1024, samples_reversed);
		fft_shift(1024, samples_reversed); //Reorder output
        int j = 0;
        for (j = 0; j < 1024; j++)
		{
            int TEMP_DATA = (int)(samples_reversed[j]*100000);
            BYTE D_1 = (TEMP_DATA & 0xFF000000) >> 24;
            BYTE D_2 = (TEMP_DATA & 0x00FF0000) >> 16;                
            BYTE D_3 = (TEMP_DATA & 0x0000FF00) >> 8; 
            BYTE D_4 = (TEMP_DATA & 0x000000FF);
            SENDUART1(D_1);
            SENDUART1(D_2);
            SENDUART1(D_3);
            SENDUART1(D_4);
		}
        
        //Process Y Data
		//Assign samples to new indeces
//		bit_reversal(y_samples, samples_reversed, bit_reversed_indeces, 1024);
//        FFT(10, samples_reversed, imaginary); //perform FFT
//        magnitude(1024, samples_reversed, samples_reversed, imaginary); //Normalize data set
//		amplitude_scaling(1024, samples_reversed);
//		fft_shift(1024, samples_reversed); //Reorder output
//        SENDDATA(1024, samples_reversed); //Send data
//        
//        //Process Z Data
//		//Assign samples to new indeces
//		bit_reversal(z_samples, samples_reversed, bit_reversed_indeces, 1024);
//        FFT(10, samples_reversed, imaginary); //perform FFT
//        magnitude(1024, samples_reversed, samples_reversed, imaginary); //Normalize data set
//		amplitude_scaling(1024, samples_reversed);
//		fft_shift(1024, samples_reversed); //Reorder output
//        SENDDATA(1024, samples_reversed); //Send data
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

void SENDDATA(int size, float *data)
{
	BYTE D_1;
	BYTE D_2;
	BYTE D_3;
	BYTE D_4;
    int i = 0;
    int TEMP_DATA;
    
	for (i = 0; i < 1024; i++)
	{
        TEMP_DATA = (data[i]);
		D_1 = (TEMP_DATA & 0xFF000000) >> 24;//Mask off bits 31-24 >> Shift by 24 to get into 7-0 index
		D_2 = (TEMP_DATA & 0x00FF0000) >> 16;//Mask off bits 23-16 >> Shift by 16 to get into 7-0 index
		D_3 = (TEMP_DATA & 0x0000FF00) >> 8;//Mask off bits 15-8 >> Shift by 8 to get into 7-0 index
		D_4 = (TEMP_DATA & 0x000000FF);//Mask off bits 7-0 
        
		SENDUART1(D_4);
		SENDUART1(D_3);
		SENDUART1(D_2);
		SENDUART1(D_1);
	}
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

void DISPLAYDATA(struct DATA_PACKET DATA)
{
    SENDUART1(CHAR_X);
    SENDUART1(COLON);
    INTTOASCII((DATA.X1 << 8 | DATA.X0), 3);
    SENDUART1(CHAR_Y);
    SENDUART1(COLON);
    INTTOASCII((DATA.Y1 << 8 | DATA.Y0), 3);
    SENDUART1(CHAR_Z);
    SENDUART1(COLON);
    INTTOASCII((DATA.Z1 << 8| DATA.Z0), 3);
}