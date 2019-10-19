Oct 19th 2019

I realised I didn't have the latest code (corresponding to the latest PCB sold by CODA). The led and relay was working by chance because some IO had the same pins, but the photofet wasn't being used...
Now it's fixed, but I totally erased the "flexiswitch" part, I still need to work on that.

//

Oct 10th 2019

The SW2 thing doesn't work, I "//ed" the code that doesn't work, I'll fix it later today.

//

Oct 9th 2019
# relaybypassflexi
FLEXI SWITCH MOD for Relay Bypass code for PIC12F675 used in Coda Effects pedals (www.coda-effects.com)

I modded the code so that the switch works like an Earthquaker Devices Flexi-switch.
That means that a short press will change the state, but a long press will change the state only when you press the switch.
That works both ways : if it's off it'll turn on only during the press and turn off again, and if it's on it'll turn off only during the press and turn back on afterwards, but you already got the idea, don't you ?)

I added the option to put a simple switch (latching spst, or anything you want to use as a on-off switch) and wire it to the "SW2" switch that's originally used as a momentary switch by Coda Effects.
I set it so that when this switch is off, or when no switch is plugged in, the switch will work like a flexi-switch, but when it's on you're back to a regular on-off footswitch

I only uploaded the source (in c) and header files since it's the only two you need to program a pic, ut the header is the same than in the original project.

You can modify the amount of time (250ms in the file I uploaded) between a short and a long push to you taste. To me that's perfect.

Feel free to tell me what you think and point out any mistakes I may have made !

Thanks a lot !

Mat
