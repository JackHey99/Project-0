# Project 0
Jack Heyward ID#2174132

## Introduction
The aim of this project is to design an embedded system that can measure a person's subjective flicker fusion. The system must not contain any delay() functions, the button needs to be de-bounced and  must trigger an interrupt that serially prints the flick frequency to the monitor. The results that are serially printed on the monitor must be verified by means of an output signal measurement using an oscilloscope.


## Method
schematic diagram of circuit




A serie current limiting resistor needed to be

Green LED datasheet
![Green LED datasheet ](https://user-images.githubusercontent.com/53545740/63909001-4dfe3300-ca75-11e9-9df3-d3eb50594236.JPG)

Vs - Supply Voltage
Vf - Forward voltage of the LED. This is the voltage required to turn on the LED.  
If - Forward Current of the LED. This is the current required by the LED for operation.

Using the following equation a suitable series resistor value can be found.
R = (Vs - Vf) / If
Substituting the values in for the green LED
R = (3.3 - 2.4) / 20mA = 24 ohms 

Because we did not have any 24 ohm resistors available the closest value resistor was used which was 130 ohms.



## Results

<!--stackedit_data:
eyJoaXN0b3J5IjpbMjAwNzg0ODQyOSw4ODgwODkwMjgsMTQ1Nz
Y2OTEwMl19
-->