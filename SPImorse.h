/*
 *
 */

class SPIMorseSender: public MorseSender {
 private:
	byte f;
	byte spiRegister;
	RH_RF22 *radio;
	
 protected:
	virtual void setOn() {
//    		radio->spiWrite(0x73, f);
      radio->setFrequency(sendFrequency);
	}

	virtual void setOff() {
//		radio->spiWrite(0x73, 0);
      radio->setFrequency(baseFrequency);
}
	
 public:
 SPIMorseSender(RH_RF22 *r, float wpm = WPM_DEFAULT, byte freq = 0x03)
	 : MorseSender(0, wpm) { 
		setFreq(freq);
		radio = r;
	}

	void setFreq(byte freq) { f = freq; }
};
