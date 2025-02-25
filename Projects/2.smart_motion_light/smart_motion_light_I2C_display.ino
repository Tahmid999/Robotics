#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int pir_sensor = 3;	/* PIR sensor O/P pin */
const int relay = 2;
int sensor_output = 0;

bool print1 = false; // to print a particular prompt for one time each of condition in void loop()
bool print2 = false; // to print a particular prompt for one time each of condition in void loop()

void setup() {

  pinMode(pir_sensor, INPUT);
  pinMode(relay, OUTPUT);

  lcd.backlight();
  lcd.init();

}

void loop() {
  sensor_output = digitalRead(pir_sensor);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Team-> WALL-E");
  lcd.setCursor(0, 1);
  lcd.print("Waiting...");
  delay(2000);

  if( sensor_output == LOW )
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Object Here!");
    delay(2000);

    // print this for one time if light is on and no object here then countdown a timer to turn of light
    if(!print1)
      {
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Turning OFF");

        for(int i = 5; i>=1; i--)
        {
          lcd.setCursor(8, 1);
          lcd.print(i);
          delay(1000);
        }

        digitalWrite(relay, HIGH);
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Light OFF");
        delay(2000);

        print1 = true; // in next itration previous countdown will not print again
      }
        
    print2 = false; // to run the prompt agian for one time
  }


  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Object Detected!");
    delay(2000);

    // print this for one time if light is off and object detect then print 'light on'
    if(!print2)
    {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Light ON");
      digitalWrite(relay, LOW);
      delay(2000);
      print2 = true; // in next itration previous prompt will not print again
    }

    print1 = false; // to run the prompt agian for one time

  }  
  
}
