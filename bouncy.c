/*
 * File:   bouncy.c
 * Author: philip
 *
 * Created on 10 March 2018, 17:36
 */


#include <xc.h>
#include <stdbool.h>
#include "config.h"


bool bouncy(void) 
{
    static bool previous_state;
    static bool current_state;
    if(DT == HI && current_state == OFF)                                // a
    {
        previous_state = OFF;
        current_state = OFF;
        return OFF;
    }
    if(DT == LO && current_state == OFF && previous_state == OFF)      // b
    {
        previous_state = OFF;
        current_state = ON;
        return ON;
    }
    if(DT == HI && current_state == ON && previous_state == OFF)                    // c
    {
        previous_state = ON;
        current_state = ON;
        return ON;
    }
    if(DT == LO && current_state == ON && previous_state == ON)       // d
    {
        previous_state = OFF;
        current_state = OFF;
        return OFF;
    }
}
