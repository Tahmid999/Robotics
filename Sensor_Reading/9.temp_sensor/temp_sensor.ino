// C++ code
//
int red = 11;
int blu = 10;
int green = 9;
int buzzer = 6;
void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blu, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  int temp = temparature();
  Serial.println(temp);
  
  if (temp <=-10 || temp>= 100) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(blu, LOW);
    digitalWrite(green, LOW);
    Serial.println("Temparature Alart!");
  }
  if ((temp <=-2 && temp>=-9) || (temp>=80 && temp<=99) )
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(blu, LOW);
    digitalWrite(green, LOW);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(blu, LOW);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  if ((temp>= -1 && temp<=15) || (temp>=36 && temp<=79))
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blu, LOW);
    Serial.println("Need Steps!");
  }
  if (temp>=16 && temp<=35 )
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blu, LOW);
    Serial.println("Temparature is good");
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  
}

int temparature() {
  int sensor_read = analogRead(A1);
  int temp = map(sensor_read,20,358,-40,125);
  return temp;
}
