#include "Component.h"

Component::Component()
{

}

Component::~Component()
{
	Debug::Log("Component Deleted.", this);
}

void Component::Start()
{
	if (!entity)
	{
		Debug::LogError("This component does not have an entity. Disabling.", this);
		enabled = false;
	}
}
void Component::Update(float* timeStep)
{
	if (!entity)
	{
		Debug::LogError("This component does not have an entity. Disabling.", this);
		enabled = false;
	}
}
void Component::Render(SDL_Renderer* renderer) {}
