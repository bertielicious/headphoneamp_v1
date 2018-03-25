/*
 * File:   main.c
 * Author: philip
 *
 * Created on 02 February 2018, 17:49
 */


#include <xc.h>
#include "config.h"
#include "main.h"
#include "init_ports.h"
#include "oled_startup.h"
#include "config_oled.h"
#include "clear_oled.h"
#include "ioc_enable.h"
#include "interrupt isr.h"
#include "write_character.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"
#include "split_digits.h"
#include "get_digit.h"
#include "bar_graph.h"
#include "setup_vol_scrn.h"
#include "setup_input_scrn.h"
#include "splash_screen.h"
#include "set_page_address.h"
#include "debounce_SWIP.h"
#include "bouncy.h"
#include "mute.h"
#include "op_mode.h"

void main (void)
{
    init_ports();
    ioc_enable();
    config_oled();
    clear_oled();
    splash_screen();
    RC4 = 1;
    RC3 = 1;
    RC6 = 1;
    RB7 = 1;
    __delay_ms(2000);
    RC4 = 0;
    RC3 = 0;
    RC6 = 0;
    RB7 = 0;
    clear_oled();
    setup_vol_scrn();
    //bool branston;// = VOL;
    bool spikey;
     while(1)
    {   
         spikey = bouncy();
         //spikey = debounce_SWIP();
         if(spikey == LO)
         {
             GREEN_LED = LO;
         }
         if(spikey == HI)
         {
             GREEN_LED = HI;
         }
         
         branston = op_mode();
         if (branston == 0 )
         {
                bar_graph();
                split_digits();
                if(count >=0 && count <95)
                {
                    write_character(&minus[0], 0x0f,0xb3);
                }
            else
                {
                    write_character(&space[0],0x0f,0xb3);
                }   
            get_digit(tens, 0x1f);
            get_digit(units, 0x2f); 
            write_character(&d[0],0x3f,0xb3);
            write_character(&B[0],0x4f,0xb3);
         }
         if (branston == 1)
         {
             if(count >=0 && count <95)
                {
                    write_character(&space[0],0x0f,0xb3);
                }
             mute();
         }
                
    }  
}
    

    





