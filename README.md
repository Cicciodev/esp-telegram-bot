# esp-telegram-bot
First project of a Telegram BOT to control an Arduino sending message to an ESP


# Step

1 - Initialize Telegram Bot writing to BotFather in telegram (send *new* and follow instruction to initialize your first bot). You'll receive an API-KEY

2 - In Arduino install library TelgramBot-Library (https://github.com/CasaJasmina/TelegramBot-Library)

3 - Modify (insert Wi-Fi auth and API-KEY) and then upload telegram-bot.ino into an ESP (I've used and ESP-01)

4 - Upload LED_0_1.ino into an Arduino (I've used an Arduino UNO)

# First Example Explained
I've choosen to control a LED with Arduino, but if you use a different ESP you can control whatever you want directly with the ESP. In order to see DEBUG message I've used pin 3 and 4 to connect ESP TX and RX (take a look at scheme.png)
In telegram-bot.ino you decide how to interact with both telegram bot and Arduino.
