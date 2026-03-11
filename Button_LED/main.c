#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)

#define GPIOC_CRH   (*(volatile unsigned int*)0x40011004)
#define GPIOC_IDR   (*(volatile unsigned int*)0x40011008)
#define GPIOC_ODR   (*(volatile unsigned int*)0x4001100C)

#define GPIOA_CRL   (*(volatile unsigned int*)0x40010800)
#define GPIOA_IDR   (*(volatile unsigned int*)0x40010808)

int main()
{
    RCC_APB2ENR |= (1<<2);  // GPIOA clock
    RCC_APB2ENR |= (1<<4);  // GPIOC clock

    GPIOC_CRH &= ~(0xF<<20);
    GPIOC_CRH |=  (0x1<<20);   // PC13 output

    GPIOA_CRL &= ~(0xF<<0);    // PA0 input

    while(1)
    {
        if(GPIOA_IDR & (1<<0))
        {
            GPIOC_ODR ^= (1<<13);
            for(int i=0;i<500000;i++);
        }
    }
}