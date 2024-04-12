#ifndef ASSIGNMENT_POWERUP_RECIEVER
#define ASSIGNMENT_POWERUP_RECIEVER

#include "KeyboardMovement.h"
#include "Component.h"
#include "Powerup.h"
#include "ScoreSystem.h"
#include "WeaponSystem/PlayerWeapon.h"

enum PowerupType;

class PowerupReciever : public Component
{
	float speedTime = 0;
	float doublePointsTime = 0;
	float weaponTime = 0;

	float powerupEffectTime = 10;

	WeaponData shotgunData = WEAPON_DATA_SHOTGUN;
	WeaponData rifleData = WEAPON_DATA_RIFLE;

	public:
		KeyboardMovement* movementSystem = nullptr;
		ScoreSystem* scoreSystem = nullptr;
		PlayerWeapon* weapon = nullptr;

		void Start() override;
		void Update(float* timeStep) override;
		void ApplyPowerupEffects(PowerupType effect);
};
#endif