#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void open_eyes()
{
    display.clearDisplay();
    display.fillCircle(display.width()/2 - display.width()/4, display.height()/2, 15, WHITE);
    display.fillCircle(display.width()/2 - display.width()/4, display.height()/2, 8, INVERSE);
    display.fillCircle(display.width()/2 + display.width()/4, display.height()/2, 15, WHITE);
    display.fillCircle(display.width()/2 + display.width()/4, display.height()/2, 8, INVERSE);
    display.display();
}

void close_eyes()
{
    display.clearDisplay();
    display.fillRect(display.width() / 2 - display.width()/4 - 15, display.height() / 2 - 4, 30, 8, WHITE);
    display.fillRect(display.width() / 2 + display.width()/4 - 15, display.height() / 2 - 4, 30, 8, WHITE);
    display.display();
}

void setup()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
    open_eyes();
    delay(500);
    close_eyes();
    delay(500);
}
