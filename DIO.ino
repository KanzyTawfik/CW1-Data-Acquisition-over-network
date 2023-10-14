
void DIO_init(){
  DIO_SetPinDirection('b',0,'o'); //setting pb0 output D8
  DIO_SetPinDirection('d',7,'i'); //setting pd7 input D7

}




void DIO_SetPinDirection(unsigned char port, int pin, unsigned char direction){
  if (port=='b' & pin<=7 & pin>=0){
    if(direction =='o'){
      DDRB = DDRB|(1<<pin); //bit set to 1 for output
  }else if (direction == 'i'){
    DDRB = DDRB&!(1<<pin); // bit cleared for 0 INPUT
  }
}
 
 if (port=='d' & pin<=8 & pin>=0){
    if(direction =='o'){
      DDRD = DDRD|(1<<pin); //bit set to 1 for output
  }else if (direction == 'i'){
    DDRD = DDRD&!(1<<pin); // bit cleared for 0 input
  }
}
}


void DIO_SetPinState(unsigned char port, int pin, unsigned char state){
  if (port=='b' & pin<=7 & pin>=0){
    if(state =='1'){
      PORTB = PORTB|(1<<pin); // pin is set to 1 for high
    } else if (state =='0');{
      PORTB &= ~(1<<pin); //pin is cleared to 0 for low
    }
} 


 if (port=='d' & pin<=7 & pin>=0){
    if(state =='1'){
      PORTD = PORTD|(1<<pin); // pin is set to 1 for high
    } else if (state =='0');{
      PORTD &= ~(1<<pin); //pin is cleared to 0 for low
    }
 }
} 

