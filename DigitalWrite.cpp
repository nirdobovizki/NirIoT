// 
// 
// 

#include "DigitalWrite.h"
#include "StateMachine.h"

void DigitalWrite::Init(int8_t pin, int8_t defaultState)
{
	m_pin = pin;
	m_offState = defaultState;
	m_nextToggle = 0;
	m_state = 0;
	pinMode(pin, OUTPUT);
	digitalWrite(pin, defaultState);
}

void DigitalWrite::Start(int actionId)
{
	switch (actionId)
	{
	case TurnOn:
		digitalWrite(m_pin, m_offState ? LOW : HIGH);
		m_state = 1;
		break;
	case SlowBlink:
		m_nextToggle = millis() + SlowBlinkHalfCycleLength;
		m_state = 2;
		break;
	case FastBlink:
		m_nextToggle = millis() + FastBlinkHalfCycleLength;
		m_state = 4;
		break;
	case SlowPulse:
		digitalWrite(m_pin, m_offState ? LOW : HIGH);
		m_nextToggle = millis() + SlowPulseLength;
		m_state = 6;
		break;
	default:
		break;
	}
}

void DigitalWrite::End(int actionId)
{
	switch (actionId)
	{
	case TurnOn:
		if(m_state == 1) digitalWrite(m_pin, m_offState);
		break;
	case SlowBlink:
		if (m_state == 3) digitalWrite(m_pin, m_offState);
		break;
	case FastBlink:
		if (m_state == 5) digitalWrite(m_pin, m_offState);
		break;
	case SlowPulse:
		if (m_state == 6) digitalWrite(m_pin, m_offState);
		break;
	default:
		break;
	}
	m_state = 0;
}
void DigitalWrite::Loop()
{
	if (m_state >= 2 && m_state <= 6 && millis() >= m_nextToggle && millis() - m_nextToggle < 0x0FFF)
	{
		if (m_state == 2 || m_state == 4) digitalWrite(m_pin, HIGH);
		else digitalWrite(m_pin, LOW);

		switch (m_state)
		{
		case 2:
			m_state = 3;
			m_nextToggle = millis() + SlowBlinkHalfCycleLength;
			break;
		case 3:
			m_state = 2;
			m_nextToggle = millis() + SlowBlinkHalfCycleLength;
			break;
		case 4:
			m_state = 5;
			m_nextToggle = millis() + FastBlinkHalfCycleLength;
			break;
		case 5:
			m_state = 4;
			m_nextToggle = millis() + FastBlinkHalfCycleLength;
			break;
		case 6:
			m_state = 0;
			m_nextToggle = 0;
			StateMachine.ProcessInput(this, EndPulse);
			break;
		}
	}
}
