#include "Projectile.h"

void Projectile::Start()
{
	// Tell this object its tag is now a projectile.
	entity->tag = projectileTag;
	entity->renderLayer = 1;

	// Look for a RigidBody.
	rigidBody = entity->GetComponent<RigidBody>();

	if(rigidBody == nullptr)
	{
		rigidBody = entity->AddComponent<RigidBody>();
	}

	rigidBody->maxVelocity = 100;
	rigidBody->drag = 0;
	rigidBody->isTrigger = true;

	spriteRenderer = entity->GetComponent<SpriteRenderer>();

	if (spriteRenderer == nullptr)
	{
		spriteRenderer = entity->AddComponent<SpriteRenderer>();
	}

	audioSource = entity->AddComponent<AudioSource>();
}

void Projectile::Update(float* timeStep)
{
	if(time < projectileLifetime)
	{
		time += *timeStep;
	}
	else
	{
		time = 0;
		entity->active = false;
	}

	for (auto rb : rigidBody->collisionList)
	{
		// If we were fired by a player for example. Ignore the collision.
		if (rb == whoSpawnedMe || rb->entity->tag == entity->tag) continue;
		if (rb->entity->tag == "Item") continue;
		
		Vector2 dir = VectorMath::Normalize(*entity->transform->GetPosition() - previousPosition);

		
		rb->AddForce(dir, projectileKnockback);

		auto* health = rb->entity->GetComponent<Health>();

		// If an enemy hits another enemy, we dont want to damage them. only push them.
		if(health != nullptr && rb->entity->tag != whoSpawnedMe->entity->tag)
		{
			Debug::Log("Projectile Collided with a " + rb->entity->tag + "! Applying " + std::to_string(projectileDamage) + " damage!");
			health->RemoveHealth(projectileDamage);
		}
		time = 0;

		if(audioSource != nullptr && collisionSound != "") audioSource->Play(collisionSound);

		entity->active = false;
	}
	previousPosition = *entity->transform->GetPosition();
}