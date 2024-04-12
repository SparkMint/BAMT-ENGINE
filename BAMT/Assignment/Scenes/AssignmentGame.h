#ifndef ASSIGNMENT_SCENEMANAGER
#define ASSIGNMENT_SCENEMANAGER

#include "AssignmentGameLevel.h"
#include "SplashScreen.h"
#include "Scene.h"
#include "AudioManager.h"
#include "MusicSource.h"
#include "AssignmentMenu.h"

class AssignmentGame : public Scene
{
	// Splash Screen Stuff.
	SplashScreen* _splashScreen = nullptr;
	float splashScreenDisplaySeconds = 5;
	float splashScreenCurrentSeconds = 0;

	AssignmentMenu* _menuScene = nullptr;
	AssignmentGameLevel* _gameScene = nullptr;


	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif