// AnalogWrite.h

#ifndef _ANALOGWRITE_h
#define _ANALOGWRITE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IActivity.h"

class AnalogWrite : public IActivity
{
	int8_t m_pin;
	uint8_t m_currentValue;
	uint8_t m_currentDirection;
	unsigned long m_nextStep;
public:
	enum Actions
	{
		SlowSweep,
	};

	void Init(int8_t pin);
	virtual void Start(int actionId);
	virtual void End(int actionId);
	virtual void Loop();
};


#endif

