#include <Wire.h>
#include "Grove_LED_Bar.h"
#include "SeeedOLED.h"

Grove_LED_Bar bar(3, 2, 0);

const int CLK = 1;
const int DIO = 2;
const int Lum = A0;

void setup()
{
    bar.begin();
    bar.setGreenToRed(true);

    Serial.begin(9600);
    
    Wire.begin();
    SeeedOled.init();
    SeeedOled.clearDisplay();
    SeeedOled.setNormalDisplay();
    SeeedOled.setPageMode();
    SeeedOled.setTextXY(0, 0);
    SeeedOled.putString("Bus de terrain 2");
      
    delay(2000);
}

void loop()
{
    int val=analogRead(Lum);
    int conv=map(val, 0, 800, 0, 10);
    
    SeeedOled.setTextXY(2, 0);
    SeeedOled.putNumber(val);
    
    bar.setLevel(conv);
}


