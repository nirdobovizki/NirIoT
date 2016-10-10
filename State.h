// State.h

#ifndef _STATE_h
#define _STATE_h

#include "arduino.h"

#include "IActivity.h"
#include "GrowingList.h"

class State
{
private:
	struct ActivityInfo
	{
		IActivity* Activity;
		int ActionId;
	};
	struct TransitionInfo
	{
		IActivity* Activity;
		int InputId;
		State* ToState;
	};
	GrowingList<ActivityInfo> m_activities;
	GrowingList<TransitionInfo> m_transitions;
	State* m_switchingTo;
public:
	State();
	void Activity(IActivity* activity, int actionId);
	void Transition(IActivity* activity, int inputId, State* toState);

	// internal
	void Enter();
	void Leave();
	void Loop();
	void ProcessInput(IActivity* activity, int inputId);
	bool InTransition() { return m_switchingTo != NULL; }
};


#endif

