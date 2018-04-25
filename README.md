# read4051
An arduino library for the CD4051 analog multiplexer
## Usage 
First create an object for the library with the parameters required (Address pins (S0, S1, S2), and the analogPin that will read the analog data coming of the chip).


### I.e:
  ```
  #include "read4051.h"
  #define addrPin0
  #define addrPin1
  #define addrPin2
  #define analogPin 0
  
  read4051 sensors(addrPin0, addrPin1, addrPin2, analogPin);
```

Then you just need to call the getValue4051(byte index) function as a variable value (type int) whenever you need to. Remenber to include the address you want to read (which shuldn't be higher than 7). 

### I.e:
  ```
  for(byte i =1; i <8; i++){
    Serial.println(sensors.getValue4051(i));
    delay(500);
  }
  ```
