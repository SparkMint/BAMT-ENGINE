#ifndef BAMT_TICK_TIMER
#define BAMT_TICK_TIMER

#include"SDL.h"

/// <summary>
/// This class makes sure that Ticks are a specified currentTimeSeconds
/// to prevent game logic acting oddly.
/// </summary>
class TickTimer 
{
	int startTicks;

	public:
		TickTimer();
		~TickTimer();

		/// <summary>
		/// Sets start ticks to the current currentTimeSeconds.
		/// </summary>
		void ResetTimer();

		///<returns>Amount of ticks that has passed since the timer was reset.</returns>
		int GetTicks() const;
};
#endif