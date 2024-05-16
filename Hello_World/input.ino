// input;
void setup()
{
 	Serial.begin(9600);
}

void loop()
{
                // input int;
//   int a = Serial.parseInt() ;
//   Serial.println(a);

                // input float;
//   float f = Serial.parseFloat();
//   Serial.println(f);

                // input char;
// char ch = Serial.read();
// Serial.println(ch);
// delay(1000);

                // input string;
String s = Serial.readString();
Serial.println(s);
delay(3000);


}