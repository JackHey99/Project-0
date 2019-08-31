# Project 0
Jack Heyward ID#2174132

## Introduction
The aim of this project is to design an embedded system that can measure a person's subjective flicker fusion. The system must not contain any delay() functions, the button needs to be de-bounced and  must trigger an interrupt that serially prints the flick frequency to the monitor. The results that are serially printed on the monitor must be verified by means of an output signal measurement using an oscilloscope.


## Method
schematic diagram of circuit




A current limiting series resistor needs to be connected to the output pin with the LED. The current flowing in an LED is an exponential function of voltage across the LED. If a series resistor is not added the current can overload the LED and blow it. The following calculation is done to find the correct series resistor or a particular LED color and type.


![Green LED datasheet ](https://user-images.githubusercontent.com/53545740/63909001-4dfe3300-ca75-11e9-9df3-d3eb50594236.JPG)Figure 2. Green LED datasheet


Vs - Supply Voltage
Vf - Forward voltage of the LED. This is the voltage required to turn on the LED.  
If - Forward Current of the LED. This is the current required by the LED for operation.

Using the following equation a suitable series resistor value can be found.
R = (Vs - Vf) / If
Substituting the values in for the green LED
R = (3.3 - 2.4) / 20mA = 24 ohms 

Because we did not have any 24 ohm resistors available the closest value resistor was used which was 130 ohms.



Pullup / Pulldown

Button denounce 


The microcontrollers default pin mode is the input state. When the controller is in the input state it has high impedance which means the circuit allows a relatively small amount of current through for the applied voltage. When a button is connected from an input pin to ground, a series current limiting resistor does not need to be added because of the high impedance limiting the current. However a pullup resistor does need to be added to the line as seen in figure 1. Without a pullup resistor the input line acts as an antenna which picks up the surrounding interference. The interference will cause the pin to float and appear noisy and can cause undesired readings on the microcontroller. To stop the floating a pullup resistor typically between 1K-10K ohm is connected.

## Results

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTM0NTQ2NjI1OV19
-->