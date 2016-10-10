NirIoT
---

A library for building arduino-environment-based devices (spacifically, Arduino and NodeMCU) using a declerative state machine

With this library you simply define states, what is active in each state and the transitions that causes the
system to change state.

For example, the blink sketch would be:

	#include <StateMachine.h>
	#include <State.h>
	#include <Timer.h>
	#include <DigitalWrite.h>

	// the system has an on state and an off state
	State stateOn;
	State stateOff;

	// we need a timer to know when to change state
	DigitalWrite outputLed;
	// and a led to turn on or off
	Timer ledChangeStateTimer;

	void setup()
	{
		// the led is on digital pin 13, default to off
		outputLed.Init(13, LOW);
		// we set the timer to half a second
		ledChangeStateTimer.Init(500);

		// off state:
		
		// the timer is running (non repeating)
		stateOff.Activity(&ledChangeStateTimer, Timer::CallOnce);
		// on timer tick change state to on
		stateOff.Transition(&ledChangeStateTimer, Timer::Tick, &stateOn);

		// on state :

		// the led is on
		stateOn.Activity(&outputLed, DigitalWrite::TurnOn);
		// the timer is running (non repeating)
		stateOn.Activity(&ledChangeStateTimer, Timer::CallOnce);
		// on timer tick change state to off
		stateOn.Transition(&ledChangeStateTimer, Timer::Tick, &stateOff);


		// the initial state is off
		StateMachine.Start(&stateOff);
	}

	void loop()
	{
		StateMachine.Loop();
	}


To install, place the library h/cpp files in a sub folder of your arduino librery folder (in Windows, it's Documents\Arduino\libraries)

