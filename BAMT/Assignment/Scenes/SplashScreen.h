#ifndef BAMT_SPLASH_SCREEN
#define BAMT_SPLASH_SCREEN

#include "../../Core/ECS/Scene.h"
#include "../../Core/EngineSettings.h"
#include "../../Core/Components/SpriteRenderer.h"
#include "../Entities/Player.h"
#include "../Entities/StaticCollider.h"

class SplashScreen : public Scene
{
	public:
		void Start() override;
		void Update(float* timeStep) override;
};

#endif