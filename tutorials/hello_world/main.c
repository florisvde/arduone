// halloworld.c
// Writing a string to the serial port without
// the use of <stdio.h> standard package.
// We will see that including <stdio.h> and
// definig a "int putchar(int c)" function dealing
// with the serial port the use of standard printf
// with its C stantard formatting is possible.
//
// Francesco Fontana
// 22/12/2019
// Initialize serial a 19200 1 stop bit @ 11.0592 MHz

#include <8051.h>

void initSio() {
  TMOD &= 0x0F;
  TMOD |= 0x20;
  TCON = 0x41;
  TH1 = 0xFD;
  SCON = 0x50;
}

// Send a single char to serial port
void sendChar(char c) {
  SBUF = c;
  while (!TI);
  TI = 0;
}

// Write a complete string
void sendChars(char *sz) {
  while(*sz) sendChar(*sz++);
}

void main(void) {
initSio();
sendChars("Hello, Floris 1!");
while(1);
}
