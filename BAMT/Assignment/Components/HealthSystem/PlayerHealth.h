#ifndef ASSIGNMENT_PLAYER_HEALTH
#define ASSIGNMENT_PLAYER_HEALTH

#include "Health.h"
#include "../ScoreSystem.h"

class PlayerHealth : public Health
{
	public:
		ScoreSystem* scoreSystem = nullptr;

		explicit PlayerHealth(int health = 0) : Health(health) {}

		void RemoveHealth(int healthToRemove) override;
		void OnDead() override;
};
#endif