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
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	USART_Init(MYUBRR);

    while (1) {
        while ( !(UCSR0A & (1<<RXC0)) );
            character = UDR0;
        USART_Transmit(character);
        
    }
    return 0;
}



























