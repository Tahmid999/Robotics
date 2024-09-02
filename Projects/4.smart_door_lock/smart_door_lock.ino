#include<LiquidCrystal_I2C.h> // to use display function and object
#include<Keypad.h> //to use keypad function and object

// ----------DISPLAY CONFIGURE-----------
const int lcd_address = 0x27; //can be change for differant lcd display
const int lcd_row = 2 , lcd_col = 16; //also can be change for differant lcd display
LiquidCrystal_I2C lcd (lcd_address, lcd_row, lcd_col); //main object to use lcd

// ----------KEYBOARD CONFIGURE----------
const byte key_row=4, key_col=4; //can be change for differant keypad like 3X4
char keys[key_row][key_col] =
{
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
}; //define all keys

byte row_pins[key_row] = {11,10,9,8}; //digital pin numbar of arduino board for keypad rows
byte col_pins[key_col] = {7,6,5,4}; //digital pin numbar of arduino board for keypad cols

Keypad keyboard = Keypad(makeKeymap(keys), row_pins, col_pins, key_row, key_col); 
//main objectto use keypad


//-------------PASSWORD CONFIGURE---------------
int pass_length = 5;
const String system_pass = "A1121"; //main pass
String input_pass = "";

//-------------LIGHT FEATURE--------------------
int red =4;
int green = 3;

void setup()
{
    lcd.init();
    lcd.backlight();
    Serial.begin(9600);
    pinMode(red, OUTPUT);
  	pinMode(green, OUTPUT);
}

void loop()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter your pass:");
    int i = 6;
    while (1)
    {
        char key = keyboard.getKey(); // watting for key input
        if (key) //use if statement to avoid garbage/blank keys continuously
        {
            if (input_pass.length()<pass_length) //chacking pass_length
            {
                input_pass = input_pass + key;
                lcd.setCursor(i,1); //for preview
                lcd.print("*");
                i++;
            }
            if (input_pass.length()==pass_length) //checking password
            {           
                if (input_pass==system_pass)
                {
                    lcd.clear();
                    lcd.setCursor(4,0);
                    lcd.print("Door Open");
                    digitalWrite(green, HIGH);
                    delay(4000);
                    input_pass = ""; //reset pass
                    break;
                }
                else
                {
                    lcd.clear();
                    lcd.setCursor(3,0);
                    lcd.print("Wrong Pass");
                    digitalWrite(red, HIGH);
                    delay(3000);
                    input_pass = ""; //reset pass
                    break;
                } 
            }
        }
    }

//Door close after pass input
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Door Closed!");
    digitalWrite(green, LOW);
  	digitalWrite(red, LOW);
    delay(3000);
    
}
