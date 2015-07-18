#include <SPI.h>
#include <RH_RF22.h>

float operatingFrequency = 432.330;
int pwmFreq = 96;
int keyPin = 6;

// Singleton instance of the radio driver
RH_RF22 rf22;

void setup()
{
  pinMode(keyPin, OUTPUT);      // sets the digital pin as output

  Serial.begin(9600);
  if (!rf22.init())
    Serial.println("init failed");
  
  rf22.setFrequency(operatingFrequency);
  rf22.setModemConfig(RH_RF22::UnmodulatedCarrier);
  rf22.setModeTx();
  rf22.setTxPower(RH_RF22_TXPOW_1DBM);
}

void loop()
{
  Serial.println("loop failed");
  dot(); 
  dash(); 
  dot();
  delay(1000);
}

void dot()
{
  analogWrite(keyPin, pwmFreq);
  delay(250);
  analogWrite(keyPin, -0);
  delay(250);
}

void dash()
{
  analogWrite(keyPin, pwmFreq);
  delay(750);
  analogWrite(keyPin, -0);
  delay(250);
}
