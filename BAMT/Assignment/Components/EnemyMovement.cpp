#include "EnemyMovement.h"

void EnemyMovement::Start()
{
	_rigidBody = entity->GetComponent<RigidBody>();

	if (_rigidBody == nullptr)
	{
		_rigidBody = entity->AddComponent<RigidBody>();
	}
}

void EnemyMovement::Update(float* timeStep)
{
	if (target == nullptr) return;

	Vector2 dir = VectorMath::Normalize(*target->transform->GetPosition() - *entity->transform->GetPosition());

	_rigidBody->AddForce(dir, movementSpeed * *timeStep);
}
