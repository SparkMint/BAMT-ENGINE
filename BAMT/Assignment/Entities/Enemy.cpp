#include "Enemy.h"

#include "Animator.h"

void Enemy::Start()
{
	Entity::Start();
	renderLayer = 2;

	for (auto entity : scene->entityList)
	{
		auto* potentialScoreSystem = entity->GetComponent<ScoreSystem>();
		if (potentialScoreSystem != nullptr) scoreSystem = potentialScoreSystem;
	}
	if (scoreSystem == nullptr) Debug::LogWarn("No ScoreSystem was found in this scene!", this);

	// RigidBody Setup
	rigidBody = AddComponent<RigidBody>();

	// Player Movement Setup
	movement = AddComponent<EnemyMovement>();

	// Sprite Renderer Setup
	animator = AddComponent<Animator>();
	animationSystem = AddComponent<EnemyAnimationSystem>();

	// Weapon Setup
	weapon = AddComponent<EnemyWeapon>();

	health = AddComponent<EnemyHealth>(0);
}

void Enemy::Init()
{
	tag = enemyTag;

	rigidBody->width = enemyData.width;
	rigidBody->height = enemyData.height;
	rigidBody->mass = enemyData.weightData.mass;
	rigidBody->maxVelocity = enemyData.weightData.maxSpeed;
	rigidBody->drag = enemyData.weightData.drag;
	rigidBody->bounciness = enemyData.weightData.bounciness;
	rigidBody->velocity = VECTOR2_ZERO;

	animator->width = enemyData.width;
	animator->height = enemyData.height;

	animator->animate = true;

	movement->movementSpeed = enemyData.speed;

	health->SetHealth(enemyData.health);
	health->maxHealth = enemyData.health;
	health->painTime = 0;

	weapon->weaponData = &enemyData.weapon;
}

void Enemy::Update(float* timeStep)
{
	Entity::Update(timeStep);
}

void Enemy::UpdateTarget(Entity* newTarget)
{
	target = newTarget;

	movement->target = newTarget;
	weapon->target = newTarget;
}

void Enemy::Stop()
{
	weapon->entityPool->DisableAllEntities();
	health->DisablePowerup();

	active = false;
}

void Enemy::Restart()
{
	Init();
}