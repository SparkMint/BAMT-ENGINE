#include "Weapon.h"

#include "BamtMath.h"

void Weapon::Start()
{
	entityPool = entity->AddComponent<EntityPooler>();
	audioSource = entity->AddComponent<AudioSource>();
	
	WeaponData defaultData = WEAPON_DATA_PISTOL;
	weaponData = &defaultData;
}

void Weapon::Update(float* timeStep)
{
	if(time < weaponData->fireRate)
	{
		time += *timeStep;
		canFire = false;
	}
	else canFire = true;
}

void Weapon::Init()
{
	for (int i = 0; i < maxProjectiles; ++i)
	{
		auto* projectile = entity->scene->AddEntity();
		projectile->AddComponent<Projectile>();
		projectile->active = false;
		entityPool->AddEntityToPool(projectile);
	}
}

void Weapon::Fire(Vector2& directionToFire)
{
	time = 0;
	if(weaponData == nullptr)
	{
		Debug::LogError("Weapon Data not found. Cannot fire!", this);
		return;
	}

	if(audioSource != nullptr)
	{
		if(weaponData->weaponFireSound != "")
		{
			audioSource->Play(weaponData->weaponFireSound.c_str());
		}
	}

	switch(weaponData->type)
	{
		case basic:
		{
			auto* projEnt = entityPool->GetAvaliableObject();

			if (projEnt == nullptr) return;

			auto* projComponent = projEnt->GetComponent<Projectile>();

			if (projComponent == nullptr) return;

			// Hard coded exception to the zombie weapon. Stops it from making collision sounds.
			// Jank. but eh.
			if(weaponData->weaponName == "BRAINS..")
			{
				projComponent->collisionSound = "";
			}
	
			projComponent->projectileDamage = weaponData->projectileDamage;
			projComponent->projectileKnockback = weaponData->projectileKnockback;
			projComponent->spriteRenderer->SetSprite(weaponData->projectileSprite.c_str());
			projComponent->whoSpawnedMe = entity->GetComponent<RigidBody>();

			projComponent->spriteRenderer->width = weaponData->projectileSize;
			projComponent->spriteRenderer->height = weaponData->projectileSize;

			projComponent->rigidBody->width = weaponData->projectileSize;
			projComponent->rigidBody->height = weaponData->projectileSize;
			projComponent->projectileLifetime = weaponData->projectileLifeTime;

			projComponent->rigidBody->velocity = VECTOR2_ZERO;
			projComponent->entity->transform->SetPosition(entity->transform->GetPosition());
			projComponent->entity->active = true;

			float angle = Math::RandomFloat(-weaponData->projectileSpread, weaponData->projectileSpread);
			Vector2 randomlyRotatedDir = VectorMath::Rotate(directionToFire, angle);

			projComponent->rigidBody->AddForce(randomlyRotatedDir, weaponData->projectileSpeed);
			break;
		}

		case explosive:
		{
			break;
		}

		case multiShot:
		{
			for (int i = 0; i < 8; ++i)
			{
				auto* projEnt = entityPool->GetAvaliableObject();

				if (projEnt == nullptr) return;

				auto* projComponent = projEnt->GetComponent<Projectile>();

				if (projComponent == nullptr) return;

				projComponent->projectileDamage = weaponData->projectileDamage;
				projComponent->projectileKnockback = weaponData->projectileKnockback;
				projComponent->spriteRenderer->SetSprite(weaponData->projectileSprite.c_str());
				projComponent->whoSpawnedMe = entity->GetComponent<RigidBody>();

				projComponent->spriteRenderer->width = weaponData->projectileSize;
				projComponent->spriteRenderer->height = weaponData->projectileSize;

				projComponent->rigidBody->width = weaponData->projectileSize;
				projComponent->rigidBody->height = weaponData->projectileSize;
				projComponent->projectileLifetime = weaponData->projectileLifeTime;

				projComponent->rigidBody->velocity = VECTOR2_ZERO;
				projComponent->entity->transform->SetPosition(entity->transform->GetPosition());
				projComponent->entity->active = true;

				float angle = Math::RandomFloat(-weaponData->projectileSpread, weaponData->projectileSpread);
				Vector2 randomlyRotatedDir = VectorMath::Rotate(directionToFire, angle);

				projComponent->rigidBody->AddForce(randomlyRotatedDir, weaponData->projectileSpeed);
			}
			break;
		}
	}
}
