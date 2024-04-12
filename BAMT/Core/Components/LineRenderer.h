#ifndef BAMT_LINE_RENDERER
#define BAMT_LINE_RENDERER

#include "Renderer.h"
#include "../EngineSettings.h"

class LineRenderer : public Renderer
{
	public:
		Vector2 Position1{ 0,0 };
		Vector2 Position2{ 0,0 };

		void Start() override;
		void Render(SDL_Renderer* renderer) override;
};
#endif