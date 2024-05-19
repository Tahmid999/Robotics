void setup()
{
    Serial.begin(9600);

    int arr[] = {1,5,6,9,5};
    int farr[] = {3.14,9.8,4.2,8.6,10.5};
    char carr[] = {'T','A','H','M','I','D'};

    Serial.println(sizeof(arr)/sizeof(arr[0]));
    Serial.println(sizeof(farr)/sizeof(farr[0]));
    Serial.println(sizeof(carr)/sizeof(carr[0]));
}

void loop()
{
    
}