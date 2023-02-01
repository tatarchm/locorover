#include "locorover.h"

void execute_motion(unsigned char speed)
{
    forward(speed);
    delay(1000);
    left(speed);
    delay(1000);
    right(speed);
    delay(1000);
    backward(speed);
    delay(1000);
}

void loop()
{
    execute_motion(SPEED_SLOW);
    execute_motion(SPEED_MEDIUM);
    execute_motion(SPEED_FAST);
}
