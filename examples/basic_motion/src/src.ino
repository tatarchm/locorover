#define A1PIN 2
#define A2PIN 3
#define B1PIN 4
#define B2PIN 5

#define SPEED_SLOW 128
#define SPEED_MEDIUM 192
#define SPEED_FAST 255

void forward(unsigned char speed)
{
    digitalWrite(A1PIN, LOW);
    analogWrite(A2PIN, speed);
    digitalWrite(B1PIN, LOW);
    analogWrite(B2PIN, speed);
}

void backward(unsigned char speed)
{
    digitalWrite(A1PIN, HIGH);
    analogWrite(A2PIN, 255 - speed);
    digitalWrite(B1PIN,  HIGH);
    analogWrite(B2PIN, 255 - speed);
}

void left(unsigned char speed)
{
    digitalWrite(A1PIN, LOW);
    analogWrite(A2PIN, speed);
    digitalWrite(B1PIN, LOW);
    digitalWrite(B2PIN, LOW);
}

void right(unsigned char speed)
{
    digitalWrite(A1PIN, LOW);
    analogWrite(A2PIN, LOW);
    digitalWrite(B1PIN, LOW);
    analogWrite(B2PIN, speed);
}

void stop()
{
    digitalWrite(A1PIN, LOW);
    digitalWrite(A2PIN, LOW);
    digitalWrite(B1PIN, LOW);
    digitalWrite(B2PIN, LOW);
}

void setup()
{
    pinMode(A1PIN, OUTPUT);
    pinMode(A2PIN, OUTPUT);
    pinMode(B1PIN, OUTPUT);
    pinMode(B2PIN, OUTPUT);

    digitalWrite(A1PIN, LOW);
    digitalWrite(A2PIN, LOW);
    digitalWrite(B1PIN, LOW);
    digitalWrite(B2PIN, LOW);
}

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
