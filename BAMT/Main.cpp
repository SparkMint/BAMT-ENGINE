#include <SDL.h>

#include "Assignment/Scenes/AssignmentGame.h"
#include "Assignment/Scenes/Test/PhysicsTestScene.h"
#include "Core/EngineManager.h"
#include "Core/Misc/Debug.h"

EngineManager* engineManager;

int main(int argc, char* argv[])
{
	// Generate a random seed using the currentTimeSeconds for any random stuff.
	std::srand(std::time(nullptr));

	// Create and initialize our Engine.
	engineManager = new EngineManager();
	engineManager->Initialize(BAMT_WINDOW_NAME, BAMT_RESOLUTION_WIDTH, BAMT_RESOLUTION_HEIGHT, false, 1000/BAMT_TARGET_FRAME_RATE);

	// GAME PALLET GOES HERE
	auto* loadedGame = engineManager->AddScene<AssignmentGame>();
	loadedGame->alwaysActive = true;

	engineManager->RunLoop();
	return 0;
}