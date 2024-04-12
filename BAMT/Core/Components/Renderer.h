#ifndef BAMT_RENDERER
#define BAMT_RENDERER

#include "../ECS/Entity.h"
#include "../ECS/Component.h"
#include "Transform.h"
#include "../Misc/Colour.h"

class Renderer : public Component
{
	protected:
		///<summary>
		/// The Position of the object within the game world.
		///</summary>
		Transform* _transform = nullptr;

	public:
		Colour colour = BAMT_COLOUR_WHITE;

		void Start() override;
};
#endif