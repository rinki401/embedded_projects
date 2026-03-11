#include "stm32f103xb.h"

void uart_init(void) {
    RCC->APB2ENR |= (1 << 2);  // GPIOA clock
    RCC->APB2ENR |= (1 << 14); // USART1 clock

    // PA9 as TX
    GPIOA->CRH &= ~(0xF << 4);
    GPIOA->CRH |=  (0xB << 4); // AF push-pull, 50MHz

    USART1->BRR = 0x1D4C;       // 9600 baud @ 8MHz
    USART1->CR1 = (1<<13) | (1<<3); // UE, TE
}

void uart_send_char(char c) {
    while (!(USART1->SR & (1<<7))); // wait TXE
    USART1->DR = c;
}

void uart_send_string(char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

int main(void) {
    uart_init();

    while(1) {
        uart_send_string("Hello STM32!\r\n");
        for(volatile int i=0;i<500000;i++); // delay
    }
}