KeyBoardAvrC
============

Talking keyboard ,RHOK
This is source code for Talking keyboard. 

library , lcd.c and lcd.h is under opensource license and can be found at <pre> http://homepage.hispeed.ch/peterfleury/avr-software.html#libs </pre> and i claim no ownership for lcd.c and lcd.h

uart_lib.c is an uart lib created by me and can be used under GNU GPL V2

Design connected to atmega is pretty simple (Schematic will be released soon)
An lcd is connected to port c(more detail in lcd.c,lcd.h about pinconfig) .ps2 connecters are connected as follow

Clock line >>> PB2
data line >>>PD2
Vcc to 5V
gnd to gnd
 take note for keyboard to work it needs clock of 8MHz at microcontroller
code is for 12MHz
For connecting Bluetooth.
connect HC05 module as Standard procedure.(using uart)

Notes:
in final product lcd will NOT be the part

Things left to be done:
1 to add all keys response, as of now only single stroke work
2 tweak and make code the goddamn code efficient to overcome 500-1000 millisec delay
3 create a separate app for this as of now we are using blueterm from playstore(That has been modified)
4 Provide and opensource the schematic asap
