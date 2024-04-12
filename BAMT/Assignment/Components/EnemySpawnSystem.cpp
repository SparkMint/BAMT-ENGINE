#include "EnemySpawnSystem.h"

void EnemySpawnSystem::Start()
{
	enemyPool = entity->AddComponent<EntityPooler>();

	for (int i = 0; i < maxZombieCount; ++i)
	{
		Animation* walkRight = new Animation("zombieWalkRight.png", 4, 1, .1f);
		Animation* walkLeft = new Animation("zombieWalkLeft.png", 4, 1, .1f);

		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->enemyData = ENEMY_ZOMBIE;
		enemy->weapon->maxProjectiles = 1;
		enemy->weapon->Init();

		enemy->animationSystem->walkLeftAnim = walkLeft;
		enemy->animationSystem->walkRightAnim = walkRight;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}

	for (int i = 0; i < maxRangerCount; ++i)
	{
		Animation* walkRight = new Animation("rangerWalkRight.png", 4, 1, .33f);
		Animation* walkLeft = new Animation("rangerWalkLeft.png", 4, 1, .33f);

		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->enemyData = ENEMY_RANGER;

		enemy->weapon->maxProjectiles = 3;
		enemy->weapon->Init();

		enemy->animationSystem->walkLeftAnim = walkLeft;
		enemy->animationSystem->walkRightAnim = walkRight;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}

	for (int i = 0; i < maxTankCount; ++i)
	{
		Animation* walkRight = new Animation("tankWalkRight.png", 4, 1, .33f);
		Animation* walkLeft = new Animation("tankWalkLeft.png", 4, 1, .33f);

		auto* enemy = entity->scene->AddEntity<Enemy>();
		enemy->enemyData = ENEMY_TANK;

		enemy->weapon->maxProjectiles = 3;
		enemy->weapon->Init();

		enemy->animationSystem->walkLeftAnim = walkLeft;
		enemy->animationSystem->walkRightAnim = walkRight;

		enemy->Init();
		enemyPool->AddEntityToPool(enemy);
		enemy->active = false;
	}
}

void EnemySpawnSystem::Update(float* timeStep)
{

	if (time < spawnSpeedSeconds)
	{
		time += *timeStep;
	}
	else
	{
		time = 0;
		SpawnEnemy();
	}
}

void EnemySpawnSystem::SetDefaultTarget(Entity* newTarget) const
{
	if (enemyPool == nullptr) return;

	for (Entity* entity : enemyPool->GetPoolVector())
	{
		auto enemy = dynamic_cast<Enemy*>(entity);

		if (enemy == nullptr) continue;
		enemy->UpdateTarget(newTarget);
	}
}

void EnemySpawnSystem::AddSpawnPoint(Vector2 newSpawnPoint)
{
	spawnPoints.push_back(newSpawnPoint);
}

void EnemySpawnSystem::Stop()
{
	for (auto enemyEnt : enemyPool->GetPoolVector())
	{
		const auto enemy = dynamic_cast<Enemy*>(enemyEnt);
		if (enemy == nullptr) return;
		enemy->Stop();
	}
	enabled = false;
}

void EnemySpawnSystem::Reset()
{
	for (auto enemyEnt : enemyPool->GetPoolVector())
	{
		const auto enemy = dynamic_cast<Enemy*>(enemyEnt);
		if (enemy == nullptr) return;
		enemy->Restart();
	}
	enabled = true;
}

void EnemySpawnSystem::SpawnEnemy() const
{
	if(spawnPoints.empty())
	{
		Debug::LogWarn("EnemySpawnSystem does not have any spawn points specified.");
		return;
	}

	Entity* enemyBase = enemyPool->GetRandomAvaliableObject();

	const auto enemy = dynamic_cast<Enemy*>(enemyBase);
	if (enemy == nullptr) return;
	enemy->Init();

	const int spawnPoint = rand() % spawnPoints.size();
	enemy->transform->SetPosition(&spawnPoints[spawnPoint]);
	enemy->active = true;
}
