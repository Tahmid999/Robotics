int relay = 5;
int pir = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
}

void loop()
{
  
  if(digitalRead(pir)==HIGH)
  {
  	Serial.println("Motion Ditected");
    digitalWrite(relay, HIGH);
  }
  else
  {
  	Serial.println("Motion not Ditected");
    digitalWrite(relay, LOW);
  }
  
}
