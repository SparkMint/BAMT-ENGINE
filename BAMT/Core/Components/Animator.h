#ifndef BAMT_ANIMATOR
#define BAMT_ANIMATOR

#include "SpriteRenderer.h"

/// <summary>
/// Provides SpriteRenderer information about the animation they are playing.
/// </summary>
struct Animation
{
	Animation();
	Animation(const char* spriteSheetLocation, int width, int height, float animSpeed);
	~Animation();

	const char* spriteSheetFileName = nullptr;
	int spriteSheetWidth = 1;
	int spriteSheetHeight = 1;
	float animationSpeedSeconds = 1;
};

class Animator : public SpriteRenderer
{
	Animation* _animation = nullptr;
	SDL_Rect* _animationRect = nullptr;

	float _time = 0;
	float _timeStep;

	int _w = 0;
	int _h = 0;

	public:
		Animator();
		Animator(Animation* animation);

		///<summary>
		/// Determines if the sprite should be animated.
		///</summary>
		bool animate = false;

		void SetAnimation(Animation* targetAnimation);

		void Start() override;
		void Update(float* timeStep) override;

		void Render(SDL_Renderer* renderer) override;
};
#endif