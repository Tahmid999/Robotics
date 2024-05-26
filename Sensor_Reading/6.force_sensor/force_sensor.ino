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
    int sensor = analogRead(A1);
    Serial.println(sensor);
    if (sensor >=0 && sensor<=150)
    {
        green_light();
        delay(500);
    }

    if (sensor >=151 && sensor<=330)
    {
        yellow_light();
    }
    if(sensor>=331 && sensor<=400)
    {
        red_light();
    }
    if (sensor>=420)
    {
        digitalWrite(red, HIGH);
        digitalWrite(blu, LOW);
        digitalWrite(green, LOW);
        delay(500);
        digitalWrite(red, LOW);
        digitalWrite(blu, LOW);
        digitalWrite(green, LOW);
        delay(500);
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
