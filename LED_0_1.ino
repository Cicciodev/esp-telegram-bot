#include<SoftwareSerial.h>
// In order to debug I define a differente serial port for the esp
SoftwareSerial esp(2,3);

String command = ""; 

void setup()
{
  Serial.begin(115200);
  esp.begin(115200);
  Serial.println("System Ready..");
  pinMode(13, OUTPUT);
}

void loop() {
  if (esp.available())
  {
    // Receiving a command from esp
    command = esp.readString();
    // [DEBUG] say what you got
    // Serial.print("I received: ");
    // Serial.println(command);

    // Trimming cause of newline (or maybe simple change println with print in esp programm)
    command.trim();

    // Handle command-action
    if (command == "1")
    {
      digitalWrite(13, HIGH);
      Serial.println("Command completed LED turned ON");
    }
    if (command == "0")
    {
      digitalWrite(13, LOW);
      Serial.println("Command completed LED turned OFF"); 
    }
  }
}
