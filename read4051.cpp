#include "Arduino.h"
#include "read4051.h"

read4051::read4051(int A, int B, int C, int analogPin){
  _a = A;
  _b = B;
  _c = C;
  _analogPin = analogPin;
}
int read4051::getValue4051(byte index){
  //Put all the pin numbers into an array
  int pins[] = {_a, _b, _c};
  //Just to make sure no index values are bigger than 7
  /* I.e:
   * 00110101 (Ramdom data)
   * 00000111 (0x07)
   * --------
   * 00000101 (Last 3 bits of data)
  */
  index &= 0x07;
  /*Shift index's bits i bits to the right and then
    check if the least important bit is either on or off*/
  for(int i=0; i<3;i++){
    if((index >> i) & 0x01){
      //If it is on, turn the pin(pins[i]) on 
      digitalWrite(pins[i], HIGH);
    }
    else{
      //If it is off, turn the pin(pins[i]) off
      digitalWrite(pins[i], LOW);
    }
  }
  //Return the value of pin(analogPin)
  return(analogRead(_analogPin));
}
