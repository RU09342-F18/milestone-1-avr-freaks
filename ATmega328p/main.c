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
void Timer_Init(){
	TCCR0A = (1<<COM0A1)|(1<<COM0B1)|(1<<WGM01)|(1<<WGM00);//set fast pwm, pwm outputs
	TCCR0B = (1<<CS01)|(1<<CS00);//enable timer and set clock to IOclk/64
	TCCR2A = (1<<COM2B1)|(1<<WGM21)|(1<<WGM20);//set fast pwm, output pwm on channel a
	TCCR2B = (1<<CS22);//set clock divider
	OCR0A = 255;
	OCR0B = 255;
	OCR2B = 255;
}
int main(void) {
    volatile uint8_t character;
    uint8_t receivedchars[50];//16 nodes
    uint8_t charcounter=0;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	USART_Init(MYUBRR);
	Timer_Init();
    while (1) {
    	charcounter=0;
    	do{
		    while ( !(UCSR0A & (1<<RXC0)) );
		    character = UDR0;
		    receivedchars[charcounter] = character;
		    //USART_Transmit(receivedchars[charcounter]);
		    if(character == 0x7f){
        		USART_Transmit(receivedchars[charcounter]);
		    	charcounter--;//backspace
		    }else
		    	charcounter++;
		    
        }while(character != 0x0D);
        if(charcounter >= 0){
		    OCR0A = 255-receivedchars[1];
		    OCR0B = 255-receivedchars[2];
		    OCR2B = 255-receivedchars[3];
		    
		    charcounter = 4;	
        	USART_Transmit(receivedchars[0]-3);
        	while(receivedchars[charcounter] != 0x0D){
        		USART_Transmit(receivedchars[charcounter]);
        		charcounter++;
        }
        }


    }
    return 0;
}



























