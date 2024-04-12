#ifndef BAMT_TEXT_RENDERER
#define BAMT_TEXT_RENDERER

#include "Renderer.h"
#include "SDL_ttf.h"
#include "../EngineSettings.h"
#include "../EngineManager.h"
#include "../ECS/Scene.h"

class TextRenderer : public Renderer
{
	Font* font;
	SDL_Rect* _rect = nullptr;
	SDL_Texture* _texture = nullptr;

	public:
		TextRenderer();
		TextRenderer(const char* newFont);

		///<summary>
		/// Width of each text character when Rendered.
		///</summary>
		float width = 1;

		///<summary>
		/// Height of each text character when Rendered.
		///</summary>
		float height = 1;

		/// <summary>
		/// What will the text renderer display?
		/// </summary>
		std::string text;

		void Render(SDL_Renderer* renderer) override;
		void SetFont(const char* newFont);
		void SetText(const char* newText);
};
#endif