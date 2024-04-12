#include "ScoreSystem.h"

void ScoreSystem::Start()
{
}

void ScoreSystem::Update(float* timeStep)
{
	if(time < multiplierChangeTime)	time += *timeStep;
	else RaiseScoreMultiplier();
}
	
void ScoreSystem::AddScore(int scoreAmount)
{
	int multiplier = scoreMultiplier;
	if (doubleMultiplier) multiplier *= 2;

	score += scoreAmount * multiplier;
	Debug::Log("Score Added! Value: " 
		+ std::to_string(scoreAmount) + ", Multiplier: X" 
		+ std::to_string(multiplier) + " = " 
		+ std::to_string(scoreAmount * multiplier));

	Debug::Log("Current Player Score = " + std::to_string(score));
}

void ScoreSystem::LowerScoreMultiplier()
{
	time = 0;
	if(scoreMultiplier == lowScoreMultiplier) 
	{
		scoreMultiplier = noScoreMultiplier;
	}
	else if (scoreMultiplier == medScoreMultiplier)
	{
		scoreMultiplier = lowScoreMultiplier;
	}
	else if (scoreMultiplier == highScoreMultiplier)
	{
		scoreMultiplier = medScoreMultiplier;
	}
}

void ScoreSystem::RaiseScoreMultiplier()
{
	time = 0;
	if (scoreMultiplier == noScoreMultiplier)
	{
		scoreMultiplier = lowScoreMultiplier;
	}
	else if (scoreMultiplier == lowScoreMultiplier)
	{
		scoreMultiplier = medScoreMultiplier;
	}
	else if (scoreMultiplier == medScoreMultiplier)
	{
		scoreMultiplier = highScoreMultiplier;
	}
}

void ScoreSystem::Reset()
{
	score = 0;
	doubleMultiplier = false;
	scoreMultiplier = 1;
}