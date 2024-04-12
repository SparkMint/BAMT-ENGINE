#ifndef ASSIGNMENT_WEAPON
#define ASSIGNMENT_WEAPON

#include "AudioSource.h"
#include "WeaponData.h"
#include "Transform.h"
#include "Component.h"
#include "EntityPooler.h"
#include "../Projectile.h"

class Weapon : public Component
{
	protected:
		float time = 0;
		bool canFire = false;

	public:
		WeaponData* weaponData = nullptr;
		AudioSource* audioSource = nullptr;

		EntityPooler* entityPool = nullptr;
		int maxProjectiles = 10;

		void Start() override;
		void Update(float* timeStep) override;


		/// <summary>
		/// Creates projectiles for the entityPool to hold.
		/// </summary>
		void Init();

		void Fire(Vector2& directionToFire);
};
#endif