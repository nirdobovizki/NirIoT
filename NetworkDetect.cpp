// 
// 
// 

#include "NetworkDetect.h"
#include "ESP8266WiFi.h"
#include "StateMachine.h"

void NetworkDetect::Init(String networkSSID)
{
	m_detectNow = false;
	m_networkName = networkSSID;
}

void NetworkDetect::Start(int actionId)
{
	switch (actionId)
	{
	case DetectNow:
		m_detectNow = true;
	default:
		break;
	}
}
void NetworkDetect::End(int actionId)
{
	switch (actionId)
	{
	case DetectNow:
		m_detectNow = false;
	default:
		break;
	}
}
void NetworkDetect::Loop()
{
	if (m_detectNow)
	{
		m_detectNow = false;
		int numSsid = WiFi.scanNetworks();
		if (numSsid == -1) 
		{
			Serial.println("No networks");
			StateMachine.ProcessInput(this, NotFound);
			return;
		}

		for (int thisNet = 0; thisNet < numSsid; thisNet++) 
		{
			if (WiFi.SSID(thisNet) == m_networkName)
			{
				Serial.println("found");
				StateMachine.ProcessInput(this, Found);
				return;
			}
			else
			{
				Serial.println(WiFi.SSID(thisNet));
			}
		}
		StateMachine.ProcessInput(this, NotFound);
	}
}
