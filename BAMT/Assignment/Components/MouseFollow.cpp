#include "MouseFollow.h"

void MouseFollow::Start()
{
	_rb = entity->GetComponent <RigidBody>();
}

void MouseFollow::Update(float* timeStep)
{
	const Vector2 mouseDir = Input::GetMousePosition() - *entity->transform->GetPosition();

	_rb->AddForce(mouseDir, 1);
}