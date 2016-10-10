// IActivity.h

#ifndef _IACTIVITY_h
#define _IACTIVITY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class IActivity
{
public:
	virtual void Start(int actionId) = 0;
	virtual void End(int actionId) = 0;
	virtual void Loop() = 0;
};


#endif

