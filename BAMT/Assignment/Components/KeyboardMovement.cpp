#include "KeyboardMovement.h"

void KeyboardMovement::Start()
{
	 _rigidBody = entity->GetComponent<RigidBody>();
	 if (_rigidBody == nullptr) _rigidBody = entity->AddComponent<RigidBody>();


	 trailRenderer = entity->AddComponent<TrailRenderer>();
	 trailRenderer->colour = BAMT_COLOUR_BLUE;
	 trailRenderer->InitializeTrail(20, .25f);

	 trailRenderer->ShowTrail(false);
}

void KeyboardMovement::Update(float* timeStep)
{
	float speed = currentMovementSpeed * 10;

	if (Input::GetKeyHold(SDLK_w)) _rigidBody->AddForce(VECTOR2_UP, speed * *timeStep);

	if (Input::GetKeyHold(SDLK_s)) _rigidBody->AddForce(VECTOR2_DOWN, speed * *timeStep);

	if (Input::GetKeyHold(SDLK_a)) _rigidBody->AddForce(VECTOR2_LEFT, speed * *timeStep);

	if (Input::GetKeyHold(SDLK_d)) _rigidBody->AddForce(VECTOR2_RIGHT, speed * *timeStep);

	trailRenderer->ShowTrail(currentMovementSpeed == powerupMovementSpeed);
}

void KeyboardMovement::Stop()
{
	trailRenderer->ShowTrail(false);
	currentMovementSpeed = baseMovementSpeed;
}

void KeyboardMovement::Reset()
{
	trailRenderer->ShowTrail(false);
	currentMovementSpeed = baseMovementSpeed;
}