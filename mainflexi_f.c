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
  TRISIO0 = 0; // NOTHING
  TRISIO1 = 1; // input footswtich
  TRISIO2 = 1; // input flexi toggle, no switch plugged on SW2 = flexi on
  TRISIO5 = 0; // output activation relay and led
  TRISIO4 = 0; // NOTHING
  TRISIO3 = 0; // output photofet

  GPIO = 0; // set outputs as low level (0V)

  // Variables definition
  uint8_t state; // on-off state of the pedal (1 = on, 0 = off)
  state = 0;
  
  uint8_t flexi; // define the mode of the pedal : classic of flexi activation
  flexi = 1;

  // Main loop
  while(1) {
        if(GP2 == 1) { // By default: flexi mode
        flexi = 1;
        }
        else { // If the "flexi" switch is turned off (meaning SW2 is closed and GP3/pin4 is connected to ground)
        flexi = 0;
        }
       if(GP1 == 0) { // footswitch pressed
         __delay_ms(15); // debouncing
         if(GP1 == 0) {
            // Changing state of the pedal
            if(state == 0) { // change to on
             GP3 = 1; // photoFET on
             __delay_ms(20);
             GP5 = 1; // relay and led on
            __delay_ms(20);
             GP3 = 0; // photoFET off
             state = 1;
            }
            else { // change to off
            GP3 = 1;
             __delay_ms(20);
             GP5 = 0; // relay and led off
             __delay_ms(20);
            GP3 = 0;
            state = 0;
            }
         __delay_ms(10);
            // To let the pedal in the good state (on or off)
            if (state == 1) { // effect on
            GP5 = 1; // relay and led on
            }
            else { // effect off
            GP5 = 0; // relay and led off
            }
        } 
    __delay_ms(250);// waiting (change that value if you're not happy with the short/long push setting)
    if (GP1 == 0) {//if switch is still pressed
      while (1) {//nothing happens
        if (GP1 == 1) {//until it's released
            break;//and then              
            }
        }
        // Changing state of the pedal again
        if(state == 0) { // change to on
        GP3 = 1; // photoFET on
        __delay_ms(20);
        GP5 = 1; // relay and led on
        __delay_ms(20);
        GP3 = 0; // photoFET off
        state = 1;
        }
        else { // change to off
        GP3 = 1;
        __delay_ms(20);
        GP5 = 0; // relay and led off
        __delay_ms(20);
        GP3 = 0;
        state = 0;
        }
      __delay_ms(10);

        // To let the pedal in the good state (on or off)
        if (state == 1) { // effect on
        GP5 = 1; // relay and led on
        }
        else { // effect off
        GP5 = 0; // relay and led off
        }   
      }
    }
   }
}
