
int red = 10, blu = 9, green = 8;

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(blu, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop()
{
    // rgb_blink();
    yellow_blink();
}

void rgb_blink(){
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    delay(500);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
    digitalWrite(blu, HIGH);
    delay(500);
    digitalWrite(blu, LOW);
    delay(500);
}

void yellow_blink(){
    digitalWrite(red, 255);
    digitalWrite(green, 255);
    digitalWrite(blu, 0);
    delay(500);
    digitalWrite(red, 0);
    digitalWrite(green, 0);
    digitalWrite(blu, 0);
    delay(500);
}
