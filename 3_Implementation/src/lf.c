#define F_CPU 16000000UL
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif 
#include <avr/io.h>
#include<util/delay.h>
#include "pwm.h"

#define PERIOD   255

int set_duty_cycle(void)
{
    static int duty_change =127;
    static int wait;
    static int SWITCH1,SWITCH2;
    int key;
    key = 1;
    if(wait--)
    {
        wait=1000;
        if(key == SWITCH1) 
        {
            if(duty_change != PERIOD)
            {
                duty_change++ ;

         
            }
        }
      if(key == SWITCH2)
      {
          if(duty_change != 0)
          {
              duty_change--;

          }
      }

   }

return duty_change;
}

static int init_config(void)
{
    DDRD = DDRD | (1<< DDD7);
    //init_digital_keypad();
    init_pwm;

}
int main(void)
{
    unsigned char duty_cycle ;
    init_config();

    while(1)
    {
        duty_cycle = set_duty_cycle();
        pwm(duty_cycle);
        
#if 1
         PORTD = PORTD | (1<< PORTD7);
         _delay_ms(1000);
         PORTD = PORTD & ~(1<< PORTD7);
         _delay_ms(1000);
#endif
    }

}
