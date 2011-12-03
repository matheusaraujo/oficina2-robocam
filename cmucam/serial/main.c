#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <cc3.h>
	
#include "fnv.h"
	
int main (void) {

	// configure uarts
	cc3_uart_init (0,
		CC3_UART_RATE_9600,
        CC3_UART_MODE_8N1,
        CC3_UART_BINMODE_BINARY);

	// Make it so that stdout and stdin are not buffered
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
	
	char a[] = {'a', 'b', 'c', 'd', 'e'};

	for(int i = 0; i < 5; i++){
		printf("%c", a[i]);
		cc3_timer_wait_ms(2000);
	}


		
  return 0;

}
