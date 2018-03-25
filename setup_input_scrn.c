/*
 * File:   setup_input_scrn.c
 * Author: philip
 *
 * Created on 18 February 2018, 18:58
 */


#include <xc.h>
#include "config.h"
#include "write_character.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"
#include "setup_input_scrn.h"
    
void setup_input_scrn (void) 
{
    uchar col;
    write_character(&I[0],0x00,0xb0);  //do this
    write_character(&n[0],0x0f, 0xb0); 
    write_character(&p[0],0x1f, 0xb0);
    write_character(&u[0],0x2f,0xb0);  
    write_character(&t[0],0x3f,0xb0);
    write_character(&space[0],0x4f,0xb0);
    write_character(&uno[0],0x5f,0xb0);
    return;
}
