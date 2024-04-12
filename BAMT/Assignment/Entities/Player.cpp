#include "Player.h"

void Player::Start()
{
	tag = playerTag;
	renderLayer = 2;

	// Transform Setup
	transform->SetPosition(&initialPosition);

	for (auto entity : scene->entityList)
	{
		auto* potentialScoreSystem = entity->GetComponent<ScoreSystem>();
		if (potentialScoreSystem == nullptr) continue;

		scoreSystem = potentialScoreSystem;
	}
	if (scoreSystem == nullptr) Debug::LogWarn("No scoreSystem found on the player! Score will not be counted!", this);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->width = colliderWidth;
	rigidBody->height = colliderHeight;
	rigidBody->mass = mass;
	rigidBody->maxVelocity = maxSpeed;
	rigidBody->drag = dragForce;
	rigidBody->bounciness = bounciness;

	// Sprite Renderer Setup
	animator = AddComponent<Animator>();
	animator->width = width;
	animator->height = height;
	animator->animate = true;

	animationSystem = AddComponent<PlayerAnimationSystem>();

	// Player Movement Setup
	playerMovement = AddComponent<KeyboardMovement>();


	playerHealth = AddComponent<PlayerHealth>();
	playerHealth->scoreSystem = scoreSystem;

	// Pistol Setup
	weapon = AddComponent<PlayerWeapon>();
	weapon->maxProjectiles = 20;
	weapon->Init();

	powerupReciever = AddComponent<PowerupReciever>();
	powerupReciever->scoreSystem = scoreSystem;
}

void Player::Stop()
{
	weapon->entityPool->DisableAllEntities();
	playerMovement->Stop();

	active = false;
}

void Player::Reset()
{
	transform->SetPosition(&initialPosition);
	rigidBody->velocity = VECTOR2_ZERO;
	weapon->weaponData = &weapon->defaultWeapon;
	playerMovement->Reset();

	active = true;
}