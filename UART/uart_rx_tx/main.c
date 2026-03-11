#include "stm32f103xb.h"

void uart_init(void) {
    RCC->APB2ENR |= (1 << 2);  // GPIOA clock
    RCC->APB2ENR |= (1 << 14); // USART1 clock

    // PA9 TX
    GPIOA->CRH &= ~(0xF << 4);
    GPIOA->CRH |=  (0xB << 4); // AF push-pull
    // PA10 RX
    GPIOA->CRH &= ~(0xF << 8);
    GPIOA->CRH |=  (0x4 << 8); // Input floating

    USART1->BRR = 0x1D4C;       // 9600 baud @ 8MHz
    USART1->CR1 = (1<<13) | (1<<3) | (1<<2); // UE, TE, RE
}

char uart_receive_char(void) {
    while (!(USART1->SR & (1<<5))); // wait RXNE
    return USART1->DR;
}

void uart_send_char(char c) {
    while (!(USART1->SR & (1<<7))); // wait TXE
    USART1->DR = c;
}

int main(void) {
    uart_init();
    char received;

    while(1) {
        received = uart_receive_char();  // wait for char from PC
        uart_send_char(received);        // echo back
    }
}