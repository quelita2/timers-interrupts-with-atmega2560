#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){              
  DDRG = 0b00100000;
  TCCR0A = 0b00000000;
  TCCR0B = 0b00000001;
  TIMSK0 = 0b00000001;
  sei(); 
  
  while(1){ }
  
  return 0;
}

ISR(TIMER0_OVF_vect){
  if(PING & 0b00100000){
    PORTG = 0b00000000;
  }else{
    PORTG = 0b00100000;
  }
}