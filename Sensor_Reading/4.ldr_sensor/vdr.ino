void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int res = analogRead(A1);
    Serial.println(res);
}

// voltage divider rule
// (511/1023)*5 ~= 2.5v 