#ifndef NBY_TWILIO_H_H
#define NBY_TWILIO_H_H

#include <Arduino.h>
#include <string>
#include <HTTPClient.h>

class NBY_Twilio
{
private:
    String accountSid;
    String authToken;
    const String callUrl = "http://twimlets.com/holdmusic?Bucket=com.twilio.music.ambient";

public:
    NBY_Twilio(String accountSid,String authToken);
    int makeCall(String fromNumber,String toNumber);
    int makeSms(String fromNumber,String toNumber,String messages);
};

#endif