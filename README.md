# NBY_TwilioArduino

Library for using Twilio's services with Arduino boards.

## Currently supported:

### Twilio's services:

- Make a phone call
- Send SMS

### Arduino boards:

- Any boards that support `HTTPClient` library.

## Steps to use

1. Create an account on `Twilio` home page if you don't have anyone.
2. Create(buy) a new number for using services, setup `to number` for required services.
3. Find and copy the `ACCOUNT_SID` AND `AUTH_TOKEN` for using in code.
4. Follow the code in `examples` folder or the code below.

## Examples

```cpp
/**
 * Make call example code
 */
#include <Arduino.h>
#include <HTTPClient.h>
#include <NBY_TwilioArduino.h>

const char* ssid = "MY_SSID";
const char* password = "MY_PASSWORD";
const String accountSid = "MY_ACCOUNT_SID";
const String authToken = "MY_AUTH_TOKEN";
String fromNumber = "FORM_NUMBER";
String toNumber = "TO_NUMBER";

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
    twilio.makeCall(fromNumber, toNumber);
}

void loop()
{
}
```

```cpp
/**
 * Send SMS example code
 */
#include <Arduino.h>
#include <HTTPClient.h>
#include <NBY_TwilioArduino.h>

const char* ssid = "MY_SSID";
const char* password = "MY_PASSWORD";
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
```

> Notice that replace some fields like `ssid`, `password`, `accountSid`, `authToken`, `fromNumber`, `toNumber`, `message` with your owns.

## License

MIT License

Copyright (c) 2023 NBY

## Authors

- [noibinhyen](https://noibinhyen.tech)

## Contributors

- [Bùi Đức Nhật](https://github.com/buiducnhat)
- [Hải Đức](https://github.com/HaiDuc57)
