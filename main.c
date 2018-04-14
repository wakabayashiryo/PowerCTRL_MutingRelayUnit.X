/*
 * File:   main.c
 * Author: evaota
 *
 * Created on 2018/04/14, 12:31
 */

#include "main.h"

uint16_t sw_time;

void Swich_CountHIGH(void);
uint16_t Switch_ReadTime(void);

void main(void)
{
    Basic_Init();

    T1CON = 0x00;

    TMR1 = 0xFFFF-1000;

    TMR1ON = 1;

    TMR1IE = 1;
    TMR1IF = 0;

    PEIE = 1;
    GIE = 1;
  
    while(1)
    {
        if(Switch_ReadTime()>1000)
        {           
            GP4 = GP5 ^= 1; 
        }
    }
}

void Basic_Init(void)
{
    TRISIO = 0x01;
    CMCON = 0x07;   //comparator pin connect to GND ,digital pin can use digital
    ANSEL = 0x00;   //set mode to digital.because default pin mode is analog
    WPU = 0x00;
    IOC = 0x00;

    GPIO = 0x00;
}

void interrupt Handler(void)
{
    if(TMR1IF&&TMR1IE)
    {
        TMR1 = 0xFFFF-1000;
        
        Swich_CountHIGH();
        
        TMR1IF = 0;
    }
}

void Swich_CountHIGH(void)
{
    static uint16_t count = 0;
    
    if(!GP0)
    {
        count++;
    }
    else
    {
        sw_time = count;
        count = 0;
    }
}

uint16_t Switch_ReadTime(void)
{
    uint16_t store_time = sw_time;

    sw_time = 0;
    
    return store_time;
}