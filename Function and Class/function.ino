// function 1 -----
int sum (int n1, int n2)
{
    int result = n1+n2;
    return result;
}

// function 2 -----
int findlargenum(int n1,int n2, int n3)
{
    if (n1>n2 && n1>n3)
    {
        return n1;
    }
    if (n2>n1 && n2>n3)
    {
        return n2;
    }
    else
        return n3;
    
}
void setup()
{
    Serial.begin(9600);
    int result = sum(27,20);
    Serial.println(result);

    int ans = findlargenum(-10,-5,-3);
    Serial.println(ans);
}

void loop()
{
    
}
