#include "PlayerWeapon.h"


void PlayerWeapon::Start()
{
	Weapon::Start();

	weaponData = &defaultWeapon;
	mouseAim = entity->AddComponent<MouseAim>();
}

void PlayerWeapon::Update(float* timeStep)
{
	Weapon::Update(timeStep);

	if (Input::GetMouseButtonHold(SDL_BUTTON_LEFT) && canFire)
	{
		Vector2 firingDirection = VectorMath::Normalize(mouseAim->GetAimDirection(entity->transform->GetPosition()));
		Fire(firingDirection);
	}
}