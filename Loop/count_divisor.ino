void setup()
{
    Serial.begin(9600);
    int i = 100; 
    int count = 0;
    for ( i = 100; i <= 500; i++)
    {
        if (i%7==0)
        {
            Serial.println(i);
            count++;
        }
        
    }
    Serial.print("number of divisor by 7 is: "); Serial.print(count);
}

void loop()
{
    
}