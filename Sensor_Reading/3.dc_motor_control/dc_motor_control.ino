
int p = 10;
int n = 11;
void setup()
{
    pinMode(p, OUTPUT);
    pinMode(n, OUTPUT);
}

void loop()
{
    analogWrite(p, 128);
    analogWrite(n, 0);
    delay(2000);
    analogWrite(p, 0);
    analogWrite(n, 128);
    delay(2000);
}
