#ifndef ASSIGNMENT_PLAYER_WEAPON
#define ASSIGNMENT_PLAYER_WEAPON

#include "Weapon.h"
#include "../MouseAim.h"

class PlayerWeapon : public Weapon
{
	public:
		MouseAim* mouseAim = nullptr;
		WeaponData defaultWeapon = WEAPON_DATA_PISTOL;

		void Start() override;
		void Update(float* timeStep) override;
};
#endif