#include "CoordinateGrid.h"

void CoordinateGrid::Start()
{
	const auto halfGridSize = gridSize / 2;
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			auto* gridSquare = scene->AddEntity<Entity>();
			gridSquare->GetComponent<Transform>()->SetPosition(halfGridSize + (i * gridSize), halfGridSize + (j * gridSize));
			gridSquare->AddComponent<SpriteRenderer>(gridSize, gridSize, "gridSquare.png");
			gridSquare->renderLayer = -1;
		}
	}
}