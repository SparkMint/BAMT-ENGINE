#include "TickTimer.h"
#include "Debug.h"

TickTimer::TickTimer()
{
	//Debug::Log("Tick Timer Created.", this);
	startTicks = 0;
}

TickTimer::~TickTimer()
{
	Debug::Log("Tick Timer Destroyed.", this);
}

void TickTimer::ResetTimer()
{
	startTicks = SDL_GetTicks();
}

int TickTimer::GetTicks() const
{
	return (SDL_GetTicks() - startTicks);
}
