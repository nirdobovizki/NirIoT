// DigitalRead.h

#ifndef _DIGITALREAD_h
#define _DIGITALREAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IActivity.h"

class DigitalRead : public IActivity
{
private:
	int8_t m_pin;
	bool m_active;

public:
	enum Activities
	{
		StartSampling
	};

	enum Inputs
	{
		OnHigh,
		OnLow,
	};

	void Init(int8_t pin);

	virtual void Start(int actionId);
	virtual void End(int actionId);
	virtual void Loop();
};


#endif

