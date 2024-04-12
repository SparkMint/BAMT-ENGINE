#include "Health.h"

#include "Animator.h"
#include "Entity.h"

Health::Health(int health) { maxHealth = health; }

void Health::Start() { currentHealth = maxHealth; }

void Health::Update(float* timeStep)
{
	if (painTime > 0)
	{
		painTime -= *timeStep;
		entity->GetComponent<Animator>()->colour = BAMT_COLOUR_RED;
	}
	else
	{
		entity->GetComponent<Animator>()->colour = BAMT_COLOUR_WHITE;
	}
}

int Health::GetHealth() const { return currentHealth; }

void Health::SetHealth(int health) { currentHealth = health; }

void Health::RemoveHealth(int healthToRemove)
{
	currentHealth -= healthToRemove;
	painTime = .2f; 

	if(currentHealth <= 0)
	{
		currentHealth = 0;
		OnDead();
	}
}