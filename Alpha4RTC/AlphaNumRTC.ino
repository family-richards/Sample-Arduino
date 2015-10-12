// Simple sketch to read the time from the DS1307 RTC and set it on the Alphanumeric 4 character display.

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "RTClib.h"


Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
RTC_DS1307 rtc;

int lastHour = -1;
int lastMinute = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  alpha4.begin(0x70);  // pass in the address

  initializeDisplay();

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  updateTime();
  delay(500);
}

void initializeDisplay()
{
  // Display a little start-up sequence in the alpha numeric display.
  
  alpha4.writeDigitRaw(3, 0x0);
  alpha4.writeDigitRaw(0, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(0, 0x0);
  alpha4.writeDigitRaw(1, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(1, 0x0);
  alpha4.writeDigitRaw(2, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(2, 0x0);
  alpha4.writeDigitRaw(3, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  
  alpha4.clear();
  alpha4.writeDisplay();
}

void updateTime()
{
  DateTime now = rtc.now();

  int hourNow = now.hour();
  int minuteNow = now.minute();

  // Update the clock if we have something new to display.
  
  if (lastHour != hourNow || lastMinute != minuteNow)
  {
    bool isPM = hourNow >= 12;
    lastHour = hourNow;
    lastMinute = minuteNow;

    // If hour is greater than twelve then adjust down.
    // If equal to zero, set to 12 (midnight).
    
    if (hourNow > 12)
    {
      hourNow -= 12;
    }
    else if (hourNow == 0)
    {
      hourNow = 12;
    }

    // First digit: either a 1 or blank.
    
    if (hourNow > 9)
    {
      alpha4.writeDigitAscii(0, '1');
    }
    else
    {
      alpha4.writeDigitAscii(0, ' ');      
    }
    
    alpha4.writeDigitAscii(1, '0' + hourNow % 10, true); // Show a dot between hour & minute
    alpha4.writeDigitAscii(2, '0' + minuteNow / 10);
    alpha4.writeDigitAscii(3, '0' + minuteNow % 10, isPM); // Show a dot for PM
    alpha4.writeDisplay();
  }  
}

