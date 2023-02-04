#include <Arduino.h>
#include <HTTPClient.h>
#include <NBY_TwilioArduino.h>

const String accountSid = "MY_ACCOUNT_SID";
const String authToken = "MY_AUTH_TOKEN";
String fromNumber = "FORM_NUMBER";
String toNumber = "TO_NUMBER";
String message = "Hello Noi binh yen";

void setup()
{
    Serial.begin(115200);
    Serial.print("Connecting to WiFi network: ");
    Serial.print(ssid);
    Serial.println(".");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("Connected!");
    NBY_Twilio twilio = NBY_Twilio(accountSid, authToken);
    twilio.makeSms(fromNumber, toNumber,message);
}

void loop()
{
}