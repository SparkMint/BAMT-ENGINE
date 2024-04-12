#include "Animator.h"

Animation::Animation()
{

}

Animation::Animation(const char* spriteSheetLocation, int width, int height, float animSpeed)
{
	spriteSheetFileName = spriteSheetLocation;
	spriteSheetWidth = width;
	spriteSheetHeight = height;
	animationSpeedSeconds = animSpeed;
}

Animation::~Animation()
{

}

Animator::Animator()
{
	_animationRect = new SDL_Rect();
	_rect = new SDL_Rect();
}

Animator::Animator(Animation* animation)
{
	_animationRect = new SDL_Rect();
	_rect = new SDL_Rect();

	SetAnimation(animation);
}

void Animator::SetAnimation(Animation* targetAnimation)
{
	if (_animation == targetAnimation) return;
	_animation = targetAnimation;
	_texture = entity->scene->engine->assetWarehouse->GetTexture(_animation->spriteSheetFileName);
	_w = 0;
	_h = 0;
}

void Animator::Start(){}

void Animator::Update(float* timeStep)
{
	_timeStep = *timeStep;
}

void Animator::Render(SDL_Renderer* renderer)
{
	if (_animation == nullptr || _texture == nullptr) return;

	if (animate)
	{
		_rect->w = (width * entity->transform->scale) * BAMT_WORLD_SCALE;
		_rect->h = (height * entity->transform->scale) * BAMT_WORLD_SCALE;

		_rect->x = roundf((entity->transform->GetX() * BAMT_WORLD_SCALE - _rect->w * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;
		_rect->y = roundf((entity->transform->GetY() * BAMT_WORLD_SCALE - _rect->h * 0.5f) * BAMT_WORLD_SCALE) / BAMT_WORLD_SCALE;

		if (_time > _animation->animationSpeedSeconds)
		{
			_time = 0;
			// Get the height and width of the glyphAtlas.

			int textureWidth, textureHeight;
			SDL_QueryTexture(_texture, nullptr, nullptr, &textureWidth, &textureHeight);
			// Get the width and height of the sprite from the spritesheet.
			_animationRect->w = textureWidth / _animation->spriteSheetWidth;
			_animationRect->h = textureHeight / _animation->spriteSheetHeight;

			_w++;
			if (_w > _animation->spriteSheetWidth - 1)
			{
				_w = 0;
				_h++;
			}
			if (_h > _animation->spriteSheetHeight - 1)
			{
				_w = 0;
				_h = 0;
			}
		}
		else _time += _timeStep;

		_animationRect->x = _w * _animationRect->w;
		_animationRect->y = _h * _animationRect->h;
	}
	SDL_SetTextureColorMod(_texture, colour.r, colour.g, colour.b);

	// Display the Sprite.
	SDL_RenderCopy(renderer, _texture, _animationRect, _rect);

	SDL_SetTextureColorMod(_texture, 255, 255, 255);
}