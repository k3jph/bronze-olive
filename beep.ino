#include <morse.h>
#include <SPI.h>
#include <RH_RF22.h>

String message = String("K3JPH/B Bronze Olive");
float baseFrequency = 432.330;
float sendFrequency = baseFrequency + 0.000300;

#include "SPImorse.h"

RH_RF22 rf22;
SPIMorseSender sender(&rf22, 10, 0x03);

void setup()
{
	Serial.begin(9600);

	if (!rf22.init())
		Serial.println("init failed");
	
	rf22.setTxPower(RH_RF22_TXPOW_17DBM);
	rf22.setFrequency(baseFrequency);
	rf22.setModemConfig(RH_RF22::UnmodulatedCarrier);
	rf22.setModeTx();
	
	sender.setup();
	sender.setMessage(message);
}

void loop()
{

	if (!sender.continueSending()) {
		sender.startSending();
	}
}
