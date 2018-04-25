/*
  read4051.h - A small arduino library to interface with the CD 4051
  analog multiplexer.
  Jose Ricardo Monegro Quezada, 2018, josetecnom12@htomail.com
*/
#ifndef read4051_h
#define read4051_h

#include "Arduino.h"

class read4051{
  public:
    //Constructor for the class 
    read4051(int A, int B, int C, int analogPin);
    //Reading metod
    int getValue4051(byte index);
  private:
    int _a;
    int _b;
    int _c;
    int _analogPin;
};

#endif
