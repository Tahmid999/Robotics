void setup()
{
    Serial.begin(9600);

}

void loop()
{
    if (Serial.available()>0)
    {   
        char ch = Serial.read();
        if (ch>='a' && ch<='z')
        {
            Serial.print(ch);
            Serial.println(" is small charecter");
        }
        else if (ch>='A' && ch<='Z')
        {
            Serial.print(ch);
            Serial.println(" is capital charectar");
        }
        else 
        {
            Serial.print(ch);
            Serial.println(" is not charecter");
        }
        
    }

}
