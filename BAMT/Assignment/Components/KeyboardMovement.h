#ifndef ASSIGNMENT_PLAYER_MOVEMENT
#define ASSIGNMENT_PLAYER_MOVEMENT

#include "Input.h"
#include "RigidBody.h"
#include "Component.h"
#include "TrailRenderer.h"

class KeyboardMovement : public Component
{
	RigidBody* _rigidBody = nullptr;
	TrailRenderer* trailRenderer = nullptr;

	public:
		float baseMovementSpeed = 5;
		float powerupMovementSpeed = 8;
		float currentMovementSpeed = 5;

		void Start() override;
		void Update(float* timeStep) override;

		void Stop();
		void Reset();
};
#endif