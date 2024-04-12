#include "SplashScreen.h"

Entity* LogoEnt;
StaticCollider* Floor;
int bounces;

void SplashScreen::Start()
{
	Scene::Start();

	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	LogoEnt = AddEntity<Entity>();
	LogoEnt->GetComponent<Transform>()->SetPosition(width / 2, -5);

	LogoEnt->AddComponent<RigidBody>();
	LogoEnt->GetComponent<RigidBody>()->width = 1;
	LogoEnt->GetComponent<RigidBody>()->height = 1;
	LogoEnt->GetComponent<RigidBody>()->drag = 1;
	LogoEnt->GetComponent<RigidBody>()->bounciness = 1;

	LogoEnt->GetComponent<RigidBody>()->maxVelocity = 10;

	LogoEnt->AddComponent<SpriteRenderer>(5, 6, "BAMT Splash Logo.png");


	// Bottom Wall
	Floor = AddEntity<StaticCollider>();

	Floor->GetComponent<Transform>()->SetPosition(width / 2, height / 2);
	Floor->GetComponent<RigidBody>()->width = width;
	Floor->GetComponent<RigidBody>()->height = .5f;
	Floor->GetComponent<RigidBody>()->bounciness = 1;
	Floor->GetComponent<RectRenderer>()->enabled = false;

	gravity = { 0, 15 };
}

void SplashScreen::Update(float* timeStep)
{
	// Run base Update logic.
	Scene::Update(timeStep);

	if (!LogoEnt) return;

	if(!LogoEnt->GetComponent<RigidBody>()->collisionList.empty())
	{
		bounces++;
	}

	if (bounces >= 3) Floor->active = false;
}