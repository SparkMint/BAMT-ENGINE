#ifndef ASSIGNMENT_GAME_MANAGER
#define ASSIGNEMNT_GAME_MANAGER

#include "Entity.h"
#include "Player.h"
#include "../Components/ScoreSystem.h"
#include "../Components/TimeSystem.h"
#include "../Components/EnemySpawnSystem.h"
#include "../Components/UIManager.h"

class GameManager : public Entity
{
	public:
		UIManager* uiManager = nullptr;

		ScoreSystem* scoreSystem = nullptr;
		EnemySpawnSystem* spawnSystem = nullptr;
		TimeSystem* timeSystem = nullptr;

		Player* player = nullptr;

		void Start() override;
		void Update(float* timeStep) override;

		void EndGame();
		void RestartGame();
};
#endif