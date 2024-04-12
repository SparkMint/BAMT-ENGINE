#ifndef ASSIGNMENT_ENEMY_ANIMATION_SYSTEM
#define ASSIGNMENT_ENEMY_ANIMATION_SYSTEM

#include "Animator.h"
#include "Component.h"
#include "EnemyMovement.h"
#include "RigidBody.h"

class EnemyAnimationSystem : public Component
{
	float _time = 0;
	float _lastHealth = 0;
	public:
		void Start() override;
		void Update(float* timeStep)override;

		float _painTime = .2f;

		Animator* animator = nullptr;
		EnemyMovement* movementSystem;
		Animation* walkRightAnim = nullptr;
		Animation* walkLeftAnim = nullptr;
};
#endif