#include <LiquidCrystal_I2C.h> //to use important fuction or object for i2c lcd
int lcd_address = 0x27;
int lcd_row = 2. lcd_column = 16; //need to configure for differant lcd

LiquidCrystal_I2C lcd (lcd_address, lcd_row, lcd_address); 

void setup()
{
    lcd.init();             //Initialize the LCD
    lcd.clear();           //clear screen if unnecessary letter come for sefty
    lcd.backlight();       //turn on back light
    lcd.setCursor(2,0);    //Set the cursor to column 0, line 0
    lcd.print("Hello! World"); //to print something on the display
    lcd.setCursor(0,1);
    lcd.print("Checking LCD");
}

void loop()
{
    
}
