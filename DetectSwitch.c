/*
 * File:   DetectSwitch.c
 * Author: evaota
 *
 * Created on 2018/04/14, 17:34
 */
#include "DetectSwirch.h"

static uint16_t time_save;

void Switch_CountHIGH(void)
{
    static uint16_t count_ms = 0;
    
    if(!SW)
    {
        count_ms++;
    }
    else
    {
        time_save = count_ms;
        count_ms = 0;
    }
}

uint16_t Switch_GetTime(void)
{
    uint16_t time_temp = time_save;

    time_save = 0;
    
    return time_temp;
}
