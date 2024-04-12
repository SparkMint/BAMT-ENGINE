#ifndef ASSIGNMENT_ENEMY
#define ASSIGNMENT_ENEMY

#include "Animator.h"
#include "Entity.h"
#include "RigidBody.h"
#include "../Components/WeaponSystem/EnemyWeapon.h"
#include "../Components/HealthSystem/EnemyHealth.h"
#include "../Components/EnemyMovement.h"
#include "../Components/EnemyAnimationSystem.h"
#include "../Components/EnemyData.h"

class EnemyHealth;

class Enemy : public Entity
{
	const char* enemyTag = "Enemy";

	public:
		Entity* target = nullptr;

		RigidBody* rigidBody = nullptr;
		EnemyAnimationSystem* animationSystem = nullptr;
		Animator* animator = nullptr;
		EnemyMovement* movement = nullptr;
		EnemyHealth* health = nullptr;
		EnemyWeapon* weapon = nullptr;
		ScoreSystem* scoreSystem = nullptr;

		EnemyData enemyData = ENEMY_ZOMBIE;

		void Start() override;
		void Update(float* timeStep) override;

		void Init();
		void UpdateTarget(Entity* newTarget);

		void Stop();
		void Restart();
};
#endif