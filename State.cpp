// 
// 
// 

#include "State.h"
#include "StateMachine.h"

State::State() : m_switchingTo(NULL)
{

}

void State::Activity(IActivity* activity, int actionId)
{
	ActivityInfo ai;
	ai.Activity = activity;
	ai.ActionId = actionId;
	m_activities.Add(ai);
}

void State::Transition(IActivity* activity, int inputId, State* toState)
{
	TransitionInfo ti;
	ti.Activity = activity;
	ti.InputId = inputId;
	ti.ToState = toState;
	m_transitions.Add(ti);
}

// internal
void State::Enter()
{
	for (int i = 0; i < m_activities.GetCount(); ++i) m_activities.GetAt(i).Activity->Start(m_activities.GetAt(i).ActionId);
}

void State::Leave()
{
	for (int i = m_activities.GetCount() - 1; i >= 0; --i) m_activities.GetAt(i).Activity->End(m_activities.GetAt(i).ActionId);
}

void State::Loop()
{
	for (int i = 0; i < m_activities.GetCount() && m_switchingTo == NULL; ++i) m_activities.GetAt(i).Activity->Loop();
	if (m_switchingTo != NULL)
	{
		StateMachine.SetCurrentState(m_switchingTo);
		m_switchingTo = NULL;
	}
}

void State::ProcessInput(IActivity* activity, int inputId)
{
	for(int i=0;i<m_transitions.GetCount();++i)
		if (m_transitions.GetAt(i).Activity == activity &&
			m_transitions.GetAt(i).InputId == inputId)
		{
			m_switchingTo = m_transitions.GetAt(i).ToState;
			return;
		}
}
