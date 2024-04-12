#include "AssignmentGame.h"

void AssignmentGame::Start()
{
	// Set this scene to always be active.
	alwaysActive = true;

	// Create all the scenes that we will need for this game.
	_splashScreen = engine->AddScene<SplashScreen>();
	_menuScene = engine->AddScene<AssignmentMenu>();
	_gameScene = engine->AddScene<AssignmentGameLevel>();

	// Activate the splash screen upon startup.
	_splashScreen->active = true;

	AudioManager::SetVolume(0);

	auto* musicTest = AddEntity();
	auto* musicComponent = musicTest->AddComponent<MusicSource>();
	musicComponent->Play("lightnin.mp3");
}

void AssignmentGame::Update(float* timeStep)
{
	// If the splash screen is active, check if enough currentTimeSeconds has passed.
	if (_splashScreen->active)
	{
		// Skip the Splash Screen if the user presses space.
		if(Input::GetKeyDown(SDLK_SPACE)) splashScreenCurrentSeconds = splashScreenDisplaySeconds;

		if (splashScreenCurrentSeconds < splashScreenDisplaySeconds)
		{
			splashScreenCurrentSeconds += *timeStep;
		}
		else
		{
			// If it has, disable splash screen, enable menu.
			_splashScreen->active = false;
			_menuScene->active = true;
		}
	}
	Scene::Update(timeStep);
}