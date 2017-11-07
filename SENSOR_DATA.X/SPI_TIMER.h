/* 
 * File:   SPI_TIMER.h
 * Author: Adoney
 *
 * Created on October 14, 2017, 12:17 AM
 */

#ifndef SPI_TIMER_H
#define	SPI_TIMER_H
#include <plib.h>
#include <sys/attribs.h>

int TIMER_FLAG = 1;

void SPI_TIMER()
{

    INTCONSET = 1 << 12;
    //Turn off timer 1
	//TICON<15> = 0
	T1CONCLR = 1 << 15;
    //Select parent clock
	//T1CON<1> = 0, internal peripheral clock
	T1CONCLR = 1 << 1;
    //Set prescalar value 
	//T1CON<5:4> = 0b01 1:256
    T1CONSET = 3 << 4;
	//Set the TMR1 to zero
	TMR1 = 0;

	//Set the period register 
	//Peripheral Clock is running at 40MHz, Prescalar 8, Timer Running at 5000000
	PR1 = 40;// Pr value is set depending on the amount of time desired 


	//Setup Timer 1 interrupt
    //Disable timer 1 interrupt
	//IEC0<4> = 0
	IEC0CLR = 1 << 4;

	//Set interrupt priority
	//IPC1<4:2> = 0b110
	IPC1SET  = 6 << 2;

	//Enable timer 1 interrupt
	//IEC0<4> = 0
	IEC0SET = 1 << 4;
}

void DELAY(int x, int TIMER_FLAG)
{
    int i = 0;
    
	//Set the period
    PR1 = x;
    //Turn off timer 1
	//TICON<15> = 0
    T1CONSET = 1 << 15;
    while(TIMER_FLAG)
    {
       i = i + 1; 
    }
           
}

void __ISR(_TIMER_1_IRQ, ipl2) TIMER1HANDLER(void)
{
    T1CONCLR = 1 << 15;
    IFS0CLR = 1 << 4;
    TIMER_FLAG = 0;
}
#endif	/* SPI_TIMER_H */

