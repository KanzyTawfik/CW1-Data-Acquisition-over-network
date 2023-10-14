#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "project.h"
#include "DIO.h"
#define BAUD 9600 //defining the BAUD rate globally





int main(void){
void DIO_init();
uart_init(BAUD); //initialize the BAUD
  void DIO_init();
  char button_on[15] = "Button Pressed\n";
  char ON1[] = "led_on";
  char OFF[] = "led_off";
  char receive_string[8];
  char Bitreceived;
  int count = 0;

  

 while(1){ //loop for running system

  if(uart_receive_ready()==1){//enter and store bit in variable then execute
   Bitreceived = uart_receive(); //store the received bit in a variable
   if(Bitreceived != '\n'){ 
       receive_string[count++] = Bitreceived; //place the received bit into the string in position (counter)
     }else{
       if( str_length("led_on") && strncmp(receive_string,ON1,6)==0 ){// compares the size of string and whether strings match
           printString("LED turned on\n");//transmit to the serial monitor that the led turned on
         PORTB |= 0b00000001;
          DIO_SetPinState('b',8,'1'); //turn on the digital pin 8 where the LED is 
       }
        else if( str_length("led_off") && strncmp(receive_string,OFF,7)==0){ //compares the size of string and whether strings match
          printString("LED turned off");//transmit to the serial monitor that the led turned off
         PORTB &= 0b11111110;
         DIO_SetPinState('b',8,'0');
       }else{
         printString("Incorrect command\n");
        }
        count = 0;
      }

  }
 
      
    
 
    DDRD &= ~_BV(DDD7);// Configure PD2 as an input using the Data Direction Register D (DDRD)

    // Enable the pull-up resistor on PD7 using the Port D Data Register (PORTD)
    PORTD |= _BV(PORTD7);

  
        // Read PD2 using the Port D Pin Input Register (PIND)
        if (PIND & _BV(PIND7))
        {
            // PD2 is high, so button is released

          
        }
        else
        {
            // PD2 is low, so button is pressed
          uart_transmit_array(button_on,15);
            
            
        }
    }

 }

 
  

  




