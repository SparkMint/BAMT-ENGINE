#include "StaticCollider.h"

StaticCollider::StaticCollider()
{
}

StaticCollider::StaticCollider(float w, float h)
{
	width = w;
	height = h;
}

void StaticCollider::Start()
{
	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();
	rigidBody->isKinematic = true;
	rigidBody->bounciness = bounciness;

	// Renderer Setup
	rectRenderer = AddComponent<RectRenderer>(width, height, fillRect);
}

void StaticCollider::Update(float* timeStep)
{
	Entity::Update(timeStep);

	rigidBody->width = width;
	rigidBody->height = height;

	rectRenderer->width = width;
	rectRenderer->height = height;
}
