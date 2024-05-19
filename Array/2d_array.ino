// const int row = 5;
// const int col = 5;
// int arr[row][col];
int n,m;
void setup()
{
    Serial.begin(9600);
    int n,m;
    Serial.println("Enter row and col that you want: ");
    while (Serial.available()==0)
    {
        // wait for input;
    }
    n = Serial.parseInt();
    m = Serial.parseInt();

    // if (n>row && m>col)
    // {
    //     n = row;
    //     m = col;
    // }
    
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Serial.print("Enter "); Serial.print("["); Serial.print(i+1); Serial.print("]"); 
            Serial.print("["); Serial.print(j+1); Serial.print("]"); Serial.print(" index value: ");
            while (Serial.available()==0)
            {
                // wait for input;
            }
            arr[i][j] = Serial.parseInt();
            Serial.println();
        }
        Serial.println();
    }

    Serial.println("Your array values are: ");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Serial.print(arr[i][j]); Serial.print(" ");
        }
        Serial.println();
    }
    
    
    
}

void loop()
{
    
}