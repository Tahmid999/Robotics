void setup()
{
    Serial.begin(9600);
    // while (1)
    // {
    //     if (Serial.readString()=="Run" || Serial.readString()=="run")
    //     {
    //         while (1)
    //         {
    //             Serial.println("Loop Running");

    //             if (Serial.readString()=="Stop" || Serial.readString()=="stop")
    //             {
    //                 Serial.println("Loop Stop");    
    //                 break;
    //             }

    //         }
    //             if (Serial.readString()!="Run" || Serial.readString()!="run" || Serial.readString()!="Stop" || Serial.readString()!="stop")
    //             {
                    
    //                 Serial.println("No command found");
    //                 break;
    //             }
    //     }
    // }   
}

void loop()
{
    while (1)
    {
        if (Serial.readString()=="Run" || Serial.readString()=="run")
        {
            while (1)
            {
                Serial.println("Loop Running");

                if (Serial.readString()=="Stop" || Serial.readString()=="stop")
                {
                    Serial.println("Loop Stop");    
                    break;
                }

            }
                if (Serial.readString()!="Run" || Serial.readString()!="run" || Serial.readString()!="Stop" || Serial.readString()!="stop")
                {
                    
                    Serial.println("No command found");
                    break;
                }
        }
    }
}