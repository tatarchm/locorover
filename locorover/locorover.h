// PIN DEFINITIONS
#define PIN_MOTOR_A1A 4
#define PIN_MOTOR_A1B 5
#define PIN_MOTOR_B1A 7
#define PIN_MOTOR_B1B 6

#define PIN_SERVO_1 8
#define PIN_SERVO_2 9
#define PIN_SERVO_3 10

#define PIN_SONAR_1_ECHO 2
#define PIN_SONAR_1_TRIG 3

#define PIN_SONAR_2_ECHO 10
#define PIN_SONAR_2_TRIG 11

#define IR_RECEIVE_PIN 12


//BUTTON DEFINITIONS

#define BTN_0 25
#define BTN_1 69
#define BTN_2 70
#define BTN_3 71
#define BTN_4 68
#define BTN_5 64
#define BTN_6 67
#define BTN_7 7
#define BTN_8 21
#define BTN_9 9
#define BTN_UP 24
#define BTN_DOWN 82
#define BTN_LEFT 8
#define BTN_RIGHT 90
#define BTN_OK 28
#define BTN_STAR 22
#define BTN_SHARP 13

// FUNCTION DEFINITIONS

// Motor control
typedef struct {
  unsigned char pin_a;
  unsigned char pin_b;
} Motor;

typedef struct {
  unsigned char button;
  unsigned char keypress_registered;
} Remote;

typedef struct {
  unsigned char trig_pin;
  unsigned char echo_pin;
  int distance;
} Sonar;

//Motor
void rotate_motor(unsigned char motor_ind, unsigned char direction, unsigned char speed);
void stop_motor(unsigned char motor_ind);
void setup_motor_pins(unsigned char motor_ind, unsigned char pin_a, unsigned char pin_b);

// Servo control
void rotate_servo(unsigned char servo_ind, unsigned char degrees);
void setup_servo(unsigned char servo_ind, unsigned char pin);

//Sonar
void setup_sonar(unsigned char sonar_ind, unsigned char trig_pin, unsigned char echo_pin);
int get_sonar_distance(unsigned char sonar_ind);
void measure_sonar_distance(unsigned char sonar_ind);

//Remote
void setup_remote();
unsigned char get_ir_button();
bool get_is_ir_pressed();

//Screen
void setup_display();
void clear_display();
void draw_line(int x1, int y1, int x2, int y2);
void draw_rectangle(int x1, int y1, int x2, int y2, bool filled);
void draw_circle(int x, int y, int radius, bool filled);
void draw_pixel(int x, int y);
void draw_text(int x, int y, char* text);
void show();
