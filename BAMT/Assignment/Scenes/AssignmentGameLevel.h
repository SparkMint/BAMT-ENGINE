#ifndef ASSIGNMENT_GAME_LEVEL
#define ASSIGNMENT_GAME_LEVEL

#include "StaticCollider.h"
#include "Scene.h"
#include "CoordinateGrid.h"
#include "TextRenderer.h"
#include "../Entities/Player.h"
#include "../Components/ScoreSystem.h"
#include "../Entities/Enemy.h"
#include "../Entities/GameManager.h"

class AssignmentGameLevel : public Scene
{
	public:
		inline static GameManager* gameManager = nullptr;

		Colour wallColour = { 100, 100, 100, 255 };
		void Start() override;
		void Update(float* timeStep) override;
};
#endif