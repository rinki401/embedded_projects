# STM32 Button Controlled LED (Bare Metal)

## Microcontroller
STM32F103C8T6 (Blue Pill)

## Language
Embedded C

## Programming Method
Direct Register Programming (Bare Metal)

## Description
This project demonstrates how to control an LED using a push button without using any HAL or external libraries.

When the button connected to PA0 is pressed, the LED connected to PC13 toggles its state.

## Hardware Used
- STM32F103C8T6 (Blue Pill board)
- Push Button connected to PA0
- LED connected to PC13

## Working Principle

1. Enable clock for GPIOA and GPIOC using RCC register.
2. Configure PC13 as output pin.
3. Configure PA0 as input pin.
4. Continuously read the button state from GPIOA_IDR register.
5. If button is pressed, toggle LED using GPIOC_ODR register.

## Registers Used

RCC_APB2ENR → Enable GPIO clock  
GPIOC_CRH → Configure PC13 mode  
GPIOC_ODR → Control LED state  
GPIOA_CRL → Configure PA0 input  
GPIOA_IDR → Read button state  

## File Structure


## Output

Press Button → LED toggles ON/OFF