#include <ESP8266WiFi.h> 
#include <WiFiClientSecure.h> 
#include <TelegramBot.h> 

// Initialize Wifi connection to the router 
const char* ssid     = "SSID"; 
const char* password = "password"; 

// Initialize Telegram BOT 
// In order to create new bot start a chat with BotFather on Telegram
// Create a new BOT and then past here the token
const char BotToken[] = "API-KEY"; 
WiFiClientSecure net_ssl; 
TelegramBot bot (BotToken, net_ssl); 

 
void setup()  
{   
  Serial.begin(115200);   
  while (!Serial) {}  //Start running when the serial is open  
  delay(3000);   
  // attempt to connect to Wifi network:   
  Serial.print("Connecting Wifi: ");   
  Serial.println(ssid);
  WiFi.begin(ssid, password);   
  while (WiFi.status() != WL_CONNECTED)  
  {    
    Serial.print(".");   
    delay(500);   
  }   
  Serial.println("");   
  Serial.println("WiFi connected");   
  bot.begin();      
}   


void loop()  
{   
  message m = bot.getUpdates(); // Read new messages   
  if (m.text.equals("on"))
  {
    // Send a messagge on the serial in order to make Arduino do something   
    Serial.println("1");    
    bot.sendMessage(m.chat_id, "The Led is now ON");   
  }   
  else if (m.text.equals("off"))  
  {
    // Send a messagge on the serial in order to make Arduino do something   
    Serial.println("0");   
    bot.sendMessage(m.chat_id, "The Led is now OFF");   
  }   
} 
