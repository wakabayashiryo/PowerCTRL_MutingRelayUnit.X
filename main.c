/*
 * File:   main.c
 * Author: evaota
 *
 * Created on 2018/04/14, 12:31
 */

#include "main.h"

#define _DETECT_TIME 100

uint8_t standby = 1;

void main(void)
{
    bool stat;
    
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
        stat = (bool)(Switch_GetTime()>_DETECT_TIME);
        
        if(stat&&!SSR)
        {   
            SSR = 1;
            standby = 0;
            
            __delay_ms(2000);
            
            RELAY1 = RELAY2 = 1;
            
        }
        else if(stat&&SSR)
        {
            RELAY1 = RELAY2 = 0;
            
            __delay_ms(1000);
            
            SSR = 0;
            standby = 1;
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
    static uint16_t count = 0;
    
    if((++count>1000)&&standby)
    {
        count = 0;
        LEDinSW = !LEDinSW;
    }
    else if(standby==0)
    {
        LEDinSW = 0;
    }
    if(TMR1IF&&TMR1IE)
    {
        TMR1 = 0xFFFF-1000;

        Switch_CountHIGH();
        
        TMR1IF = 0;
    }
}