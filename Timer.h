// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IActivity.h"

class Timer : public IActivity
{
private:
	unsigned long m_nextActivation;
	unsigned long m_timeout;

public:
	enum Actions
	{
		CallOnce
	};

	enum Inputs
	{
		Tick
	};

	void Init(unsigned long timeout);
	virtual void Start(int actionId);
	virtual void End(int actionId);
	virtual void Loop();
};


#endif

