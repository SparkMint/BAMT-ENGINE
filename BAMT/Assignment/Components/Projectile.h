#ifndef ASSIGNMENT_PROJECTILE
#define ASSIGNMENT_PROJECTILE

#include "AudioSource.h"
#include "Component.h"
#include "RigidBody.h"
#include "SpriteRenderer.h"
#include "TrailRenderer.h"
#include "HealthSystem/Health.h"

/// <summary>
/// Projectiles can be fired by enemies and the player. They collide with everything
///	but themselves and whoever fired them.
/// </summary>
class Projectile : public Component
{
	Vector2 previousPosition = VECTOR2_ZERO;
		const char* projectileTag = "Projectile";

		float time = 0;

	public:
		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;
		AudioSource* audioSource = nullptr;

		const char* collisionSound = "projectileHit.wav";
		int projectileDamage = 0;
		float projectileKnockback = 0;
		float projectileLifetime = 1;

		RigidBody* whoSpawnedMe;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif
