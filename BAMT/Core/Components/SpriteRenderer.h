#ifndef BAMT_SPRITE_RENDERER
#define BAMT_SPRITE_RENDERER

#include "Renderer.h"
#include "SDL_image.h"
#include "EngineManager.h"
#include "Scene.h"
#include "../EngineSettings.h"

class SpriteRenderer : public Renderer
{
	private:
		///<summary>
		/// Location of the Sprite we want to render.
		///</summary>
		const char* sprite;

	protected:
		SDL_Texture* _texture = nullptr;
		SDL_Rect* _rect = nullptr;

	public:
		///<summary>
		/// Width of the sprite when rendered.
		///</summary>
		float width = 1;

		///<summary>
		/// Height of the sprite when Rendered.
		///</summary>
		float height = 1;

		/// <summary>
		/// Constructs a rectangle with specified inputs.
		/// </summary>
		/// <param name="Width">- The width of the Sprite.</param>
		/// <param name="Height">- The width of the Sprite.</param>
		/// <param name="projectileSprite">Location of the sprite we want to load.</param>
		SpriteRenderer(float Width = 0, float Height = 0, const char* spriteLocation = "");

		void Update(float* timeStep) override;
		void Render(SDL_Renderer* renderer) override;

		void SetSprite(const char* targetSprite);
};
#endif