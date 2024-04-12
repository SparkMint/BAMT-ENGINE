#include "GameManager.h"


void GameManager::Start()
{
	uiManager = AddComponent<UIManager>();

	scoreSystem = AddComponent<ScoreSystem>();

	spawnSystem = AddComponent<EnemySpawnSystem>();

	timeSystem = AddComponent<TimeSystem>();


	player = scene->AddEntity<Player>();

	spawnSystem->SetDefaultTarget(player);
	uiManager->scoreSystem = scoreSystem;
	uiManager->timeSystem = timeSystem;
	uiManager->playerWeapon = player->weapon;
	uiManager->playerMovement = player->playerMovement;

	Entity::Start();
}

void GameManager::Update(float* timeStep)
{
	Entity::Update(timeStep);

	if(timeSystem->currentTimeSeconds < 0 && timeSystem->currentTimeSeconds > -1)
	{
		EndGame();
		timeSystem->currentTimeSeconds = -1;
		Debug::Log("GAME OVER! End Score: " + std::to_string(scoreSystem->score));
	}

	if(Input::GetKeyDown(SDLK_r))
	{
		EndGame();
		RestartGame();
	}
}

void GameManager::EndGame()
{
	player->Stop();
	spawnSystem->Stop();
	timeSystem->Stop();
	uiManager->Stop();
}

void GameManager::RestartGame()
{

	player->Reset();

	spawnSystem->Reset();

	scoreSystem->Reset();

	timeSystem->Reset();

	uiManager->Reset();
}
