// 
// 
// 

#include "DigitalRead.h"
#include "StateMachine.h"

void DigitalRead::Init(int8_t pin)
{
	m_pin = pin;
	m_active = false;
}

void DigitalRead::Start(int actionId)
{
	switch (actionId)
	{
	case StartSampling:
		m_active = true;
		break;
	default:
		break;
	}
}

void DigitalRead::End(int actionId)
{
	switch (actionId)
	{
	case StartSampling:
		m_active = false;
		break;
	default:
		break;
	}
}

void DigitalRead::Loop()
{
	if (!m_active) return;
	StateMachine.ProcessInput(this, digitalRead(m_pin) ? OnHigh : OnLow);
}


