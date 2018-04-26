# use4051
An arduino library for the CD4051 analog multiplexer
## Usage
First create an object for the library with the parameters required (Address pins (S0, S1, S2), and the analogPin that will read the analog data coming of the chip).


  ```
  #include "read4051.h"
  #define addrPin0
  #define addrPin1
  #define addrPin2
  #define analogPin 0

  read4051 sensors(addrPin0, addrPin1, addrPin2, analogPin);
```

Then you just need to call the read4051(byte index) function as a variable value (type int) whenever you need to. Remenber to include the address you want to read (which shuldn't be higher than 7).


  ```
  for(byte i =1; i <8; i++){
    Serial.println(sensors.read4051(i));
    delay(500);
  }
```
Or you can call the void write4051(byte index, int value, int optional_pin = -1) function to write values instead/


```
for(byte i =1; i <8; i++){
  sensors.write4051(i, i * 10);
  delay(500);
}
```
