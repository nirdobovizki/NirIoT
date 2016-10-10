// DigitalWrite.h

#ifndef _DIGITALWRITE_h
#define _DIGITALWRITE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IActivity.h"

class DigitalWrite : public IActivity
{
private:
	int8_t m_pin;
	int8_t m_offState;
	unsigned long m_nextToggle;
	int m_state;
public:
	enum Actions
	{
		TurnOn,
		SlowBlink,
		FastBlink,
		SlowPulse,
	};

	enum Inputs
	{
		EndPulse
	};

	unsigned long SlowPulseLength;
	unsigned long SlowBlinkHalfCycleLength;
	unsigned int FastBlinkHalfCycleLength;

	DigitalWrite() :SlowBlinkHalfCycleLength(3000), FastBlinkHalfCycleLength(500), SlowPulseLength(10000) {}

	void Init(int8_t pin, int8_t defaultState);
	virtual void Start(int actionId);
	virtual void End(int actionId);
	virtual void Loop();
};


#endif

