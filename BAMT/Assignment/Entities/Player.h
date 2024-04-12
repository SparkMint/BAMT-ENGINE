#ifndef BAMT_GAMEOBJECT
#define BAMT_GAMEOBJECT

#include "SpriteRenderer.h"
#include "RigidBody.h"
#include "Entity.h"
#include "Animator.h"
#include "../Components/KeyboardMovement.h"
#include "../Components/PowerupReciever.h"
#include "../Components/ScoreSystem.h"
#include "../Components/HealthSystem/PlayerHealth.h"
#include "../Components/WeaponSystem/PlayerWeapon.h"
#include "../Components/PlayerAnimationSystem.h"


class Player : public Entity
{
	const char* playerTag = "Player";

	public:
		RigidBody* rigidBody = nullptr;

		KeyboardMovement* playerMovement = nullptr;
		PlayerWeapon* weapon = nullptr;
		PlayerHealth* playerHealth = nullptr;
		PowerupReciever* powerupReciever = nullptr;
		ScoreSystem* scoreSystem = nullptr;

		// Transform Values
		Vector2 initialPosition = { BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE / 2, BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE / 2 };

		Animator* animator = nullptr;
		PlayerAnimationSystem* animationSystem = nullptr;

		// Size Values
		float width = .18f * 4;
		float height = .24f * 4;

		// Size Values
		float colliderWidth = .18f * 3;
		float colliderHeight = .24f * 3;

		// RigidBody Values
		float maxSpeed = 10;
		float dragForce = 5;
		float mass = 3;
		float bounciness = .2f;

		void Start() override;

		void Stop();
		void Reset();
};
#endif