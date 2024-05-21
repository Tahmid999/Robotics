int red = 11;
int blu = 10;
int green = 9;

void setup()
{
    Serial.begin(9600);
    pinMode(red, OUTPUT);
    pinMode(blu, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop()
{
    int soil_mos = analogRead(A1);
    Serial.println(soil_mos);

    if (soil_mos >=0 && soil_mos <=100)
    {
        // digitalWrite(red, HIGH);
        // digitalWrite(blu, LOW);
        // digitalWrite(green, LOW);
      	// delay(500);

        red_light();
        delay(500);
    }

    if (soil_mos >=101 && soil_mos <=600)
    {
        // digitalWrite(red, HIGH);
        // digitalWrite(green, HIGH);
        // digitalWrite(blu, LOW);

        yellow_light();
    }
    else
    {
        // digitalWrite(green, HIGH);
        // digitalWrite(red, LOW);
        // digitalWrite(blu, LOW);

        green_light();
    }

}

void red_light(){
    digitalWrite(red, HIGH);
    digitalWrite(blu, LOW);
    digitalWrite(green, LOW);
}

void yellow_light(){
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blu, LOW);
}

void green_light(){
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blu, LOW);
}
