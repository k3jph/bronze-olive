#include <morse.h>
#include <SPI.h>
#include <RH_RF22.h>

float operatingFrequency = 432.330;
int pwmFreq = 64;
int keyPin = 6;

String message = String("K3JPH/B Columbia, Maryland");

// Singleton instance of the radio driver
RH_RF22 rf22;
PWMMorseSender sender(keyPin, 25, pwmFreq);

void setup()
{
  Serial.begin(9600);
  if (!rf22.init())
    Serial.println("init failed");
  
  rf22.setFrequency(operatingFrequency);
  rf22.setModemConfig(RH_RF22::UnmodulatedCarrier);
  rf22.setModeTx();
  rf22.setTxPower(RH_RF22_TXPOW_20DBM);

  sender.setup();
  sender.setMessage(message);
}

void loop()
{
  if (!sender.continueSending()) {
    sender.startSending();
  }
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
