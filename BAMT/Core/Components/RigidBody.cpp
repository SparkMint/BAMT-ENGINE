#include "RigidBody.h"

RigidBody::~RigidBody()
{
	// Check if the entity is already a child of the new parent.
	auto iterator = std::find(entity->scene->rigidBodiesList.begin(), entity->scene->rigidBodiesList.end(), this);
	entity->scene->rigidBodiesList.erase(iterator);
}

void RigidBody::Start()
{
	transform = entity->GetComponent<Transform>();

	if (transform == nullptr)
	{
		Debug::LogWarn("Transform Component was not present on Entity with a RigidBody. Adding one now...");
		transform = entity->AddComponent<Transform>();
	}
	entity->scene->rigidBodiesList.push_back(this);
}

void RigidBody::Update(float* timeStep)
{
	if (isKinematic) return;
	_timeStep = *timeStep / BAMT_PHYSICS_STEPS;

	for (int i = 0; i < BAMT_PHYSICS_STEPS; ++i)
	{
		// Simulate the next position for our RigidBody.
		const Vector2 stepPosition = Simulate(&_timeStep, velocity, *transform->GetPosition());

		// Set the position of this object to where the resulting step was.
		transform->SetPosition(&stepPosition);
	}
}

Vector2 RigidBody::Simulate(const float* timeStep, Vector2 vel, Vector2 position)
{
	const float speed = VectorMath::Magnitude(vel);
	const Vector2 gravity = entity->scene->gravity;

	vel.x += gravity.x * *timeStep;
	vel.y += gravity.y * *timeStep;

	// If we are moving, apply drag to the body. 
	if (speed > 0) 
	{
		float dragForce = drag * speed;

		vel.x -= (vel.x / speed) * dragForce * *timeStep;
		vel.y -= (vel.y / speed) * dragForce * *timeStep;

		// Slow us down if we are going too fast.
		if (speed > maxVelocity)
		{
			vel.x = (vel.x / speed) * maxVelocity;
			vel.y = (vel.y / speed) * maxVelocity;
		}

		// Apply the newly made vel to the position we are going to return.
		position.x += vel.x * *timeStep;
		position.y += vel.y * *timeStep;
	}

	// Set the new vel to be the vel we calculated in here.
	velocity = vel;

	// Return the position
	return position;
}

void RigidBody::AddReactionForce(Vector2 direction, float force)
{
	// Use F = ma to get the acceleration force.
	// Acceleration = Force / Mass
	const float acceleration = force / mass;

	// We should assume that the direction we are given is already normalized.
	velocity.x += direction.x * acceleration * (_timeStep * BAMT_PHYSICS_STEPS);
	velocity.y += direction.y * acceleration * (_timeStep * BAMT_PHYSICS_STEPS);
}

void RigidBody::AddForce(Vector2 direction, float force)
{
	// Use F = ma to get the acceleration force.
	// Acceleration = Force / Mass
	const float acceleration = force / mass;

	// We should assume that the direction we are given is already normalized.
	velocity.x += direction.x * acceleration;
	velocity.y += direction.y * acceleration;
}