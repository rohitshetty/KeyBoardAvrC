KeyBoardAvrC
============

Talking keyboard ,RHOK
This is source code for Talking keyboard. 

library , lcd.c and lcd.h is under opensource license and can be found at <pre> http://homepage.hispeed.ch/peterfleury/avr-software.html#libs </pre> and i claim no ownership for lcd.c and lcd.h

uart_lib.c is an uart lib created by me and can be used under GNU GPL V2

Design connected to atmega is pretty simple (Schematic will be released soon)
An lcd is connected to port c(more detail in lcd.c,lcd.h about pinconfig) .ps2 connecters are connected as follow

Clock line >>> PB2 <p>
data line >>>PD2 <p>
Vcc to 5V <p>
gnd to gnd <p>
 take note for keyboard to work it needs clock of 8MHz at microcontroller
code is for 12MHz
For connecting Bluetooth.
connect HC05 module as Standard procedure.(using uart)
Schematics doesnt show the regular set up of Crystals and power. It is assumed to be self explanatory if any issues you can always reach me at 
<pre> rohitfoss00@gmail.com </pre>



(schematics <pre> http://postimg.org/image/dnjcomi0z/ </pre>
more data about ps2 protocols and pinout config for your connector is found at <pre> http://www.computer-engineering.org/ps2protocol/ </pre>

)
Notes:
in final product lcd will NOT be the part

Things left to be done: <p>
1 to add all keys response, as of now only single stroke work <p>
2 tweak and make code the goddamn code efficient to overcome 500-1000 millisec delay <p>
3 create a separate app for this as of now we are using blueterm from playstore(That has been modified) <p>
4 Provide and opensource the schematic asap <p>

