void setup()
{
    Serial.begin(9600);
    
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            Serial.print("* ");
        }
        Serial.println();
    }
    
}

void loop()
{
    
}