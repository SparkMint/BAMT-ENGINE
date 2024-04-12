#ifndef ASSIGNMENT_ENEMY_WEAPON
#define ASSIGNMENT_ENEMY_WEAPON
#include "Weapon.h"

class EnemyWeapon : public Weapon
{
	public:
		/// <summary>
		/// Who should we fire at?
		/// </summary>
		Entity* target = nullptr;

		void Update(float* timeStep) override;
};
#endif