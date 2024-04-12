#ifndef BAMT_SCENE
#define BAMT_SCENE

#include "Entity.h"
#include <algorithm>

#include "../Components/RigidBody.h"
#include "../Components/Transform.h"

class EngineManager;
class RigidBody;

class Scene
{
	float _timeStep;
	public:
		EngineManager* engine = nullptr;

		std::vector<Entity*> entityList;

		std::vector<RigidBody*> rigidBodiesList;
		Vector2 gravity {0,0};

		// Determines if scene logic should run.
		bool active = false;

		// If set to true, this scene will always run no matter what.
		bool alwaysActive = false;

		/// <summary>
		/// Called upon the creation of a scene.
		/// </summary>
		virtual void Start();

		/// <summary>
		/// Updates all active Entities.
		/// </summary>
		virtual void Update(float* timeStep);

		/// <summary>
		/// Renders all active Entities.
		/// </summary>
		virtual void Render(SDL_Renderer* renderer) const;

		/// ENTITY FACTORY DECLARATION

		/// <summary>
		/// Creates an Entity of the specified type and adds it to the Entity List.
		/// </summary>
		template<class T = Entity, typename... TArgs>
		T* AddEntity(TArgs&&... mArgs);

		/// <summary>
		/// Destroys a specified Entity and removes it from the Entity List.
		/// </summary>
		void RemoveEntity(Entity* ent);

		/// <summary>
		/// Sorts all entities in the scene for rendering purposes.
		/// </summary>
		void SortEntities();

		void SortRigidBodies();

		void DetectCollisions();

		void SolveRigidBodyCollisions(const std::vector<std::pair<RigidBody*, RigidBody*>>& collisionPairs) const;

		Scene();
		~Scene();
};

/// ENTITY FACTORY IMPLEMENTATION

template<class T, typename... TArgs>
inline T* Scene::AddEntity(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* ent = new T(std::forward<TArgs>(mArgs)...);
	std::string className = typeid(*ent).name();
	size_t startPos = className.find_last_of(" ") + 1;

	// Use Dynamic Casting to find if the type given is derived from Entity.
	Entity* entityBase = dynamic_cast<Entity*>(ent);
	if (entityBase != nullptr)
	{
		// Add the entity to our entity list.
		entityList.emplace_back(entityBase);
		entityBase->scene = this;
		entityBase->Start();

		//Debug::Log(className.substr(startPos) + " (Entity) was created.", ent);

		return ent;
	}

	// If it got here, the type we got wasn't an entity type.
	Debug::LogError(className.substr(startPos) + " (Entity) could not be created successfully. Not derived off Entity class.", ent);
	delete(ent);
	return nullptr;
}

inline void Scene::RemoveEntity(Entity* ent)
{
	auto entToRemove = remove(entityList.begin(), entityList.end(), ent);
	delete(ent);
}
#endif