#include <locorover.h>

#define RED_PIN 10
#define BLUE_PIN 11

void setup()
{
    setup_motor_pins();
    pinMode(RED_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
    forward(SPEED_SLOW);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    delay(500);
    forward(SPEED_SLOW);
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    delay(500);
    forward(SPEED_SLOW);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    delay(500);
    left(SPEED_SLOW);
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    delay(500);
}
