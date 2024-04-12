#ifndef BAMT_TRIANGLE_RENDERER
#define BAMT_TRIANGLE_RENDERER

#include "../ECS/Entity.h"
#include "../ECS/Component.h"
#include "SDL.h"
#include "Transform.h"
#include "../Misc/Debug.h"

class TriRenderer : public Component
{
	public:
		TriRenderer(int size = 0);

		/// <summary>
		/// Size of the Triangle.
		/// </summary>
		int size = 0;

		// Component overrides.
		void Start() override;
		void Render(SDL_Renderer* renderer) override;
};
#endif