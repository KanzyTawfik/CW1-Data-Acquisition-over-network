#include <avr/io.h>

void uart_SetBaudRate(int BRate){
  int ubrr = ((F_CPU)/(BRate*16UL)-1);  //function to change baudrate, = 103
  UBRR0H = (ubrr>>8);               //set the high baudrate
  UBRR0L = ubrr;                    //set the low baudrate
}

void uart_init(int BRate){
  uart_SetBaudRate(BRate); //run the previous BaudRate setup function
  UCSR0B |= (1<<TXEN0)|(1<<RXEN0);  //enable the transmitter and receiver
  UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);//set format to 8-bit
}

void uart_transmit(unsigned char data){
  int udr_empty; //initialize the udr empty boolean-like variable
  do{
    udr_empty = (UCSR0A & (1<<UDRE0)) != 0; //check the data buffer if empty or not
  }while(!udr_empty); //loop if data buffer is full

  UDR0 = data; //send the data to the data bus
}



void uart_transmit_array(char* data, int size){ //parameters are character array(string) and length of array to be able to loop on it
  for(int i = 0; i < size; i++){ //for loop
    while(!(UCSR0A & (1<<UDRE0))); //while loop to wait for the character to be received before sending another one
    UDR0 = (int) data[i]; //sending the character bit
  }
}

unsigned char uart_receive(void){
  if(!uart_receive_ready()){
    return;
  }else {
    return UDR0;
  } 
}

int uart_receive_ready(void){
  int flag = ((UCSR0A)&(1<<RXC0)) != 0; //checks the 7th bit of the register which means the received completed successfully
  return flag;
}

int ON1(const char *s1, const char *s2){
  char recieve_string[8] = "led_on";
    char str2[] = "led_on";
    int result = strcmp(recieve_string, str2);

    if (result == 0) {
        uart_transmit_array("LED turned on\n",14);//transmit to the serial monitor that the led turned on
          PORTB |= 0b00000001;
    
    } else {
        uart_transmit_array("Incorrect command\n",18);
    }

    return 0;

}

int OFF(const char *s1, const char *s2){
  char recieve_string[8] = "led_off";
    char str2[] = "led_off";
    int result = strcmp(recieve_string, str2);

    if (result == 0) {
        uart_transmit_array("LED turned off\n",15);//transmit to the serial monitor that the led turned off
          PORTB &= 0b11111110;
    
    } else {
        uart_transmit_array("Incorrect command\n",18);
    }

    return 0;

}

int str_length(char str[]) {
    // initializing count variable (stores the length of the string)
    int count; 
     for(int i = 0; i < strlen(str); i++) {  
        if(str[i] != ' ')  
            count++;  
    }  
    // returning the character count of the string
    return count; 
}

void printString(const char myString[]) {
  uint8_t i = 0;
  while (myString[i]) {
    transmitByte(myString[i]);
    i++;
  }
}

void transmitByte(uint8_t data) {
                                     /* Wait for empty transmit buffer */
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = data;                                            /* send data */
}



