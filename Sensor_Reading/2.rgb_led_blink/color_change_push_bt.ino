
int red = 11;
int blu = 10;
int green = 9;

int button = 6;
int count = 0;

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(blu, OUTPUT);
    pinMode(green, OUTPUT);

    pinMode(button, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(button)==LOW)
    {
        count++;
        delay(500);
    }

    if (count == 0)
    {
        digitalWrite(red, 0);
        digitalWrite(blu, 0);
        digitalWrite(green, 0);
    }

    if (count == 1)
    {
        digitalWrite(red, 255);
        digitalWrite(blu, 255);
        digitalWrite(green, 255);
    }

    if (count == 2)
    {
        digitalWrite(red, 255);
        digitalWrite(blu, 0);
        digitalWrite(green, 0);
    }

    if (count == 3)
    {
        digitalWrite(red, 0);
        digitalWrite(blu, 255);
        digitalWrite(green, 0);
    }

    if (count == 4)
    {
        digitalWrite(red, 0);
        digitalWrite(blu, 0);
        digitalWrite(green, 255);
    }

    if (count == 5)
    {
        digitalWrite(red, 255);
        digitalWrite(blu, 255);
        digitalWrite(green, 0);
    }
    
    if (count == 6)
    {
        digitalWrite(red, 255);
        digitalWrite(blu, 0);
        digitalWrite(green, 255);
    }


 /* if i want to make different color then
    i have to change rgb value (0-255), so i
    need to apply the value in pwm port and need
    to use analogwrite function */
    
    if (count == 7)
    {
        analogWrite(red, 31);     
        analogWrite(blu, 255);
        analogWrite(green, 226);
    }

    if (count == 8)
    {
        count = 0;
    }
    
}