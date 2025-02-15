#include <stdint.h>


#define UART 0x10000000
#define UART_THR (uint8_t*)(UART+0x00)
#define UART_LSR (uint8_t*)(UART+0x05)
#define UART_LST_EMPTY_MASK 0x40

int lib_putc(char ch){
    while((*UART_LSR&UART_LST_EMPTY_MASK)==0);
    return *UART_THR=ch;
}

void lib_puts(char *s){
    while(*s) lib_putc(*s++);
}

int main(void){
    lib_puts("Hello OS!\n");
    return 0;
}

