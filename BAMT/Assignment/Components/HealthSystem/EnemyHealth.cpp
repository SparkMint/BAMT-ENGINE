#include "EnemyHealth.h"

void EnemyHealth::Start()
{
	Health::Start();

	powerup = entity->scene->AddEntity();
	powerup->AddComponent<Powerup>();
	powerup->active = false;

	audioSource = entity->AddComponent<AudioSource>();
	audioSource->SetAudioClip(deathAudioClip);
}

void EnemyHealth::OnDead()
{
	int score = maxHealth * 10;

	const Enemy* myEnemy = dynamic_cast<Enemy*>(entity);
	if (myEnemy != nullptr)
	{
		myEnemy->scoreSystem->AddScore(score);
	}

	const int dropChance = rand() % 12;
	if(dropChance == 1)
	{
		Debug::Log("Powerup Dropped!");
		auto* powerupComponent = powerup->GetComponent<Powerup>();
		const PowerupType type = static_cast<PowerupType>(rand() % 4);
		powerupComponent->UpdateType(type);
		powerupComponent->audioSource->Play(powerupComponent->spawnSound);
		powerup->transform->SetPosition(entity->transform->GetPosition());
		powerup->active = true;
	}
	audioSource->Play();

	entity->active = false;
}

void EnemyHealth::DisablePowerup()
{
	powerup->active = false;
}
