#include <Servo.h> //to use servo facility we need to add this library header file.

int servo_pin = 6;

Servo myservo;  // servo is a class and myservo is a object.
void setup()
{
    Serial.begin(9600);
    myservo.attach(servo_pin); // introduce to the myservo object 6 no pin is for servo motor.  
}

void loop()
{
    int sensor = angle_value();
    Serial.println(sensor);
    myservo.write(sensor); // write the andgle.
}

int angle_value() {
    int sensor_read = analogRead(A1);
    int angle = map(sensor_read, 693, 285, 0, 180);
    return angle;
}
