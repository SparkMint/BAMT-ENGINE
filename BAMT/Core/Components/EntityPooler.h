#ifndef ASSIGNMENT_OBJECT_POOLER
#define ASSIGNEMNT_OBJECT_POOLER

#include "Entity.h"
#include "Component.h"

class EntityPooler : public Component
{
	std::vector<Entity*> entityPool;

	public:
		void AddEntityToPool(Entity* entityToAdd);

		Entity* GetAvaliableObject();
		Entity* GetRandomAvaliableObject(int attempts = 5);
		std::vector<Entity*> GetPoolVector();
		void DisableAllEntities() const;
};
#endif
