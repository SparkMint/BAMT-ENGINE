#ifndef ASSIGNMENT_POWERUP
#define ASSIGNMENT_POWERUP

#include "Component.h"
#include "RigidBody.h"
#include "SpriteRenderer.h"
#include "PowerupReciever.h"
#include "AudioSource.h"

enum PowerupType {speed = 0, doublePoints = 1, shotgun = 2, rifle = 3};

class Powerup : public Component
{
	std::string powerupTag = "Item";

	float powerupWidth = .5f;
	float powerupHeight = .5f;

	public:
		PowerupType type = speed;

		RigidBody* rigidBody = nullptr;
		SpriteRenderer* spriteRenderer = nullptr;
		AudioSource* audioSource = nullptr;
		const char* collectionSound = "powerupCollect.wav";
		const char* spawnSound = "powerupSpawn.wav";

		void Start() override;
		void Update(float* timeStep) override;
		void UpdateType(PowerupType typeToUpdateTo);
};
#endif