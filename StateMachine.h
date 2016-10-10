// StateMachine.h

#ifndef _STATEMACHINE_h
#define _STATEMACHINE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "State.h"
#include "IActivity.h"
#include "GrowingList.h"

class StateMachineClass
{
private:
	State* m_currentState;
	GrowingList<IActivity*> m_globalActivities;

public:
	void Start(State* state);
	void Loop();
	void GlobalActivity(IActivity* activity, int actionId);
	void ProcessInput(IActivity* activity, int inputId);

	void SetCurrentState(State* state);

};

extern StateMachineClass StateMachine;

#endif

