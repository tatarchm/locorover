#include <Arduino.h>

#include "locorover.h"
#include "src/Servo.h"
#include "src/TinyIRReceiver.hpp"
#include "src/ss_oled.h"

Motor motor[2];
Servo servo[3];
Sonar sonar[3];
Remote remote;
SSOLED ssoled;

void rotate_motor(unsigned char motor_ind, unsigned char direction, unsigned char speed)
{
  unsigned char v1, v2;
  switch(direction)
  {
    case 0:
    {
      v1 = LOW;
      v2 = speed;
      break;
    }
    case 1:
    {
      v1 = HIGH;
      v2 = 255 - speed;
      break;
    }
  }
  digitalWrite(motor[motor_ind].pin_a, v1);
  analogWrite(motor[motor_ind].pin_b, v2);
}

void stop_motor(unsigned char motor_ind)
{
  digitalWrite(motor[motor_ind].pin_a, LOW);
  digitalWrite(motor[motor_ind].pin_b, LOW);
}

void setup_motor_pins(unsigned char motor_ind, unsigned char pin_a, unsigned char pin_b)
{
  motor[motor_ind].pin_a = pin_a;
  motor[motor_ind].pin_b = pin_b;

  pinMode(motor[motor_ind].pin_a, OUTPUT);
  pinMode(motor[motor_ind].pin_b, OUTPUT);

  digitalWrite(motor[motor_ind].pin_a, LOW);
  digitalWrite(motor[motor_ind].pin_b, LOW);
}

void rotate_servo(unsigned char servo_ind, unsigned char degrees)
{
  servo[servo_ind].write(degrees);
}

void setup_servo(unsigned char servo_ind, unsigned char pin)
{
  servo[servo_ind].attach(pin);
}

void setup_remote()
{
  initPCIInterruptForTinyReceiver();
}

void setup_sonar(unsigned char sonar_ind, unsigned char trig_pin, unsigned char echo_pin)
{
  sonar[sonar_ind].echo_pin = echo_pin;
  sonar[sonar_ind].trig_pin = trig_pin;
  pinMode(sonar[sonar_ind].trig_pin, OUTPUT);
  pinMode(sonar[sonar_ind].echo_pin, INPUT);
}

void measure_sonar_distance(unsigned char sonar_ind)
{
  digitalWrite(sonar[sonar_ind].trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonar[sonar_ind].trig_pin, LOW);

  float duration_us = pulseIn(sonar[sonar_ind].echo_pin, HIGH);
  sonar[sonar_ind].distance = 0.017 * duration_us;
}

float get_sonar_distance(unsigned char sonar_ind)
{
  return sonar[sonar_ind].distance;
}

unsigned char get_ir_button()
{
  return remote.button;
}

bool get_is_ir_pressed()
{
  if (remote.keypress_registered)
  {
    remote.keypress_registered = 0;
    return 1;
  }
  else return 0;
}

void handleReceivedTinyIRData(uint8_t aAddress, uint8_t aCommand, uint8_t aFlags)
{
  remote.button = aCommand;
  remote.keypress_registered = 1;
}
uint8_t ucBackBuffer[1024];

void setup_display()
{
  oledInit(&ssoled, OLED_128x64, -1, 0, 0, 1, -1, -1, -1, 800000L);
  oledSetBackBuffer(&ssoled, ucBackBuffer);
}

void draw_line(int x1, int y1, int x2, int y2)
{
  oledDrawLine(&ssoled, x1, y1, x2, y2, 1);
}

void draw_rectangle(int x1, int y1, int x2, int y2, bool filled)
{
  oledRectangle(&ssoled, x1, y1, x2, y2, 1, filled);
}

void draw_circle(int x, int y, int radius, bool filled)
{
  oledEllipse(&ssoled, x, y, radius, radius, 1, filled);
}

void draw_pixel(int x, int y)
{
  oledSetPixel(&ssoled, x, y, 1, 1);
}

void draw_text(int x, int y, char* text)
{
  oledWriteString(&ssoled, 0, x, y, text, FONT_NORMAL, 0, 1);
}

void show()
{
  oledDumpBuffer(&ssoled, NULL);
}

void clear_display()
{
  oledFill(&ssoled, 0, 1);
}