#include "stm32f103xb.h"

void gpio_init(void) {
    RCC->APB2ENR |= (1<<2);   // GPIOA clock
    GPIOA->CRL &= ~(0xF << 20);
    GPIOA->CRL |=  (0x1 << 20); // PA5 output push-pull
}

void timer2_init(void) {
    RCC->APB1ENR |= (1<<0);   // TIM2 clock
    TIM2->PSC = 7999;         // Prescaler
    TIM2->ARR = 999;          // 1s delay
    TIM2->DIER |= (1<<0);     // Update interrupt enable
    TIM2->CR1 |= (1<<0);      // Counter enable

    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void) {
    if(TIM2->SR & (1<<0)) {   // Check update interrupt
        TIM2->SR &= ~(1<<0);  // Clear flag
        GPIOA->ODR ^= (1<<5); // Toggle LED
    }
}

int main(void) {
    gpio_init();
    timer2_init();

    while(1) {
        // main loop free
    }
}