#ifndef ASSIGNMENT_ENEMY_HEALTH
#define ASSIGNMENT_ENEMY_HEALTH

#include "AudioSource.h"
#include "Health.h"
#include "../Powerup.h"
#include "../../Entities/Enemy.h"

class EnemyHealth : public Health
{
	public:
		Entity* powerup = nullptr;
		AudioSource* audioSource = nullptr;
		const char* deathAudioClip = "enemyDeath.wav";

		explicit EnemyHealth(int health) : Health(health){}

		void OnDead() override;
		void Start() override;
		void DisablePowerup();
};
#endif