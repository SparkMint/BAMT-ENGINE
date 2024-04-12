#include "Entity.h"

Entity::Entity()
{
	active = true;
	transform = AddComponent<Transform>();
}

Entity::~Entity()
{
	// Clear all memory taken up by this entity.
	for (const Component* c : _components)
	{
		delete(c);
	}
	Debug::Log("Entity Destroyed.", this);
}

void Entity::Start() { }

void Entity::Update(float* timeStep)
{
	for (Component* c : _components)
	{
		if(c->enabled)
			c->Update(timeStep);
	}
}

void Entity::Render(SDL_Renderer* renderer) const
{
	for (Component* c : _components)
	{
		if (c->enabled)
			c->Render(renderer);
	}
}