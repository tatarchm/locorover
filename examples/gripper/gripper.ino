#include <locorover.h>
#include <Servo.h>

#define GRIPPER_DOWN_DEG 0
#define GRIPPER_UP_DEG 50
#define GRIPPER_OPEN_DEG 70
#define GRIPPER_CLOSE_DEG 40

Servo updown_servo, gripper_servo;

void setup()
{
    setup_motor_pins();
    gripper_servo.attach(8);
    updown_servo.attach(9);
}

void loop()
{
    updown_servo.write(GRIPPER_DOWN_DEG);
    gripper_servo.write(GRIPPER_OPEN_DEG);
    delay(10000);
    gripper_servo.write(GRIPPER_CLOSE_DEG);
    delay(1000);
    updown_servo.write(GRIPPER_UP_DEG);
    delay(1000);
    backward(SPEED_SLOW);
    delay(1000);
    left(SPEED_SLOW);
    delay(500);
    forward(SPEED_SLOW);
    delay(1000);
    stop();
    delay(1000);
    updown_servo.write(GRIPPER_DOWN_DEG);
    delay(500);
    gripper_servo.write(GRIPPER_OPEN_DEG);
    delay(10000);
}
