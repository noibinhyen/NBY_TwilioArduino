#include "NBY_Twilio.h"
#include <base64.h>

NBY_Twilio::NBY_Twilio(String accountSid, String authToken)
{
    this->accountSid = accountSid;
    this->authToken = authToken;
}

int NBY_Twilio::makeCall(String fromNumber, String toNumber)
{
    HTTPClient http;
    String url = "https://api.twilio.com/2010-04-01/Accounts/";
    url += accountSid;
    url += "/Calls.json";

    http.begin(url);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String str = "";
    str = this->accountSid + ":" + this->authToken;
    http.addHeader("Authorization", "Basic " + base64::encode(str));

    String payload = "";
    payload = "To=" + toNumber + "&From=" + fromNumber + "&Url=" + callUrl;

    int httpCode = http.POST(payload);

    return httpCode;
}

int NBY_Twilio::makeSms(String fromNumber, String toNumber, String messages)
{
    HTTPClient http;

    String url = "https://api.twilio.com/2010-04-01/Accounts/";
    url += accountSid;
    url += "/Messages.json";
    http.begin(url);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String str = "";
    str = this->accountSid + ":" + this->authToken;
    http.addHeader("Authorization", "Basic " + base64::encode(str));

    String payload = "";
    payload = "To=" + toNumber + "&From=" + fromNumber + "&Body=" + messages;
    int httpCode = http.POST(payload);

    return httpCode;
}