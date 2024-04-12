#ifndef ASSIGNMENT_MENU_SCENE
#define ASSIGNMENT_MENU_SCENE

#include "Scene.h"
#include "Button.h"
#include "AssignmentGameLevel.h"
#include "../Components/MouseFollow.h"

class AssignmentMenu : public Scene
{
	float _gravSwitchTime = 0;
	bool negateGravity = false;
	
	Button* startButton = nullptr;

	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif