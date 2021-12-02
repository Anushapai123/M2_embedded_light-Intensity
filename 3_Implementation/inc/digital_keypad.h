#include "digital_keypad.h"


Static void init_config(void)
{
    DDRB = DDRB |(1 << DDB1);
    DDRB = DDRB |(1 << DDB0);


    init_ext_interrupt(0, F_EDGE);
//enable global interupt
    sei();

}

int main(void)
{

    int flag;
    unsigned char key ;
    init_config();

    while(1)
    {
        if(flag == 1)
        {
            PORTB = PORTB ^ (1 << PORTB1);
            flag = 0;

        }
    PORTB = PORTB | (1 << PORTB0);
         _delay_ms(1000);
         PORTB = PORTB & ~(1 << PORTB0);
         _delay_ms(1000);
    }
}

ISR(INT0_vect)
{
    flag = 0;

}
int init_ext_interrupt(unsigned char int_number, unsigned char sense_type )
{
    ASSERT(int_number);


    DDRD = DDRD & ~(1 <<(int_number +2));

    EICRA = EICRA | (sense_type << (1 << int_number) );

    EIMSK = EIMSK | (1 << int_number);

}