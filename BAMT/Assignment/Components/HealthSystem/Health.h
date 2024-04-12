#ifndef ASSIGNMENT_HEALTH
#define ASSIGNMENT_HEALTH

#include "Component.h"

class Health : public Component
{
	int currentHealth = 0;


	public:
		Health(int health);

		void Start() override;
		void Update(float* timeStep) override;

		float painTime = 0;

		int maxHealth = 1;

		int GetHealth() const;
		void SetHealth(int health);
		virtual void RemoveHealth(int healthToRemove);

		virtual void OnDead() = 0;
};
#endif