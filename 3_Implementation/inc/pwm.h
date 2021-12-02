#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>

void init_pwm(void)
{
    DDRD = DDRD | (1<< DDD6);

    TCCR0A =TCCR0A | (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
    
    TCCR0B = TCCR0B | (1 << CS00);

}
void pwm(unsigned char duty)
{
    OCR0A = duty;

}