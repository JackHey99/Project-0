![Cover sheet](https://user-images.githubusercontent.com/53545740/64072690-33cb8b80-cce7-11e9-81a9-684b2b33ebf4.JPG)
Cover sheet
File Path: Report_Photos/Cover sheet.JPG

# Project 0
Jack Heyward ID#2174132
Date: 01/09/2019
MG7013 EMBEDDED SYSTEMS
Tutor: Frank Beinersdorf


## Introduction
The aim of this project is to design an embedded system that can measure a person's subjective flicker fusion. The system must not contain any delay() functions, the button needs to be de-bounced and  must trigger an interrupt that serially prints the flick frequency to the monitor. The results that are serially printed on the monitor must be verified by means of an output signal measurement using an oscilloscope.


## Method

Figure 1 below shows the schematic diagram of circuit created on EasyEDA. 
![Schematic for project 0](https://user-images.githubusercontent.com/53545740/64058023-ff79a180-cbf8-11e9-8e9a-4c43ab1972b7.JPG)
Figure 1. Circuit schematic.
File Path: Report_Photos/Schematic for project 0.JPG


A current limiting series resistor needs to be connected to the output pin with the LED. The current flowing in an LED is an exponential function of voltage across the LED. If a series resistor is not added the current can overload the LED and blow it. The following calculation is done to find the correct series resistor or a particular LED color and type.


![Green LED datasheet ](https://user-images.githubusercontent.com/53545740/63909001-4dfe3300-ca75-11e9-9df3-d3eb50594236.JPG)Figure 2. Green LED datasheet. 
From (Vishay, 2019)
File Path: Report_Photos/Green LED data.JPG

Vs - Supply Voltage
Vf - Forward voltage of the LED. This is the voltage required to turn on the LED.  
If - Forward Current of the LED. This is the current required by the LED for operation.

Using the following equation a suitable series resistor value can be found.
R = (Vs - Vf) / If
Substituting the values in for the green LED
R = (3.3 - 2.4) / 20mA = 24 ohms 

Because we did not have any 24 ohm resistors available the closest value resistor was used which was 130 ohms.


The microcontrollers default pin mode is the input state. When the controller is in the input state it has high impedance which means the circuit allows a relatively small amount of current through for the applied voltage. When a button is connected from an input pin to ground, a series current limiting resistor does not need to be added because of the high impedance limiting the current. However a pullup resistor does need to be added to the line as seen in figure 1. Without a pullup resistor the input line acts as an antenna which picks up the surrounding interference. The interference will cause the pin to float and appear noisy and can cause undesired readings on the microcontroller. To stop the floating a pullup resistor typically between 1K-10K ohms is connected from the input line to the 3.3V pin on the controller (see figure 3). This causes the input line to have a constant 3.3V along it while the button is not pushed which is read as logic 1 by the microcontroller. When the button is pushed the current is sinking through the connection to ground and the voltage drops to 0V which is read as a logic 0 by the microcontroller. 

![Pull Up resistor](https://user-images.githubusercontent.com/53545740/64058032-13bd9e80-cbf9-11e9-9c66-45fe7edba810.JPG)
Figure 3. Pull up resistor configuration and transmission signal.  
From (Electronics tutorials, 2018)
File Path: Report_Photos/Pull Up resistor.JPG

When using mechanical buttons as an input for a microcontroller a process called de-bouncing needs to be performed. When a mechanical button is pushed there is always a 'bounce'. This is caused from the spring inside the button taking time to settle. The typical reading for a mechanical button being pushed can be seen in figure 4. We can not remove the bouncing effect however, because we are using a microcontroller we can add additional code to the program to ignore the bounce. This is done by creating an 'ignore time' which tells the program to ignore any input changes for a set time after the initial change. The ignore time is different for each button however, for the button used in this project an ignore time of 80-120 milliseconds was used.

![Button Bounce](https://user-images.githubusercontent.com/53545740/64058038-246e1480-cbf9-11e9-8b42-ee225b6b79e3.JPG)
Figure 4. Button de-bounce waveform.
From (Electronics tutorials,2018)
File Path: Report_Photos/Button Bounce.JPG




## Results
**Pseudo Code**

The following is the Pseudo code used to help create the final program. It is a very basic idea of the program structure with is then converted in to C coding language.

 - Setup and Initialize 

Main loop

 - Read the potentiometer value.
 - Map the potentiometer value to reduce the range.
 - Set the mapped potentiometer value to the PWM half wave period.
 - Turn the LED **on** for the set period.
 - Turn the LED **off** for the set period.
 - **If** button has been pressed print the current frequency on the serial monitor. 
 - **Else** repeat the loop.

Button pressed ISR

 - If the button is pressed at any time exit loop above and remember the action. 
 - Add a 100ms button de-bounce that ignores the bouncing of the button.

**Testing**
Figure 5 and 6 below is the comparison between the reading on the oscilloscope and the values printed on the serial monitor. The two values agreed with each other so it can be confirmed that the system is working correctly and printing accurate data. The Oscilloscope reads to two decimal places so the system can be advertised as accurate to 0.01Hz. If the accuracy needs to be greater the system can return results to a higher degree of accuracy however, they would need to be compared with the readings from an oscilloscope with a higher accuracy to ensure the results are correct.
![Serial monitor display](https://user-images.githubusercontent.com/53545740/64060154-06b2a680-cc1d-11e9-9d1b-1572b8a44b85.JPG)
Figure 5. Serial monitor display reading the threshold frequency and PWM wave period.
File Path: Report_Photos/Serial monitor display.JPG

![LED pin oscilloscope reading](https://user-images.githubusercontent.com/53545740/64060157-116d3b80-cc1d-11e9-8e91-04bd63151d01.JPG)
Figure 6. Oscilloscope reading of the output. Measured frequency = 45.45Hz.
File Path: Report_Photos/LED pin oscilloscope reading.JPG


**A video of the system operating can be found at**
https://youtu.be/N0qFZP7VAJ0

Final version of the code can be found at the following file path: src/main.cpp

**Future Improvements** 
Some possible future improvements for this project could be to create a graphical user interface, GUI that returns the flicker threshold in a more user friendly and simpler form than the serial monitor command window. If a GUI is created the potentiometer could be removed and replaced with a flick control button within the GUI. This would give the user greater control in the frequency adjustment as the increments can be much finer with an increased resolution. The increased control and resolution will allow the user to adjust the frequency to their exact flick threshold giving a more accurate result. 

## Conclusion
The aim of this project was to design an embedded system that can measure a person's subjective flicker fusion. All specifications and constraints were adhered to and the final program and circuit worked as desired. The program returns the flicker frequency via a serial monitor to a tested accuracy of two decimal places. Creation of a GUI was suggested as a future improvement for the system which would allow the user to adjust the flicker frequency with greater control. The result could also be presented on a more user friendly display within the GUI. Overall the system meets the brief and works as desired. 

## References


Electronic Tutorials. (2018, April 25). Input Interfacing Circuits Connect to the Real World. Retrieved from https://www.electronics-tutorials.ws/io/input-interfacing-circuits.html

Vishay. (2019, January 1). High Efficiency LED. Retrieved from https://www.vishay.com/docs/83009/tlhg4900.pdf
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIwOTI4OTM3MzldfQ==
-->