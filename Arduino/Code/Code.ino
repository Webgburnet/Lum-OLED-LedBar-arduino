#include <Wire.h>
#include "Grove_LED_Bar.h"
#include "SeeedOLED.h"

const int DIO = 2;
const int CLK = 3;
const int Lum = A0;

Grove_LED_Bar bar(CLK, DIO, 0);

void setup()
{    
	Serial.begin(9600);
    bar.begin();
    bar.setGreenToRed(true);
    
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


