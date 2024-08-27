#include<Servo.h> // to use servo motor
Servo my_servo;
int echo = 6, trig = 5;
float distance_value(int echo, int trig); // function forward call

void setup()
{
    Serial.begin(9600);
    my_servo.attach(9); // servo motor pin diclare
    my_servo.write(0); // check and sefty for garbage voltage
    pinMode(echo, INPUT);
    pinMode(trig, OUTPUT);
}

void loop()
{
    if (distance_value(echo, trig)<=65.5) // distance is in cm
    {
        my_servo.write(92);
    }
    else
        my_servo.write(0);
}

float distance_value(int echo, int trig)
{
    digitalWrite(trig, LOW); // check and sefty for garbage voltage
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    int duration = pulseIn(echo, HIGH); // to capture the time

    float distance= ((0.034 * duration)/2); // we know s=vt, 
                                            // here v is in cm/microsecon
    return distance;
}
