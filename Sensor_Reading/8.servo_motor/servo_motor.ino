// C++ code
//
#include<Servo.h>

Servo myservo;
void setup()
{
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(0);
}

void loop()
{
  Serial.println("Enter motor angle unit: ");
  while(Serial.available()==0){
    // wait for input
  }
  int angle_unit = Serial.parseInt();
  myservo.write(angle_unit);
  
}
