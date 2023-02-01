#include <locorover.h>
#include <Ultrasonic.h>

Ultrasonic sonar_l(10, 11);
Ultrasonic sonar_r(8, 9);

void setup()
{
    setup_motor_pins();
}

void loop()
{
    forward(SPEED_SLOW);
    if (sonar_l.read() < 10)
    {
        left(SPEED_SLOW);
        delay(300);
    }
    if (sonar_r.read() < 10)
    {
        right(SPEED_SLOW);
        delay(300);
    }
}
