#include "AssignmentGameLevel.h"

void AssignmentGameLevel::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	const float thickness = 5;
	const float offset = 1;

	// Left Wall
	auto* leftWall = AddEntity<StaticCollider>(thickness, height / 2);
	leftWall->GetComponent<Transform>()->SetPosition(-thickness / 2 + offset, height / 2);
	leftWall->GetComponent<RectRenderer>()->colour = wallColour;

	auto* leftWindow = AddEntity<StaticCollider>(thickness, height);

	leftWindow->GetComponent<Transform>()->SetPosition(-thickness / 2, height / 2);
	leftWindow->GetComponent<RectRenderer>()->colour = wallColour;

	// Top Wall
	auto* topWall = AddEntity<StaticCollider>(width, thickness);

	topWall->GetComponent<Transform>()->SetPosition(width / 2, -thickness / 2 + offset);
	topWall->GetComponent<RectRenderer>()->colour = wallColour;

	// Right Wall
	auto* rightWindow = AddEntity<StaticCollider>(thickness, height);

	rightWindow->GetComponent<Transform>()->SetPosition(width + thickness / 2 , height / 2);
	rightWindow->GetComponent<RectRenderer>()->colour = wallColour;

	// Right Wall
	auto* rightWall = AddEntity<StaticCollider>(thickness, height / 2);

	rightWall->GetComponent<Transform>()->SetPosition(width + thickness / 2 - offset, height / 2);
	rightWall->GetComponent<RectRenderer>()->colour = wallColour;

	// Bottom Wall
	auto* bottomWall = AddEntity<StaticCollider>(width, thickness);

	bottomWall->GetComponent<Transform>()->SetPosition(width / 2, height + thickness / 2 - offset);
	bottomWall->GetComponent<RectRenderer>()->colour = wallColour;

	gameManager = AddEntity<GameManager>();

	auto* gridEnt = AddEntity<CoordinateGrid>();
	gridEnt->renderLayer = -1;

	gameManager->spawnSystem->AddSpawnPoint({ 0, height / 4});
	gameManager->spawnSystem->AddSpawnPoint({width, height / 4});
	gameManager->spawnSystem->AddSpawnPoint({0, height - height / 4});
	gameManager->spawnSystem->AddSpawnPoint({ width, height - height / 4 });

	auto* backgroundEnt = AddEntity();
	backgroundEnt->renderLayer = -2;
	auto* backgroundRect = backgroundEnt->AddComponent<RectRenderer>(width, height, true);
	backgroundEnt->transform->SetPosition(width / 2, height / 2);
	backgroundRect->colour = { 20,20,20 };
}

void AssignmentGameLevel::Update(float* timeStep)
{
	Scene::Update(timeStep);
}