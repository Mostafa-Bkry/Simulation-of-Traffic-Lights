/*
 * File:   main.c
 * Author: acer
 *
 * Created on November 18, 2021, 12:59 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    unsigned char seg_arr[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
    
    TRISB = 0;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    
    while(1) {
        for(int i = 0; i < 10; i++) {
            PORTC = seg_arr[i];
            
            RD0 = 1;
            if(i == 5) RD1 = 1;
            
            for(int j = 0; j < 10; j++) {
                PORTB = seg_arr[j];
                __delay_ms(1000);
            
                if(i == 9 && j == 9){
                    RD0 = 0;
                    RD1 = 0;
                    RD2 = 1;
                }
            }
        }
        __delay_ms(10000);
        RD2 = 0;
    }
    return;
}
