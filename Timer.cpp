// 
// 
// 

#include "Timer.h"
#include "StateMachine.h"

void Timer::Init(unsigned long timeout)
{
	m_timeout = timeout;
	m_nextActivation = 0;
}

void Timer::Start(int actionId)
{
	switch (actionId)
	{
	case CallOnce:
		m_nextActivation = millis() + m_timeout;
		if (m_nextActivation == 0)m_nextActivation = 1;
		Serial.print("Timer armed to ");
		Serial.print(m_nextActivation);
		Serial.println();
		break;
	default:
		break;
	}
}

void Timer::End(int actionId)
{
	switch (actionId)
	{
	case CallOnce:
		m_nextActivation = 0;
		break;
	default:
		break;
	}
}

void Timer::Loop()
{
	if (m_nextActivation)
	{
		Serial.println(m_nextActivation - millis());
	}
	if (m_nextActivation != 0 && millis() >= m_nextActivation && millis() - m_nextActivation < 0x0FFFFFFF)
	{
		StateMachine.ProcessInput(this, Tick);
		m_nextActivation = 0;
	}
}
