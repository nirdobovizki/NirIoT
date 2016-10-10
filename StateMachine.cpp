// 
// 
// 

#include "StateMachine.h"

void StateMachineClass::GlobalActivity(IActivity* activity, int actionId)
{
	activity->Start(actionId);
	m_globalActivities.Add(activity);
}

void StateMachineClass::Start(State* state)
{
	m_currentState = state;
	m_currentState->Enter();
}

void StateMachineClass::SetCurrentState(State* state)
{
	m_currentState->Leave();
	m_currentState = state;
	m_currentState->Enter();
}

void StateMachineClass::Loop()
{
	for (int i = 0; i < m_globalActivities.GetCount() && !m_currentState->InTransition(); ++i) m_globalActivities.GetAt(i)->Loop();
	m_currentState->Loop();
}

void StateMachineClass::ProcessInput(IActivity* activity, int inputId)
{
	m_currentState->ProcessInput(activity, inputId);
}

StateMachineClass StateMachine;

