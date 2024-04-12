#include "LineRenderer.h"

void LineRenderer::Start()
{
	Renderer::Start();
}

void LineRenderer::Render(SDL_Renderer* renderer)
{
	// Set the colour of the line.
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);

	const Vector2 scaledPosition1 = { Position1.x * BAMT_WORLD_SCALE , Position1.y * BAMT_WORLD_SCALE };

	const Vector2 scaledPosition2 = { Position2.x * BAMT_WORLD_SCALE , Position2.y * BAMT_WORLD_SCALE };
	// Draw the line.
	SDL_RenderDrawLineF(renderer, scaledPosition1.x , scaledPosition1.y, scaledPosition2.x, scaledPosition2.y);
}