#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(float Width, float Height, const char* spriteLocation)
{
	width = Width;
	height = Height;
	sprite = spriteLocation;

	_rect = new SDL_Rect();
}

void SpriteRenderer::Update(float* timeStep)
{

}

void SpriteRenderer::Render(SDL_Renderer* renderer)
{
	if(_texture)
	{
		// Get the height and width of the glyphAtlas.
		// Was using this but keeping it incase i need it later on.
		int textureWidth, textureHeight;
		SDL_QueryTexture(_texture, nullptr, nullptr, &textureWidth, &textureHeight);

		_rect->w = (width * _transform->scale) * BAMT_WORLD_SCALE;
		_rect->h = (height * _transform->scale) * BAMT_WORLD_SCALE;

		_rect->x = roundf((_transform->GetX() * BAMT_WORLD_SCALE - _rect->w * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;
		_rect->y = roundf((_transform->GetY() * BAMT_WORLD_SCALE - _rect->h * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;

		SDL_SetTextureColorMod(_texture, colour.r, colour.g, colour.b);

		// Display the Sprite.
		SDL_RenderCopy(renderer, _texture, nullptr, _rect);

		SDL_SetTextureColorMod(_texture, 255, 255, 255);

		//Debug::Log("SPRITE RENDERER VALUES");
		//Debug::Log("----------------------");
		//Debug::Log("Width: " + std::to_string(_rect->w));
		//Debug::Log("Height: " + std::to_string(_rect->h));
		//Debug::Log("X: " + std::to_string(_rect->x));
		//Debug::Log("Y: " + std::to_string(_rect->y));
	}
	else
	{
		SetSprite(sprite);
	}
}

void SpriteRenderer::SetSprite(const char* targetSprite)
{
	sprite = targetSprite;

	_texture = entity->scene->engine->assetWarehouse->GetTexture(targetSprite);

	if (_texture == nullptr)
	{
		std::string spriteName = sprite;
		Debug::LogError("SpriteRenderer could not load " + spriteName+ ". Setting it to default!", this);
		_texture = entity->scene->engine->assetWarehouse->GetTexture("default.png");
	}
}
