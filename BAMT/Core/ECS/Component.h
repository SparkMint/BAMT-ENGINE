#ifndef BAMT_COMPONENT
#define BAMT_COMPONENT

#include <SDL_render.h>
#include "../Misc/Debug.h"

class Entity;
class Transform;

class Component 
{
	public:
		Component();
		virtual ~Component();
		/// <summary>
		/// The entity we are attached to.
		/// </summary>
		Entity* entity = nullptr;

		/// <summary>
		/// Should this component run its logic?
		/// </summary>
		bool enabled = true;

		/// <summary>
		/// Called when this instance is loaded.
		/// </summary>
		virtual void Start();

		/// <summary>
		/// Called every tick.
		/// </summary>
		virtual void Update(float* timeStep);

		/// <summary>
		/// Used for rendering.
		/// </summary>
		virtual void Render(SDL_Renderer* renderer);
};
#endif