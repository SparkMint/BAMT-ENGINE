#include "RectRenderer.h"

RectRenderer::RectRenderer(float Width, float Height, bool Fill)
{
	width = Width;
	height = Height;
	fillRect = Fill;

	rect = new SDL_Rect();
}

void RectRenderer::Start()
{
	// Finds or creates Transform on this object.
	Renderer::Start();
}

void RectRenderer::Render(SDL_Renderer* renderer)
{
	rect->w = width * BAMT_WORLD_SCALE * _transform->scale;
	rect->h = height * BAMT_WORLD_SCALE * _transform->scale;

	rect->x = roundf((_transform->GetX() * BAMT_WORLD_SCALE - rect->w * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;
	rect->y = roundf((_transform->GetY() * BAMT_WORLD_SCALE - rect->h * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;

	if (fillRect)
	{
		// Fill the inside of the Rectangle.
		SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
		SDL_RenderFillRect(renderer, rect);
	}
	else
	{
		// Only draw the outline of our shape.
		SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
		SDL_RenderDrawRect(renderer, rect);
	}
}