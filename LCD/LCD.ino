// The LCD is usually interfaced via 16 pins which are labelled as shown below:
                         //Connections to Arduino
                         //  LCD                                                 Connection
                         //  1. GND - Ground                                     GND
                         //  2. VDD - 3 - 5V                                     5V
                         //  3. VO  - Contrast                                   (Tap off a 5K - 10K pot across VCC and Ground)
#define LCD_RS         7 //  4. RS  - Register Select - 0=Command / 1=Character  Arduino Pin as defined
                         //  5. RW  - Read/Write - 0=Write or 1=Read             GND
#define LCD_ENABLE     3 //  6. E   - Enable - Enable data transmit              Arduino Pin as defined
                         //  7. DB0 - Data Bit 0                                 N/A
                         //  8. DB1 - Data Bit 1                                 N/A
                         //  9. DB2 - Data Bit 2                                 N/A
                         // 10. DB3 - Data Bit 3                                 N/A
#define LCD_DB4        4 // 11. DB4 - Data Bit 4 - used in 4 bit operation       Arduino Pin as defined
#define LCD_DB5        5 // 12. DB5 - Data Bit 5 - used in 4 bit operation       Arduino Pin as defined
#define LCD_DB6        13 // 13. DB6 - Data Bit 6 - used in 4 bit operation       Arduino Pin as defined
#define LCD_DB7        2 // 14. DB7 - Data Bit 7 - used in 4 bit operation       Arduino Pin as defined
#define LCD_Backlight 10 // 15. BL1 - Backlight +                                Emitter of 2N3904, Collector to VCC, Base to D10 via 10K resistor
                         // 16. BL2 - Backlight -                                GND

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

void setup() {
  float n = 19/2;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Robot ");
  lcd.setCursor(0,1);
  lcd.print("Hello ");
  pinMode(LCD_Backlight, OUTPUT); 
  analogWrite(LCD_Backlight, 128); // Set the brightness of the backlight
}

void loop(){}
