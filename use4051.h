/*
  read4051.h - A small arduino library to interface with the CD 4051
  analog multiplexer.
  Jose Ricardo Monegro Quezada, 2018, josetecnom12@htomail.com
*/
#ifndef read4051_h
#define read4051_h

#include "Arduino.h"

class use4051{
  public:
    //Constructor for the class
    use4051(int A, int B, int C, int analogPin);
    //Reading metod
    int read4051(byte index);
    void write4051(byte index, int value);
  private:
    int _a;
    int _b;
    int _c;
    int _analogPin;
};

#endif
