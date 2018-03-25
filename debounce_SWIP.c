/*
 * File:   debounce_SWIP.c
 * Author: philip
 *
 * Created on 28 February 2018, 18:54
 */


#include <xc.h>
#include "config.h"
#include <stdbool.h>
#include "debounce_SWIP.h"



bool debounce_SWIP(void) 
{
    static bool previous_state;
    static bool current_state;
    if(DT == HI && current_state == OFF)                          //a
    {
        previous_state = OFF;
        current_state = OFF;
        return OFF;
    }
    if(DT == LO && previous_state == OFF && current_state == OFF)  //b
    {
        previous_state = OFF;
        current_state = BOUNCE_ON;
        return OFF;
    }
    if(DT == HI && previous_state == OFF && current_state == BOUNCE_ON) //c
    {
        previous_state = BOUNCE_ON;
        current_state = OFF;
        return OFF;
    }
    if(DT == LO && previous_state == OFF && current_state == BOUNCE_ON) //d
    {
        previous_state = BOUNCE_ON;
        current_state = ON;
        return ON;
    }
    if(DT == HI && previous_state == BOUNCE_ON && current_state == ON) //e
    {
        previous_state = ON;
        current_state = BOUNCE_OFF;
        return OFF;
    }
    if(DT == LO && previous_state == ON && current_state == BOUNCE_OFF) //f
    {
        previous_state = BOUNCE_OFF;
        current_state = ON;
        return ON;
    }
    if(DT == HI && previous_state == ON  && current_state == BOUNCE_OFF) //g
    {
        previous_state = BOUNCE_OFF;
        current_state = OFF;
        return OFF;
    }
    
}