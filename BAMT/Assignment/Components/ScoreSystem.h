#ifndef ASSIGNMENT_SCORE_SYSTEM
#define ASSIGNMENT_SCORE_SYSTEM

#include "Component.h"

class ScoreSystem : public Component
{
	float time = 0;
	float multiplierChangeTime = 7;

	const int noScoreMultiplier = 1;
	const int lowScoreMultiplier = 2;
	const int medScoreMultiplier = 4;
	const int highScoreMultiplier = 8;

	public:
		int score = 0;
		int scoreMultiplier = 1;

		bool doubleMultiplier;

		void Start() override;
		void Update(float* timeStep) override;

		void AddScore(int scoreAmount);


		void LowerScoreMultiplier();
		void RaiseScoreMultiplier();

		void UpdateMultiplierText();
		void Reset();
};
#endif