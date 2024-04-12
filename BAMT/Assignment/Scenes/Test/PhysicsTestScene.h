#ifndef BAMT_PHYSICS_TEST_SCENE
#define BAMT_PHYSICS_TEST_SCENE

#include "EngineSettings.h"
#include "Scene.h"
#include "CoordinateGrid.h"
#include "../../Entities/Player.h"
#include "StaticCollider.h"

class PhysicsTestScene : public Scene
{
	public:
		void Start() override;
};
#endif