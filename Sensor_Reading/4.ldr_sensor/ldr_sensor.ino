
int led = 5;
void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int ldr_value = analogRead(A1);
    Serial.println(ldr_value);
    if (ldr_value <= 500)
    {
        digitalWrite(led, HIGH);
        delay(500);
    }
    else
    {
        digitalWrite(led, LOW);
        delay(500);
    }
    
    
}
