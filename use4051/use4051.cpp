#include "Arduino.h"
#include "use4051.h"

use4051::use4051(int A, int B, int C, int analogPin){
  _a = A;
  _b = B;
  _c = C;
  _analogPin = analogPin;
}
int use4051::read4051(byte index){
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
void use4051::write4051(byte index, int value,  int optional_pin = -1){
  //The same thing as adove, but instead it uses PWM to
  //write an analog value to the chip
  int pins[] = {_a, _b, _c};
  index &= 0x07;
  for(int i=0; i<3;i++){
    if((index >> i) & 0x01){
      digitalWrite(pins[i], HIGH);
    }
    else{
      digitalWrite(pins[i], LOW);
    }
  }
  if(optional_pin > -1){
    analogWrite(optional_pin, value);
  }
  else{
      analogWrite(_analogPin, value);
  }
}
