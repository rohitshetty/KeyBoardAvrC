/*
USe this as ur ISR copy
ISR(USART_RXC_vect)
{
char s;
while (!( UCSRA & (1<<UDRE)));
s=UDR;
//Do your stuff here


}
*/
#define BAUDRATE (((F_CPU) + 8UL * (BAUD)) / (16UL * (BAUD)) -1UL) 


void UART_init(){
unsigned int baudrate;
/*
serial communication specifications
Async (UART)
8 bit data frame
1 stop bit
no parity
*/

baudrate=BAUDRATE ;
UBRRH=(unsigned char)(baudrate>>8);
UBRRL=(unsigned char) baudrate;



UCSRB|=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);

UCSRA&=~(1<<U2X);  // U2X  set to 0 signifies async communication


UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);




/*
data bit frame set to 8 bit
UCSZx are used to change it
*/
UCSRC&=~((1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<URSEL));
sei();
}

void uart_send(unsigned char c)
{
    while (!( UCSRA & (1<<UDRE)));  
             // wait while register is free
    UDR = (unsigned char) c;  
}


