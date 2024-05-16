void setup()
{
    Serial.begin(9600);
    Serial.println("Enter three number: ");
}

void loop()
{
    if (Serial.available()>0)
    {
        
        int num1 = Serial.parseInt();
        int num2 = Serial.parseInt();
        int num3 = Serial.parseInt();

        if (num1>num2)
        {
            Serial.print(num1);
            Serial.println(" is large number");
                if (num2>num3)
                {
                    Serial.print(num2);
                    Serial.println(" is large number");
                }
        }

        else
        {
            Serial.print(num3);
            Serial.println(" is large number");
        }
        
    }
    
}