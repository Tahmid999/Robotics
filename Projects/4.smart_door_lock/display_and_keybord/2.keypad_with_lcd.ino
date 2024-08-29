#include <LiquidCrystal_I2C.h> // to use display function and object
#include <Keypad.h> // to use keypad function and object

// ----------DISPLAY CONFIGURE-----------
int lcd_address = 0x27; //can be change for differant lcd display
int lcd_row = 2, lcd_column = 16; // also can be change for differant lcd display
LiquidCrystal_I2C lcd (lcd_address, lcd_row, lcd_column); // main object to use lcd

// ----------KEYBOARD CONFIGURE----------
const byte row = 4, column = 4; //can be change for differant keypad like 3X4
                                // data type byte must
char keys[row][column] = 
{
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
}; //define all keys

byte row_pins[row] =    {11,10,9,8}; //digital pin numbar of arduino board for keypad rows
byte col_pins[column] = {7,6,5,4}; ////digital pin numbar of arduino board for keypad cols

Keypad keyboard = Keypad(makeKeymap(keys), row_pins, col_pins, row, column); //main object
                                                                            //to use keypad

void setup()
{
  lcd.init(); //lcd display initialaization
  lcd.backlight(); //for brightness
  Serial.begin(96400);
}

void loop()
{
  char key = keyboard.getKey(); // watting for key input

  if (key) //use if statement to avoid garbage/blank keys continuously
  {
    lcd.clear(); //to avoid garbage letter for sefty
    lcd.setCursor(0,0);
    lcd.print(key); //key print on lcd display
    Serial.println(key);
  }
  

}
