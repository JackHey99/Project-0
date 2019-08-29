#include <arduino.h>

//Configuration
uint8_t BUTTON_PIN = 14;
uint8_t led_pin = 13;
uint32_t debouncedelay_ms = 120;
uint8_t POT_PIN = A1;
//----------------------------------//

//Initilize variable values
volatile bool button_pressed = 0;
uint32_t delta_t_ms = 0;
float frequancy = 0;
//----------------------------------//

void ISR_button_pressed();

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  attachInterrupt(BUTTON_PIN, ISR_button_pressed, FALLING);
}

void loop()
{

//Configure Local Variables 
  uint32_t pot_value = analogRead(POT_PIN);
  delta_t_ms = map(pot_value, 0, 1023, 3 , 30);
  static bool led_state = 0;
  static uint32_t previoustime_ms = 0;
  uint32_t currenttime_ms = millis();



  if ((currenttime_ms - previoustime_ms) >= delta_t_ms)
  {
    if (led_state == 0)
    {
      led_state = 1;
    }
    else
    {
      led_state = 0;
    }
    digitalWrite(led_pin, led_state);
    previoustime_ms = currenttime_ms;
  }

  if (button_pressed == true)
  {
    float pwm_period_ms = delta_t_ms;
    float frequancy = (1000 / (pwm_period_ms * 2));
    
    
    Serial.print("Your threshold is:  ");
    Serial.print((frequancy), 3);
    Serial.println("Hz");

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