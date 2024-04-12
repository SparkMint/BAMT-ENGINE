#include "EnemyAnimationSystem.h"

void EnemyAnimationSystem::Start()
{
	animator = entity->GetComponent <Animator>();
	movementSystem = entity->GetComponent<EnemyMovement>();
}

void EnemyAnimationSystem::Update(float* timeStep)
{
	if (movementSystem == nullptr) return;
	const Vector2 targetPos = *movementSystem->target->transform->GetPosition();


	if (entity->transform->GetX() < targetPos.x)
	{
		animator->SetAnimation(walkRightAnim);
	}
	else
	{
		animator->SetAnimation(walkLeftAnim);
	}
}
