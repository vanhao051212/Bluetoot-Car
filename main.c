/*
 * GccApplication1.cpp
 *
 * Created: 6/5/2018 11:01:33 AM
 * Author : asus
 */ 

#include <avr/io.h>
#define CPU_F 16000000UL
//#define BAUDRATE	9600
#include "function.h"
#include "USART_RS232_H_file.h"

int main(void)
{
	USART_Init(9600);
	INIT();
	char t;
	handle(0);
	while (1) 
    {
		t=USART_RxChar();
		switch (t)
		{
			case 'F': speed(100,100,100); handle(0); break;
			case 'B': speed(-100,-100,100); handle(0); break;
			case 'L': speed(100,50,50); handle(-100); break;
			case 'R': speed(50,100,50); handle(100); break;
			case 'G': speed(0,100,100); handle(-80); break;
			case 'I': speed(100,0,100); handle(80); break;
			case 'H': speed(0,-100,100); handle(-80); break;
			case 'J': speed(-100,0,100); handle(80); break;
			case 'S': speed(0,0,0); handle(0); break;
			default: break;
		}
    }
}

