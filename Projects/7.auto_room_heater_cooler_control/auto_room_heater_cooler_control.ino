
//------------DHT Sensor Library Call-----------------
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


//----------------Display part---------------------

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C display(0x27, 16, 2);

//-----------custom symbol for degree sign------------
byte degree[8] =
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


//------------Indicator and Cooler/Heater Init------------------
int red = 4;
int green = 3;
int blue = 6;

//-------pwm pin--------
int cooler = 9;
// int heater = 10; // if avaiable :)

//----------function declare----------------------
void heat();
void normal();
void cool();


void setup() {

  dht.begin();
  display.backlight(); // for display backlight
  display.init();
  display.createChar(1, degree); // custom symbol created
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(cooler, OUTPUT);


}

void loop() {
  
  float humi = dht.readHumidity();
  float temp_c = dht.readTemperature();
  float temp_f = ((temp_c * 1.8) + 32); // c --> f convert
  delay(10);


  display.clear(); 
  display.setCursor(2,0);
  display.print("Assignment 3");
  display.setCursor(2,1);
  display.print("Team->WALL-E");
  delay(3000);

  display.clear();
  display.setCursor(0,0);
  display.print("Humidity= ");
  display.print(humi);
  display.print("%");
  display.setCursor(0,1);
  display.print("Temp= ");
  display.print(temp_c);
  display.write(1); // to print degree sign
  display.print("C");
  delay(1500);

  display.setCursor(0,1);
  display.print("Temp= ");
  display.print(temp_f);
  display.write(1); // to print degree sign
  display.print("F");
  delay(1500);

  display.setCursor(0,1);
  display.print("Temp= ");
  display.print(temp_c);
  display.write(1); // to print degree sign
  display.print("C");
  delay(1500);

  display.setCursor(0,1);
  display.print("Temp= ");
  display.print(temp_f);
  display.write(1); // to print degree sign
  display.print("F");
  delay(1500);
  
  display.setCursor(0,1);
  display.print("Temp= ");
  display.print(temp_c);
  display.write(1); // to print degree sign
  display.print("C");
  delay(1500);


  if(temp_c >= 30)
  {
    heat();

  }
  else if(temp_c < 29)
  {
    cool();

  }
  else
  {
    normal();

  }


}

void heat()
{
  digitalWrite(green, LOW);
  analogWrite(cooler, ((3.7/5)*255)); // motor can run max 3.7v so that we have to make output below 5v by pwm pin, (0-5)v = (0-255)
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);

  display.clear();
  display.setCursor(0,0);
  display.print("High Temp Alert!");
  display.setCursor(4,1);
  display.print("Cooler ON");
  delay(3000);

}


void normal()
{
  digitalWrite(green, HIGH);
  analogWrite(cooler, 0);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);

  display.clear();
  display.setCursor(3,0);
  display.print("Temp Normal");
  delay(2000);
}


void cool()
{
  // analogWrite(heater, 156); // if we have any header than we can use
  digitalWrite(green, LOW);
  analogWrite(cooler, 0);
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);

  display.clear();
  display.setCursor(1,0);
  display.print("Low Temp Alert!");
  display.setCursor(4,1);
  display.print("Heater ON");
  delay(3000);

  display.clear();
  display.setCursor(0,0);
  display.print("Sorry Heater Nai");
  display.setCursor(1,1);
  display.print("Moja Korlam :)");
  delay(2500);
}
