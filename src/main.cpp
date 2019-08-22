#include <Arduino.h>

//Configuration
uint8_t BUTTON_PIN = 14;
uint8_t LED_PIN = 12;
uint32_t debouncedelay_ms = 100;
uint8_t POT_PIN = A1;
//----------------------------------//

//Initilize variable values
//uint32_t pot_value = 0;
//float pot_voltage = 0;
volatile bool button_pressed = 0;
//----------------------------------//

void ISR_button_pressed();

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(BUTTON_PIN, ISR_button_pressed, FALLING);
}

void loop()
{
  uint32_t pot_value = analogRead(POT_PIN);
  float pot_voltage = (pot_value * 3.3) / (1023);

  if (button_pressed == true)
  {
    Serial.println(pot_voltage, 4);
  }

  button_pressed = false;
}

void ISR_button_pressed()
{
  noInterrupts();
  uint32_t currenttime_ms = millis();
  static uint32_t previoustime_ms = 0;

  if ((currenttime_ms - previoustime_ms) > debouncedelay_ms)
  {
    button_pressed = true;
    previoustime_ms = currenttime_ms;
  }
  interrupts();
}