#include "EnemyWeapon.h"

void EnemyWeapon::Update(float* timeStep)
{
	Weapon::Update(timeStep);

	if (!canFire || target == nullptr) return;

	Vector2 firingDirection = VectorMath::Normalize(*target->transform->GetPosition() - *entity->transform->GetPosition());
	Fire(firingDirection);
}