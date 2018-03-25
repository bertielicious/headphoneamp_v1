/*
 * File:   op_mode.c
 * Author: philip
 * finite state machine to handle switching mode from 
 * volume to mute and back to volume
 * Created on 05 March 2018, 18:57
 */


#include <xc.h>
#include <stdbool.h>
#include "op_mode.h"
#include "config.h"
#include "mute.h"
bool op_mode(void) 
{
    if(SWIP == 1 && current_state == VOL)                           // a
    {
        previous_state = VOL;
        current_state = VOL;
        INTCONbits.GIE = 1;
        return VOL;
    }
    if(SWIP == 0 && current_state == VOL && previous_state == VOL)  // b
    {
        previous_state = VOL;
        current_state = MUTE;
        INTCONbits.GIE = 0;         // prevent change of volume when product is muted
        //TRISAbits.TRISA2 = 0;
        
        return MUTE;
    }
     if(SWIP == 1 && current_state == MUTE && previous_state == VOL) // c
    {
        previous_state = MUTE;
        current_state = MUTE;
        INTCONbits.GIE = 0;
       // TRISAbits.TRISA2 = 0;
        //count = count + 1;
        return MUTE;
    }
    if(SWIP == 0 && current_state == MUTE && previous_state == MUTE) // d
    {
        previous_state == MUTE;
        current_state = VOL;
        INTCONbits.GIE = 1;
        //TRISAbits.TRISA2 = 1;
        return VOL;
    }
}
    