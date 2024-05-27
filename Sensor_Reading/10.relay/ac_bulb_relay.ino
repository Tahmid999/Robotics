// C++ code
//
int relay = 6;
void setup()
{
  pinMode(relay, OUTPUT);
}

void loop()
{
  digitalWrite(relay, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(relay, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}