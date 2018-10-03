#define F_CPU 8000000 // Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <./avr/io.h>
#include <./util/delay.h>

void USART_Init( unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	}
void USART_Transmit( uint8_t data ){
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}
int main(void) {
    uint8_t character;
    uint8_t receivedchars[50] = 0;
    uint8_t charcounter=0;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	USART_Init(MYUBRR);
    while (1) {
    	charcounter=0;
    	do{
		    while ( !(UCSR0A & (1<<RXC0)) );
		        character = UDR0;
		    receivedchars[charcounter] = character;
		    charcounter++;
        }while(character != 0x0D);
        //set PWM0 receivedchars[charcounter-2]
        //set PWM1 receivedchars[charcounter-3]
        //set PWM2 receivedchars[charcounter-4]
        charcount-=4;
        receivedchars[charcounter] = 0x0D;
        receivedchars[0] = receivedchars[0]-1;
        for(int i=0;i<charcounter;i++){
        	USART_Transmit(receivedchars[i]);
        }
    }
    return 0;
}



























