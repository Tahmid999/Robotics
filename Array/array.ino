
// const int size = 100;
// int arr[size];
void setup()
{
    Serial.begin(9600);
    
    int n;
    Serial.println("How many numbers do you want to store: ");
    while (Serial.available()==0)
    {
        // wait for inpur this is must while input any data;
    }
    n = Serial.parseInt();
    
    // if (n > size)
    // {                // to avoid overflow;
    //     n = size;
    // }
    
    int arr[n];
    Serial.print("Enter "); Serial.print(n); Serial.print(" numbers: ");
    Serial.println();

    for (int i = 0; i < n ; i++)
    {
        while (Serial.available()==0)
        {
        // wait for inpur this is must while input any data;
            //
        }
        arr[i] = Serial.parseInt();
    }

    Serial.print("Your "); Serial.print(n); Serial.println(" numbers are: ");

    for (int i = 0; i < n; i++)
    {
        Serial.print(arr[i]);
        Serial.print(" ");
    }
    
}

void loop()
{
    
}
