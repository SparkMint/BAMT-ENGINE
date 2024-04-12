#ifndef ASSIGNMENT_ENEMY_MOVEMENT
#define ASSIGNMENT_ENEMY_MOVEMENT

#include "RigidBody.h"
#include "Component.h"

class EnemyMovement : public Component
{
	RigidBody* _rigidBody = nullptr;

	public:
		Entity* target = nullptr;

		float movementSpeed = 1;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif