/* 
 * File:   relayonpress.c
 * Author: Benoit
 *
 * Created on 5/02/2017
 */
//modded by Mat on Oct 7th 2019
// "flexi switch with toggle" version

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include "header.h"

// Initialization
void main(void) {
  ANSEL = 0; // no analog GPIOs
  CMCON = 0x07; // comparator off
  ADCON0 = 0; // Analog to Digital and Digital to Analog convertors off
  TRISIO0 = 0; // output LED
  TRISIO1 = 1; // input footswtich
  TRISIO2 = 0; // output photofet
  TRISIO5 = 0; // output activation relay
  TRISIO4 = 0; // output ground relay
  TRISIO3 = 1; // input flexi toggle, no switch plugged on SW2 = flexi on

  GPIO = 0; // set outputs as low level (0V)

  // Variables definition
  uint8_t state; // on-off state of the pedal (1 = on, 0 = off)
  state = 0;

  // Main loop
  while(1) {
       if(GP1 == 0) { // footswitch pressed
         __delay_ms(15); // debouncing
         if(GP1 == 0) {
            // Changing state of the pedal
            if(state == 0) { // change to on
             GP2 = 1; // photoFET on
             __delay_ms(20);
             GP0 = 1; // LED on
             GP5 = 1; // relay on
             GP4 = 0;
            __delay_ms(20);
             GP2 = 0; // photoFET off
             state = 1;
            }
            else { // change to off
            GP2 = 1;
             __delay_ms(20);
             GP0 = 0; // LED off
             GP5 = 0; // relay off
            GP4 = 0;
             __delay_ms(20);
            GP2 = 0;
            state = 0;
            }
         __delay_ms(10);
            // To let the pedal in the good state (on or off)
            if (state == 1) { // effect on
             GP0 = 1; // LED on
            GP5 = 1; // relay on
            GP4 = 0;
            }
            else { // effect off
            GP0 = 0; // LED off
            GP5 = 0; // relay off
            GP4 = 0;
            }
        } 
    if (GP3 == 1) { //if flexitoggle on or if there's no switch on SW2
    __delay_ms(250);// waiting (change that value if you're not happy with the short/long push setting)
    if (GP1 == 0) {//if switch is still pressed
      while (1) {//nothing happens
        if (GP1 == 1) {//until it's released
            break;//and then              
            }
        }
        // Changing state of the pedal again
        if(state == 0) { // change to on
        GP2 = 1; // photoFET on
        __delay_ms(20);
        GP0 = 1; // LED on
        GP5 = 1; // relay on
        GP4 = 0;
        __delay_ms(20);
        GP2 = 0; // photoFET off
        state = 1;
        }
        else { // change to off
        GP2 = 1;
        __delay_ms(20);
        GP0 = 0; // LED off
        GP5 = 0; // relay off
        GP4 = 0;
        __delay_ms(20);
        GP2 = 0;
        state = 0;
        }
      __delay_ms(10);

        // To let the pedal in the good state (on or off)
        if (state == 1) { // effect on
        GP0 = 1; // LED on
        GP5 = 1; // relay on
        GP4 = 0;
        }
        else { // effect off
        GP0 = 0; // LED off
        GP5 = 0; // relay off
        GP4 = 0;
        }   
      }
    }
   }
  }
}