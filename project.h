//function declarations

void uart_SetBaudRate(int BRate);
void uart_init(int BRate);
void uart_transmit(char* data);
unsigned char uart_receive(void);
int uart_receive_ready(void);
void uart_transmit_array(char* data, int size);
int str_length(char str[]);
void printString(const char myString[]);
void transmitByte(uint8_t data);

