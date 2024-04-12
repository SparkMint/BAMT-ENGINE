#include "Powerup.h"

void Powerup::Start()
{
	entity->tag = powerupTag;

	rigidBody = entity->AddComponent<RigidBody>();
	audioSource = entity->AddComponent<AudioSource>();

	rigidBody->isTrigger = true;
	rigidBody->drag = 0.5f;
	rigidBody->maxVelocity = 2;
	rigidBody->width = powerupWidth;
	rigidBody->height = powerupHeight;

	spriteRenderer = entity->AddComponent<SpriteRenderer>(powerupWidth, powerupHeight, "default.png");
}

void Powerup::Update(float* timeStep)
{
	for (auto rb : rigidBody->collisionList)
	{
		if(rb->entity->tag == "Enemy")
		{
			const Vector2 pushDir = *entity->transform->GetPosition() - *rb->entity->transform->GetPosition();

			rigidBody->AddForce(VectorMath::Normalize(pushDir), 1);
		}

		if (rb->entity->tag != "Player") continue;
		

		auto* reciever = rb->entity->GetComponent<PowerupReciever>();
		if (reciever != nullptr)
		{
			// We have been collected!
			reciever->ApplyPowerupEffects(type);
			audioSource->Play(collectionSound);
		}
		entity->active = false;
	}
}

void Powerup::UpdateType(PowerupType typeToUpdateTo)
{
	type = typeToUpdateTo;
	switch (type)
	{
		case speed:
			spriteRenderer->SetSprite("speedItem.png");
			return;
		case doublePoints:
			spriteRenderer->SetSprite("doublePointsItem.png");
			return;
		case shotgun:
			spriteRenderer->SetSprite("shotgunItem.png");
			return;
		case rifle:
			spriteRenderer->SetSprite("rifleItem.png");
	}
}