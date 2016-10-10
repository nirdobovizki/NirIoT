// 
// 
// 

#include "AnalogWrite.h"

void AnalogWrite::Init(int8_t pin)
{
	m_pin = pin;
	m_currentValue = 0;
	m_currentDirection = 0;
}

void AnalogWrite::Start(int actionId)
{
	switch (actionId)
	{
	case SlowSweep:
		m_currentDirection = 1;
		m_nextStep = millis();
	default:
		break;
	}
}
void AnalogWrite::End(int actionId)
{
	switch (actionId)
	{
	case SlowSweep:
		analogWrite(m_pin, 0);
		m_currentDirection = 0;
	default:
		break;
	}

}
void AnalogWrite::Loop()
{
	if (m_currentDirection != 0 && millis() >= m_nextStep && millis() - m_nextStep < 0x0FFF)
	{
		if (m_currentDirection == 1 && m_currentValue == 255) m_currentDirection = 2;
		if (m_currentDirection == 2 && m_currentValue == 0) m_currentDirection = 1;
		if (m_currentDirection == 1) ++m_currentValue; else --m_currentValue;
		analogWrite(m_pin, m_currentValue);
		m_nextStep = millis() + 10;
	}
}
