// NetworkDetect.h

#ifndef _NETWORKDETECT_h
#define _NETWORKDETECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "IActivity.h"

class NetworkDetect : public IActivity
{
private:
	bool m_detectNow;
	String m_networkName;
public:
	enum Actions
	{
		DetectNow
	};
	enum Inputs
	{
		Found,
		NotFound
	};
	void Init(String networkSSID);
	virtual void Start(int actionId);
	virtual void End(int actionId);
	virtual void Loop();
};


#endif

