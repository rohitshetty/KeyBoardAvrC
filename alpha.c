#define F_CPU 12000000UL
#define BAUD 9600 
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include <stdlib.h>
#include "lcd.c"
#include "kbd.c"
#include "uart_lib.c"
volatile int count=0;
volatile int sent=0;
volatile int data=0x00;
volatile int current_buff[3];
volatile int buffer=0x00;
volatile int flag=00;
volatile char c[50];
volatile char cs;
volatile char string[50];
void main(){
char s;
UART_init();
lcd_init(LCD_DISP_ON);
lcd_clrscr();
//lcd_putc('c');
cli();
DDRD&=~(1<<PD2);
PORTD|=(1<<PD2);
DDRB&=~(1<<PB2);
 MCUCSR &= ~(1<<ISC2);      // falling-edge interrupt on INT2 
   GICR |=(1<<INT2) ;
sei();

while(1)
{


if(flag==1)
{lcd_clrscr();
uart_send(string[strlen(string)-1]);
flag=0;

lcd_puts(string);


}
}


}
ISR(INT2_vect)
{


count++;

if(count>=2 && count<10)
{
data = (data >> 1); // LSB first  
if(PIND & (1<<PD2)){

{data = data | 0x80; }
}

}
 if(count >=33){
itoa(data,c,16);


decode(&string[strlen(string)-1],data);
/*
if(1){

switch(cs){
case '\r':
if(strlen(string)-1>=0)
string[strlen(string)-1]=127;
break;
default:
string[strlen(string)]=cs;

break;







}} 
*/
count=0;
 data=0;
flag=1;
sent=1;
}

//lcd_clrscr();


}
