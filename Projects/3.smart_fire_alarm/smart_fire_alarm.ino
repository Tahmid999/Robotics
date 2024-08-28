int buzzer = 5; 
int fire_sensor = 7, smoke_sensor = A2;

void setup()
{
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);
    pinMode(fire_sensor, INPUT);
}

void loop()
{
    if ((digitalRead(fire_sensor)==true) && (analogRead(smoke_sensor)>250))
    {
        Serial.print("fire and smoke detected");
        digitalWrite(buzzer, HIGH);
    }
    else
    {
        Serial.print("fire and smoke not detected");
        digitalWrite(buzzer, LOW);
    }
    Serial.println("");
}
