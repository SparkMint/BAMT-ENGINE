#ifndef ASSIGNMENT_TIME_SYSTEM
#define ASSIGNMENT_TIME_SYSTEM

#include "Component.h"
#include "ScoreSystem.h"

class TimeSystem : public Component
{
	public:
		ScoreSystem* scoreSystem = nullptr;

		float currentTimeSeconds = 0;
		float timeLimitSeconds = 45;
		
		int timeExtendScoreRequirement = 5000;

		bool timeExtended = false;

		void Start() override;
		void Update(float* timeStep) override;

		void Stop();
		void Reset();
};
#endif