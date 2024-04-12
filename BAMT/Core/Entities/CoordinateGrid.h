#ifndef BAMT_COORDINATE_GRID
#define BAMT_COORDINATE_GRID

#include "../ECS/Entity.h"
#include "../ECS/Scene.h"
#include "../Components/SpriteRenderer.h"

class CoordinateGrid : public Entity
{
	int width = 25;
	int height = 20;

	float gridSize = 1;

	public:
		void Start() override;
};
#endif
