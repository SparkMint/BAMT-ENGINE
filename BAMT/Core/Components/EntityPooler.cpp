#include "EntityPooler.h"

void EntityPooler::AddEntityToPool(Entity* entityToAdd)
{
	entityPool.push_back(entityToAdd);
}

Entity* EntityPooler::GetAvaliableObject()
{
	for (const auto object : entityPool)
	{
		if(!object->active)	return object;
	}
	// If all objects in the pool are active, return nothing.
	return nullptr;
}

Entity* EntityPooler::GetRandomAvaliableObject(int attempts)
{
	for (int i = 0; i < attempts; ++i)
	{
		const int chosenObjectIndex = rand() % entityPool.size();

		if (!entityPool[chosenObjectIndex]->active)
		{
			return entityPool[chosenObjectIndex];
		}
	}
	// If we couldnt get a random one, just iterate through the list for any active one.
	return GetAvaliableObject();
}

std::vector<Entity*> EntityPooler::GetPoolVector()
{
	return entityPool;
}

void EntityPooler::DisableAllEntities() const
{
	for (const auto ent : entityPool)
	{
		ent->active = false;
	}
}
