/*
 * File:   interrupt isr.c
 * Author: philip
 *
 * Created on 07 February 2018, 20:25
 */


#include <xc.h>
#include "config.h"
#include "interrupt isr.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"
#include "bar_graph.h"
#include "bouncy.h"
#include "debounce_SWIP.h"
void interrupt isr(void) 
{
   // uchar col;
    uchar clear_port_a =LO;
    if(INTCONbits.INTF == HI)
    {
       if(CLK == HI && branston == 0)  // checks if mute is pressed, so any movement of encoder does not increase count
       {
           up_down = HI;
           count++;             // rot encoder is being turned clockwise
           
       }
       else
       {
           bounce = bouncy();
           //bounce = debounce_SWIP();
           if(bounce == LO)
           {
                up_down = LO;
                count--;             // rot encoder is being turned anti-clockwise
           }
       }
       if (count >= COUNT_MAX)
    {
        count = COUNT_MAX;
    }
    if(count <= COUNT_MIN)
    {
        count = COUNT_MIN;
    }
     
    PORTBbits.RB5 = ~PORTBbits.RB5;
    clear_port_a = PORTA;
    INTCONbits.INTF = LO;
    
    }
}
