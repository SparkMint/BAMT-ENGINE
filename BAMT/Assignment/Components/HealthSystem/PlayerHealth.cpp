#include "PlayerHealth.h"

void PlayerHealth::RemoveHealth(int healthToRemove)
{
	// Instead of removing health, this will instead lower the score multiplier from the player.
	if(scoreSystem != nullptr) scoreSystem->LowerScoreMultiplier();
	painTime = .2f;
}

void PlayerHealth::OnDead()
{

}