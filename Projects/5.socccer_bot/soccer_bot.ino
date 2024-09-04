//Right motor: motorA_pwm-11(for right motors clockwise spin), 
               //motorB_pwm-10(for right motors anti_clockwise spin),
               //motorA_en-13, motorB_en-12
//Left motor: motorC_pwm-6(for right motors clockwise spin),
              //motorD_pwm-5(for right motors anti_clockwise spin), 
              //motorC_en-9, motorD_en-8


//for right motors pins, i can use #define mehtode
int motorA_en = 13;
int motorB_en = 12;
int motorA_pwm = 11;
int motorB_pwm = 10;

//for right motors pins, i can use #define mehtode
int motorC_en = 9;
int motorD_en = 8;
int motorC_pwm = 16;
int motorD_pwm = 5;

int speed ; // to control motor speed
char remote; //to recive bluetooth signal

//motors movement functions forward declare
void forward();
void backward();
void left();
void right();
void stop();


void setup()
{
    //Right motors pinmode set
    pinMode(motorA_en, OUTPUT);
    pinMode(motorB_en, OUTPUT);
    pinMode(motorA_pwm, OUTPUT);
    pinMode(motorB_pwm, OUTPUT);

    //Left motors pinmode set
    pinMode(motorC_en, OUTPUT);
    pinMode(motorD_en, OUTPUT);
    pinMode(motorC_pwm, OUTPUT);
    pinMode(motorD_pwm, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    //for control by blutooth
    if (Serial.available())
    {
        remote = Serial.read(); //to recive blutooth signal (S,F,B,L,R)

        //this if condition is for motor speed control, 
        //bluetooth signal value for speed is (0-9)
        if (remote=='0' || remote=='1' || remote=='2' || remote=='3' || remote=='4' || 
            remote=='5' || remote=='6' || remote=='7' || remote=='8' || remote=='9')
        {
            int value = (int)remote; //typecasting == char value to int value from signal
            speed = value*28; // 255/9 = 28.333 so 0*28=0, 5*28=140, 9*28=252
        }
        
        //this all if condition for motors movement control
        if (remote=='F')
        {
            forward();
            Serial.print(remote);
        }
        if (remote=='B')
        {
            backward();
            Serial.print(remote);
        }
        if (remote=='R')
        {
            right();
            Serial.print(remote);
        }
        if (remote=='L')
        {
            left();
            Serial.print(remote);
        }
        if (remote=='S')
        {
            stop();
            Serial.print(remote);
        }

        Serial.println("");
    }
    
}

void forward(){

    //for right motors forward
    digitalWrite(motorA_en, HIGH);
    digitalWrite(motorB_en, HIGH);
    analogWrite(motorA_pwm, speed);
    analogWrite(motorB_pwm, 0);

    //for left motors forward
    digitalWrite(motorC_en, HIGH);
    digitalWrite(motorD_en, HIGH);
    analogWrite(motorC_pwm, speed);
    analogWrite(motorD_pwm, 0);
}

void backward(){

    //for right motors forward
    digitalWrite(motorA_en, HIGH);
    digitalWrite(motorB_en, HIGH);
    analogWrite(motorA_pwm, 0);
    analogWrite(motorB_pwm, speed);

    //for left motors forward
    digitalWrite(motorC_en, HIGH);
    digitalWrite(motorD_en, HIGH);
    analogWrite(motorC_pwm, 0);
    analogWrite(motorD_pwm, speed);
}

void left(){

    //for right motors forward
    digitalWrite(motorA_en, HIGH);
    digitalWrite(motorB_en, HIGH);
    analogWrite(motorA_pwm, speed);
    analogWrite(motorB_pwm, 0);

    //for left motors forward
    digitalWrite(motorC_en, HIGH);
    digitalWrite(motorD_en, HIGH);
    analogWrite(motorC_pwm, 0);
    analogWrite(motorD_pwm, speed);
}

void right(){

    //for right motors forward
    digitalWrite(motorA_en, HIGH);
    digitalWrite(motorB_en, HIGH);
    analogWrite(motorA_pwm, 0);
    analogWrite(motorB_pwm, speed);

    //for left motors forward
    digitalWrite(motorC_en, HIGH);
    digitalWrite(motorD_en, HIGH);
    analogWrite(motorC_pwm, speed);
    analogWrite(motorD_pwm, 0);
}

void stop(){

    //for right motors forward
    digitalWrite(motorA_en, LOW);
    digitalWrite(motorB_en, LOW);

    //for left motors forward
    digitalWrite(motorC_en, LOW);
    digitalWrite(motorD_en, LOW);
}
