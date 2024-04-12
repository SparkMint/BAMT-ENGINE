#include "PlayerAnimationSystem.h"

void PlayerAnimationSystem::Start()
{
	animator = entity->GetComponent<Animator>();
	rigidBody = entity->GetComponent<RigidBody>();
	walkLeftAnim = new Animation("playerWalkLeft.png", 4, 1, .2f);
	walkRightAnim = new Animation("playerWalkRight.png", 4, 1, .2f);
	idleLeftAnim = new Animation("playerIdleLeft.png", 8, 1, .33f);
	idleRightAnim = new Animation("playerIdleRight.png", 8, 1, .33f);
}

void PlayerAnimationSystem::Update(float* timeStep)
{
	// Get the direction of the mouse on the screen.
	const Vector2 mousePos = Input::GetMousePosition();

	if (entity->transform->GetX() < mousePos.x)
	{
		VectorMath::Magnitude(rigidBody->velocity) > 0.5f ? animator->SetAnimation(walkRightAnim) : animator->SetAnimation(idleRightAnim);
	}
	else 
	{
		VectorMath::Magnitude(rigidBody->velocity) > 0.5f ? animator->SetAnimation(walkLeftAnim) : animator->SetAnimation(idleLeftAnim);
	}
}
