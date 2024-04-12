#include "TriRenderer.h"

TriRenderer::TriRenderer(int triSize)
{
	size = triSize;
}

void TriRenderer::Start()
{
}

void TriRenderer::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//point1 = transform->GetX(), transform->SetY() - size / 2;
	//point2 = transform->GetX() - size / 2, transform->SetY() + size / 2 ;
	//point3 = transform->GetX() + size / 2, transform->SetY() + size / 2 ;

	SDL_RenderDrawLine(renderer, (int)entity->transform->GetX(), (int)entity->transform->GetY() - size * 0.5f,
		(int)entity->transform->GetX() - size * 0.5f, (int)entity->transform->GetY() + size * 0.5f);

	SDL_RenderDrawLine(renderer, (int)entity->transform->GetX() - size / 2, (int)entity->transform - entity->transform->GetY() + size * 0.5f,
		(int)entity->transform->GetX() - entity->transform->GetX() + size * 0.5f, (int)entity->transform - entity->transform->GetY() + size * 0.5f);

	SDL_RenderDrawLine(renderer, (int)entity->transform->GetX(), (int)entity->transform->GetY() - size * 0.5f,
		(int)entity->transform->GetX() + size * 0.5f, (int)entity->transform->GetY() + size * 0.5f);
}
