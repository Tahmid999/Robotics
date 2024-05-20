class calculator
{
    int a,b,c;
    public:
    void set(int n1,int n2, int n3)
    {
        a = n1;
        b = n2;
        c = n3;
    }

    void sum(){
        int sum = a+b+c;
        Serial.print("your sum is: ");
        Serial.print(sum);
        Serial.println();
    }

    void multi(){
        int multi = a*b*c;
        Serial.print("your multiplication is: ");
        Serial.print(multi);
        Serial.println();
    }

    void large(){

        if (a>b && a>c)
        {
            Serial.print("your large num is: ");
            Serial.print(a);
            Serial.println();
        }
        if (b>a && b>c)
        {
            Serial.print("your large num is: ");
            Serial.print(b);
            Serial.println();
        }
        else
        {
            Serial.print("your large num is: ");
            Serial.print(c);
            Serial.println();
        }
    }

};

void setup()
{
    Serial.begin(9600);
    calculator c; // c is a object of calculator class;
    c.set(10,50,-50);
    c.large();
    c.sum();
}

void loop()
{
    
}