#define SPEED_SLOW 128
#define SPEED_MEDIUM 192
#define SPEED_FAST 255

struct MotorControllerPins {
    int A1PIN;
    int A2PIN;
    int B1PIN;
    int B2PIN;
};

MotorControllerPins PIN_DEF[2];

void rotate_motor(unsigned char controller_ind, unsigned char motor, unsigned char direction, unsigned char speed)
{
    unsigned char pin1, pin2;
    unsigned char v1, v2;
    switch(motor)
    {
        case 0:
        {
            pin1 = PIN_DEF[controller_ind].A1PIN;
            pin2 = PIN_DEF[controller_ind].A2PIN;
            break;
        }
        case 1:
        {
            pin1 = PIN_DEF[controller_ind].B1PIN;
            pin2 = PIN_DEF[controller_ind].B2PIN;
            break;
        }
    }
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
    digitalWrite(pin1, v1);
    analogWrite(pin2, v2);
}

void stop_motor(unsigned char controller_ind, unsigned char motor)
{
    unsigned char pin1, pin2;
    switch(motor)
    {
        case 0:
        {
            pin1 = PIN_DEF[controller_ind].A1PIN;
            pin2 = PIN_DEF[controller_ind].A2PIN;
            break;
        }
        case 1:
        {
            pin1 = PIN_DEF[controller_ind].B1PIN;
            pin2 = PIN_DEF[controller_ind].B2PIN;
            break;
        }
    }
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

void setup_motor_pins(unsigned char controller_ind)
{
    if (controller_ind == 0)
    {
        PIN_DEF[controller_ind].A1PIN = 4;
        PIN_DEF[controller_ind].A2PIN = 5;
        PIN_DEF[controller_ind].B1PIN = 8;
        PIN_DEF[controller_ind].B2PIN = 9;
    }
    else if (controller_ind == 1)
    {
        PIN_DEF[controller_ind].A1PIN = 7;
        PIN_DEF[controller_ind].A2PIN = 6;
        PIN_DEF[controller_ind].B1PIN = 10;
        PIN_DEF[controller_ind].B2PIN = 11;
    }
    

    pinMode(PIN_DEF[controller_ind].A1PIN, OUTPUT);
    pinMode(PIN_DEF[controller_ind].A2PIN, OUTPUT);
    pinMode(PIN_DEF[controller_ind].B1PIN, OUTPUT);
    pinMode(PIN_DEF[controller_ind].B2PIN, OUTPUT);

    digitalWrite(PIN_DEF[controller_ind].A1PIN, LOW);
    digitalWrite(PIN_DEF[controller_ind].A2PIN, LOW);
    digitalWrite(PIN_DEF[controller_ind].B1PIN, LOW);
    digitalWrite(PIN_DEF[controller_ind].B2PIN, LOW);
}
